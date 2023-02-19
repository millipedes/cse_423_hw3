#ifndef TRE_H
#define TRE_H

#include "../../token/include/token.h"

typedef struct TREE_T {
  char * symbolname;
  struct TREE_T ** kids;
  struct token * leaf;
  int prodrule;
  int no_kids;
} tree;

tree * init_tree(void);

#endif
