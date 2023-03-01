#ifndef YYE_H
#define YYE_H

#include "../../token/include/token.h"
#include <stdio.h>

extern char * yytext;
extern int yylineno;
extern token * yytoken;

int yyerror(char * s);

#endif
