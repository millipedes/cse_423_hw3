/**
 * @file   token.h
 * @brief  This file contains the function definitions and macros for token.c
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef TOK_H
#define TOK_H

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "token_type.h"
#include "../../main/include/constants_macros.h"
#include "../../menus/include/menus.h"

// Delimitir used for floating point numbers
#define FLOAT_DELIMITIR '.'
// (1/2) Delimitirs used for exponential
#define LEXP_DELIMITIR  'e'
// (2/2) Delimitirs used for exponential
#define UEXP_DELIMITIR  'E'

#define FLOAT_FLAG -2147483640

// Funcition is used for r = r * 10^x
#define EXP_OP(r, x) r *= pow(10, x)

// Updates the memory of a character pointer, st, to have size si
#define UPDATE_MEM_CHAR(st, si) if(!st) st = calloc(si, sizeof(char));    \
                                else st = realloc(st, si * sizeof(char));

// Is char c not a quote mark?
#define NOT_QUOTE(c) ((c != '\'') && (c != '\"')) ? 1 : 0
// Is char c not a newline?
#define NOT_NL(c) ((c != '\n') || (c != '\r')) ? 1 : 0

// Is the category x NAME?
#define IS_NAME_CATEGORY(x)   (x == NAME)   ? 1 : 0
// Is the category x STIRNG?
#define IS_STRING_CATEGORY(x) (x == STRING) ? 1 : 0
// Is the category x INDENT?
#define IS_INDENT_CATEGORY(x) (x == INDENT) ? 1 : 0
// Is the category x DEDENT?
#define IS_DEDENT_CATEGORY(x) (x == DEDENT) ? 1 : 0

typedef struct TOKEN_T {
  int category;
  char * text;
  int lineno;
  char * filename;
  int ival;
  double dval;
  char * sval;
  int float_flag;
} token;

token * init_token(int category, char * text, int lineno, char * filename);
int handle_int_expression(char * text, int lineno);
double handle_float_expression(char * text, int lineno);
char * handle_string_expansion(char * text, size_t text_len, int lineno);
void handle_unsupported_escape(char * text, int curr_index, int lineno);
token * deep_copy_token(token * original);
void debug_token(token * the_token);
void free_token(token * the_token);

#endif
