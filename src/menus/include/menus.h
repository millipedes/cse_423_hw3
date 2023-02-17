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
#include "../../token/include/token_type.h"
#include "../../main/include/constants_macros.h"

// Is type t a reserved word that is not supported?
#define RESERVED_WORD_NOT_SUPPORTED(t) ((t == IS)            \
                                        || (t == IN)         \
                                        || (t == POUND_TYPE) \
                                        || (t == TYPE)       \
                                        || (t == AWAIT)      \
                                        || (t == ASYNC))     ? 1 : 0

// Is the opperator not supported?
#define OPERATOR_NOT_SUPPORTED(t) ((t == TILDE)               \
                                   || (t == LEFTSHIFT)        \
                                   || (t == RIGHTSHIFT)       \
                                   || (t == AMPEREQUAL)       \
                                   || (t == VBAREQUAL)        \
                                   || (t == CIRCUMFLEXEQUAL)  \
                                   || (t == LEFTSHIFTEQUAL)   \
                                   || (t == RIGHTSHIFTEQUAL)  \
                                   || (t == AMPER)            \
                                   || (t == VBAR)             \
                                   || (t == CIRCUMFLEX)       \
                                   || (t == PLUSEQUAL)        \
                                   || (t == MINEQUAL)         \
                                   || (t == STAREQUAL)        \
                                   || (t == SLASHEQUAL)       \
                                   || (t == PERCENTEQUAL)     \
                                   || (t == DOUBLESLASHEQUAL) \
                                   || (t == ATEQUAL))         ? 1 : 0


void print_not_puny_supported_reserved_word(token_type rw, int lineno);
void print_unmatched_quote(char * literal, int lineno);
void print_not_puny_supported_operator(token_type rw, int lineno);
void print_exp_error_message(char * literal, int lineno);
void print_unsupported_escape(char * literal, int lineno);

#endif
