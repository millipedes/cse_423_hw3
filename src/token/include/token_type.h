/**
 * @file   token_type.h
 * @brief  This file contains the token_type enum and the function defintions
 * for token_type.c
 * @author Matthew C. Lindeman
 * @date   January 27, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef TOKT_H
#define TOKT_H

#include <stdlib.h>

// typedef enum {
//   NAME = 257,
//   ENDMARKER,
//   NUMBER,
//   STRING,
//   NEWLINE,
//   INDENT,
//   DEDENT,
//   NODENT,
//   LPAR,
//   RPAR,
//   LSQB,
//   RSQB,
//   COLON,
//   COMMA,
//   SEMI,
//   PLUS,
//   MINUS,
//   STAR,
//   SLASH,
//   VBAR,
//   AMPER,
//   LESS,
//   GREATER,
//   EQUAL,
//   DOT,
//   PERCENT,
//   LBRACE,
//   RBRACE,
//   EQEQUAL,
//   NOTEQUAL,
//   LESSEQUAL,
//   GREATEREQUAL,
//   TILDE,
//   CIRCUMFLEX,
//   LEFTSHIFT,
//   RIGHTSHIFT,
//   DOUBLESTAR,
//   PLUSEQUAL,
//   MINEQUAL,
//   STAREQUAL,
//   SLASHEQUAL,
//   PERCENTEQUAL,
//   AMPEREQUAL,
//   VBAREQUAL,
//   CIRCUMFLEXEQUAL,
//   LEFTSHIFTEQUAL,
//   RIGHTSHIFTEQUAL,
//   DOUBLESTAREQUAL,
//   DOUBLESLASH,
//   DOUBLESLASHEQUAL,
//   AT,
//   ATEQUAL,
//   RARROW,
//   ELLIPSIS,
//   COLONEQUAL,
//   OP,
//   AWAIT,
//   ASYNC,
//   TYPE,
//   TYPE_IGNORE,
//   TYPE_COMMENT,
//   ERRORTOKEN,
//   POUND_TYPE,
//   COMMENT,
//   NL,
//   ENCODING,
//   FALSE,
//   NONE,
//   TRUE,
//   AND,
//   AS,
//   ASSERT,
//   BREAK,
//   CLASS,
//   CONTINUE,
//   DEF,
//   DEL,
//   ELIF,
//   ELSE,
//   EXCEPT,
//   FINALLY,
//   FOR,
//   FROM,
//   IF,
//   IMPORT,
//   IN,
//   IS,
//   LAMBDA,
//   NONLOCAL,
//   NOT,
//   OR,
//   GLOBAL,
//   RAISE,
//   RETURN,
//   TRY,
//   WHILE,
//   WITH,
//   YIELD,
//   PASS,
// } token_type;

const char * token_type_to_string(int type);

#endif
