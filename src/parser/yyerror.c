#include "include/yyerror.h"

int yyerror(char * s) {
  fprintf(stderr, "%d: %s with ['%s']\n", yylineno, s, yytext);
  debug_token(yytoken, 0);
  return 0;
}
