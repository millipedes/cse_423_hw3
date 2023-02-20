#ifndef TRE_H
#define TRE_H

#include "../../token/include/token.h"

typedef struct TREE_T {
  char * symbolname;
  struct TREE_T ** kids;
  token * leaf;
  int prodrule;
  int no_kids;
} tree;

tree * init_tree(token * leaf, int prodrule);
tree * add_child(tree * parent, tree * child);
void debug_tree(tree * the_tree, int index);
void free_tree(tree * the_tree);

#endif
