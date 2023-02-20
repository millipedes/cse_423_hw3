/**
 * @file   menus.h
 * @brief  This file contains the function definitions and macros for menus.c
 * @author Matthew C. Lindeman
 * @date   Junuary 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef MEN_H
#define MEN_H

#include <stdio.h>
#include <stdlib.h>
#include "../../main/include/constants_macros.h"

// Is type t a reserved word that is not supported?
#define RESERVED_WORD_NOT_SUPPORTED(t) ((t == IS_CAT)            \
                                        || (t == IN_CAT)         \
                                        || (t == POUND_TYPE_CAT) \
                                        || (t == TYPE_CAT)       \
                                        || (t == AWAIT_CAT)      \
                                        || (t == ASYNC_CAT))     ? 1 : 0

// Is the opperator not supported?
#define OPERATOR_NOT_SUPPORTED(t) ((t == TILDE_CAT)               \
                                   || (t == LEFTSHIFT_CAT)        \
                                   || (t == RIGHTSHIFT_CAT)       \
                                   || (t == AMPEREQUAL_CAT)       \
                                   || (t == VBAREQUAL_CAT)        \
                                   || (t == CIRCUMFLEXEQUAL_CAT)  \
                                   || (t == LEFTSHIFTEQUAL_CAT)   \
                                   || (t == RIGHTSHIFTEQUAL_CAT)  \
                                   || (t == AMPER_CAT)            \
                                   || (t == VBAR_CAT)             \
                                   || (t == CIRCUMFLEX_CAT)       \
                                   || (t == PLUSEQUAL_CAT)        \
                                   || (t == MINEQUAL_CAT)         \
                                   || (t == STAREQUAL_CAT)        \
                                   || (t == SLASHEQUAL_CAT)       \
                                   || (t == PERCENTEQUAL_CAT)     \
                                   || (t == DOUBLESLASHEQUAL_CAT) \
                                   || (t == ATEQUAL_CAT))         ? 1 : 0

extern const char * token_type_to_string(int type);


void print_not_puny_supported_reserved_word(int rw, int lineno);
void print_unmatched_quote(char * literal, int lineno);
void print_not_puny_supported_operator(int rw, int lineno);
void print_exp_error_message(char * literal, int lineno);
void print_unsupported_escape(char * literal, int lineno);

#endif
