#include "include/yyerror.h"

int yyerror(char * s) {
  fprintf(stderr, "%s\n", s);
  return 0;
}
