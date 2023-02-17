/**
 * @file   token.c
 * @brief  This file contains the functions related to the token data structure.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/token.h"

/**
 * This function initializes a token with the given parameters.
 * @param   category - This translates to the token_type of the token.
 * @param       text - The text literal of the token.
 * @param     lineno - The line number in which the token was found.
 * @param   filename - The file name where the token was found.
 * @return the_token - The token that was initialized.
 */
token * init_token(int category, char * text, int lineno, char * filename) {
  // For the '+ 1's below, it is for nul terminator ('\0')
  size_t text_len = strnlen(text, MAX_LEXEME_SIZE) + 1;
  size_t filename_len = strnlen(filename, MAX_LEXEME_SIZE) + 1;
  token * the_token = calloc(1, sizeof(struct TOKEN_T));
  if(text[0] != '\n') {
    the_token->text = calloc(text_len, sizeof(char));
    strncpy(the_token->text, text, text_len - 1);
  } else {
    the_token->text = calloc(text_len - 1, sizeof(char));
    strncpy(the_token->text, text + 1, text_len - 2);
  }
  the_token->filename = calloc(filename_len, sizeof(char));
  strncpy(the_token->filename, filename, filename_len - 1);
  the_token->lineno = lineno;
  the_token->ival = 0;
  the_token->dval = 0.0;
  the_token->float_flag = 0;
  the_token->sval = NULL;
  the_token->category = category;
  if(IS_STRING_CATEGORY(category))
    the_token->sval = handle_string_expansion(text, text_len, lineno);
  else if(!strchr(text, FLOAT_DELIMITIR)
      && the_token->category == NUMBER
      && handle_int_expression(text, lineno) != FLOAT_FLAG)
    the_token->ival = handle_int_expression(text, lineno);
  else if((strchr(text, FLOAT_DELIMITIR)
        || strchr(text, LEXP_DELIMITIR)
        || strchr(text, UEXP_DELIMITIR))
      && the_token->category == NUMBER) {
    the_token->dval = handle_float_expression(text, lineno);
    the_token->float_flag = 1;
  }
  return the_token;
}

/**
 * This function is used to process integer numbers.
 * @param    text - The text from which the integer number comes from.
 * @param  lineno - The lineno from which the integer comes from.
 * @return result - The floating point number in int format.
 */
int handle_int_expression(char * text, int lineno) {
  size_t text_len = strnlen(text, MAX_LEXEME_SIZE);
  size_t ival_len = 1;
  char * ival = NULL;
  int exp_val = 0;
  float result = 0;
  for(size_t i = 0; i < text_len; i++) {
    ival_len++;
    UPDATE_MEM_CHAR(ival, ival_len);
    while(text[i] == '_') i++;
    if(text[i] == LEXP_DELIMITIR || text[i] == UEXP_DELIMITIR) {
      if(!text[i + 1])
        print_exp_error_message(text, lineno);
      exp_val = atoi(text + i + 1);
      break;
    } else {
      strncat(ival, text + i, 1);
    }
  }
  if(exp_val) {
    result = atoi(ival);
    EXP_OP(result, exp_val);
  } else {
    result = atoi(ival);
  }
  free(ival);
  if(result < 1 && result > 0)
    return FLOAT_FLAG;
  else
    return (int)result;
}

/**
 * This function is used to process floating point numbers.
 * @param    text - The text from which the fpn comes from.
 * @param  lineno - The lineno from which the fpn comes from.
 * @return result - The floating point number in double format.
 */
double handle_float_expression(char * text, int lineno) {
  size_t text_len = strnlen(text, MAX_LEXEME_SIZE);
  size_t dval_len = 1;
  char * dval = NULL;
  for(size_t i = 0; i < text_len; i++) {
    if(text[i] == LEXP_DELIMITIR || text[i] == UEXP_DELIMITIR)
      if(!text[i + 1])
        print_exp_error_message(text, lineno);
    dval_len++;
    if(!dval)
      dval = calloc(dval_len, sizeof(char));
    else
      dval = realloc(dval, dval_len * sizeof(char));
    while(text[i] == '_') i++;
    strncat(dval, text + i, 1);
  }
  double result = atof(dval);
  free(dval);
  return result;
}

/**
 * This function handles the exapansion of strings for the sval member of a
 * token.
 * @param     text - The text literal of the sval.
 * @param text_len - The length of the text literal of the sval.
 * @return    sval - The sval with the characters replaced.
 */
