/**
 * @file   menus.c
 * @brief  This file contains the user facing menus that are printed on
 * error/warning.
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/menus.h"

/**
 * This function prints the error message for unsupported reserved words.
 * @param     rw - The reserved word which does not exist in puny.
 * @param lineno - The lineno where it occured.
 * @return N/a
 */
void print_not_puny_supported_reserved_word(int rw, int lineno) {
  fprintf(stderr, "[LEXER]: Error, reserved word: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", token_type_to_string(rw));
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` on line: %d not supported by puny!\nExiting\n", lineno);
  exit(1);
}

/**
 * This function prints the error message for unmatched quote.
 * @param literal - The full string where it occured.
 * @param  lineno - The lineno where it occured.
 * @return N/a
 */
void print_unmatched_quote(char * literal, int lineno) {
  fprintf(stderr, "[LEXER]: Unmatched quote: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", literal);
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` on line: %d\nExiting\n", lineno);
  exit(1);
}

/**
 * This function prints the error message for unsupported operator.
 * @param     rw - The operator type.
 * @param lineno - The lineno where it occured.
 * @return N/a
 */
void print_not_puny_supported_operator(int rw, int lineno) {
  fprintf(stderr, "[LEXER]: Error, operator: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", token_type_to_string(rw));
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` on line: %d not supported by puny!\nExiting\n", lineno);
  exit(1);
}

/**
 * This function prints the error message for an exponential notation without an
 * operand.
 * @param literal - The number.
 * @param  lineno - The lineno where it occured.
 * @return N/a
 */
void print_exp_error_message(char * literal, int lineno) {
  fprintf(stderr, "[LEXER]: Exponential has no operand: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", literal);
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` on line: %d\nExiting\n", lineno);
  exit(1);
}

/**
 * This function prints the error message for an unsupported escape character.
 * @param literal - The escape sequence.
 * @param  lineno - The lineno where it occured.
 * @return N/a
 */
void print_unsupported_escape(char * literal, int lineno) {
  fprintf(stderr, "[LEXER]: Escape Sequence unsupported: `");
  fprintf(stderr, ERROR_COLOR);
  fprintf(stderr, BOLD_COLOR);
  fprintf(stderr, "%s", literal);
  fprintf(stderr, END_COLOR);
  fprintf(stderr, "` on line: %d\nExiting\n", lineno);
  free(literal);
  exit(1);
}
