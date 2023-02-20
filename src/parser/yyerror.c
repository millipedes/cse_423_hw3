#include "include/yyerror.h"

int yyerror(char * s) {
  fprintf(stderr, "err: %s\n", s);
  return 0;
}