char * handle_string_expansion(char * text, size_t text_len, int lineno) {
  size_t sval_len = 1;
  char * sval = NULL;
  for(size_t i = 0; i < text_len; i++) {
    // Note here that text_len != strnlen(text) rather strlen(text) + 1 hence -1
    if((i != 0 && (i != text_len - 2)) || NOT_QUOTE(text[i])) {
      sval_len++;
      UPDATE_MEM_CHAR(sval, sval_len);
      if(text[i] == '\\') {
        i++;
        switch(text[i]) {
          case 'n':  strncat(sval, "\n", 2); break;
          case 't':  strncat(sval, "\t", 2); break;
          case '\'': strncat(sval, "\'", 2); break;
          case '\"': strncat(sval, "\"", 2); break;
          case 'f':  strncat(sval, "\f", 2); break;
          case 'r':  strncat(sval, "\r", 2); break;
          case 'a':  strncat(sval, "\a", 2); break;
          case '0':  strncat(sval,  "0", 2); break;
          default:   handle_unsupported_escape(text, i, lineno);
        }
      } else
        strncat(sval, text + i, 1);
    }
  }
  return sval;
}

/**
 * This function is responsible for handling the error that arises from an
 * unsupported escape character.
 * @param       text - The literal text string from which the unsupported escape
 * char comes from.
 * @param curr_index - The curr_index index where the unsupported escape
 * character was found.
 * @param     lineno - The lineno where the unsupported escape character was
 * found.
 * @return       N/a
 */
void handle_unsupported_escape(char * text, int curr_index, int lineno) {
  int final_index = curr_index;
  while((!(IS_WHITESPACE(text[final_index])) && NOT_QUOTE(text[final_index])))
    final_index++;
  char * tmp = calloc(final_index - curr_index + 1, sizeof(char));
  strncpy(tmp, text + curr_index, final_index - curr_index);
  print_unsupported_escape(tmp, lineno);
}

/**
 * This function deep copies a particular token.
 * @param original - The original token which will be copied.
 * @return    copy - The deep copy.
 */
token * deep_copy_token(token * original) {
  token * copy = calloc(1, sizeof(struct TOKEN_T));
  // For the '+ 1's below, it is for nul terminator ('\0')
  size_t text_len = strnlen(original->text, MAX_LEXEME_SIZE) + 1;
  size_t filename_len = strnlen(original->filename, MAX_LEXEME_SIZE) + 1;
  if(original->text[0] != '\n') {
    copy->text = calloc(text_len, sizeof(char));
    strncpy(copy->text, original->text, text_len - 1);
  } else {
    copy->text = calloc(text_len - 1, sizeof(char));
    strncpy(copy->text, original->text + 1, text_len - 2);
  }
  copy->filename = calloc(filename_len, sizeof(char));
  strncpy(copy->filename, original->filename, filename_len - 1);
  copy->lineno = original->lineno;
  copy->ival = 0;
  copy->dval = 0.0;
  copy->sval = NULL;
  copy->category = original->category;
  if(IS_STRING_CATEGORY(original->category))
    copy->sval = handle_string_expansion(original->text, text_len,
        original->lineno);
  else if(!strchr(original->text, FLOAT_DELIMITIR)
      && copy->category == NUMBER
      && handle_int_expression(original->text, original->lineno) != FLOAT_FLAG)
    copy->ival = handle_int_expression(original->text, original->lineno);
  else if((strchr(original->text, FLOAT_DELIMITIR)
        || strchr(original->text, LEXP_DELIMITIR)
        || strchr(original->text, UEXP_DELIMITIR))
      && copy->category == NUMBER) {
    copy->dval = handle_float_expression(original->text, original->lineno);
    copy->float_flag = 1;
  }
  return copy;
}

/**
 * This function debugs a token.
 * @param the_token - The token that is debugged.
 * @return      N/a
 */
void debug_token(token * the_token) {
  printf("%-17s", token_type_to_string(the_token->category));
  printf("%-14s", the_token->text);
  printf("%-8d", the_token->lineno);
  printf("%-12s", the_token->filename);
  if(IS_STRING_CATEGORY(the_token->category))
    printf("%-12s", the_token->sval);
  else if(!the_token->float_flag && the_token->category == NUMBER)
    printf("%-8d", the_token->ival);
  else if(the_token->category == NUMBER)
    printf("%-8f", the_token->dval);
  printf("\n");
}

/**
 * This function fees a token.
 * @param the_token - The token that is feed.
 * @return      N/a
 */
void free_token(token * the_token) {
  if(the_token) {
    if(the_token->text)
      free(the_token->text);
    if(the_token->filename)
      free(the_token->filename);
    if(the_token->sval)
      free(the_token->sval);
    free(the_token);
    the_token = NULL;
  }
}
