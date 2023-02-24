/**
 * @file   constants_macros.h
 * @brief  This file contains the macros/constants used by the whole program.
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef CONST_H
#define CONST_H

#define MAX_LEXEME_SIZE 1024
#define MAX_PATH_SIZE   1024
#define TAB_MULTIPLE    8

#define IS_TAB_SPACE(c)   ((c == ' ')      \
                           || (c == '\t')) ? 1 : 0
#define IS_NEWLINE(c)     ((c == '\r')     \
                           || (c == '\n')) ? 1 : 0
#define IS_WHITESPACE(c)  ((c == '\r')     \
                           || (c == '\n')  \
                           || (c == ' ')   \
                           || (c == '\t')) ? 1 : 0
#define NOT_WHITESPACE(c) !IS_WHITESPACE(c) ? 1 : 0
#define PRINT_C_N(c, n) for(int zyx = 0; zyx < n; zyx++) printf("%s", c);

#define NAME_CAT             258
#define NUMBER_CAT           260
#define STRING_CAT           261
#define INDENT_CAT           263
#define DEDENT_CAT           264
#define VBAR_CAT             277
#define AMPER_CAT            278
#define TILDE_CAT            290
#define CIRCUMFLEX_CAT       291
#define LEFTSHIFT_CAT        292
#define RIGHTSHIFT_CAT       293
#define PLUSEQUAL_CAT        295
#define MINEQUAL_CAT         296
#define STAREQUAL_CAT        297
#define SLASHEQUAL_CAT       298
#define PERCENTEQUAL_CAT     299
#define AMPEREQUAL_CAT       300
#define VBAREQUAL_CAT        301
#define CIRCUMFLEXEQUAL_CAT  302
#define LEFTSHIFTEQUAL_CAT   303
#define RIGHTSHIFTEQUAL_CAT  304
#define DOUBLESTAREQUAL_CAT  305
#define DOUBLESLASHEQUAL_CAT 307
#define ATEQUAL_CAT          309
#define AWAIT_CAT            314
#define ASYNC_CAT            315
#define TYPE_CAT             316
#define POUND_TYPE_CAT       320
#define IN_CAT               343
#define IS_CAT               344

#define SPACE "  "
#define BOLD_COLOR  "\e[1m"
#define ERROR_COLOR "\033[97m"
#define END_COLOR   "\033[0m"

#endif
