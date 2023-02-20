#include "include/tree.h"

tree * init_tree(token * leaf, int prodrule) {
  tree * the_tree = calloc(1, sizeof(struct TREE_T));
  // size_t symbolname_len = strnlen(yytext, MAX_LEXEME_SIZE);
  // the_tree->symbolname = calloc(symbolname_len + 1, sizeof(char));
  // strncpy(the_tree->symbolname, yytext, MAX_LEXEME_SIZE);
  the_tree->symbolname = NULL;
  the_tree->leaf = leaf;
  the_tree->prodrule = prodrule;
  the_tree->kids = NULL;
  the_tree->no_kids = 0;
  return the_tree;
}

tree * add_child(tree * parent, tree * child) {
  if(parent->kids) {
    parent->no_kids++;
    parent->kids = realloc(parent->kids, parent->no_kids
        * sizeof(struct TREE_T *));
    parent->kids[parent->no_kids - 1] = child;
  } else {
    parent->kids = calloc(1, sizeof(struct TREE_T *));
    parent->kids[0] = child;
    parent->no_kids++;
  }
  return parent;
}

void debug_tree(tree * the_tree, int index) {
  if(the_tree) {
    PRINT_C_N(SPACE, index)
    printf("[TREE]\n");
    if(the_tree->symbolname) {
      PRINT_C_N(SPACE, index)
      printf("symbolname: `%s`\n", the_tree->symbolname);
    }
    if(the_tree->leaf) {
      PRINT_C_N(SPACE, index)
      debug_token(the_tree->leaf, index);
    }
    PRINT_C_N(SPACE, index)
    printf("no_kids: %d\n", the_tree->no_kids);
    if(the_tree->kids) {
      for(int i = 0; i < the_tree->no_kids; i++)
        debug_tree(the_tree->kids[i], index + 1);
    }
  }
}

void free_tree(tree * the_tree) {
  if(the_tree) {
    if(the_tree->kids) {
      for(int i = 0; i < the_tree->no_kids; i++)
        if(the_tree->kids[i])
          free_tree(the_tree->kids[i]);
      free(the_tree->kids);
    }
    if(the_tree->leaf)
      free_token(the_tree->leaf);
    if(the_tree->symbolname)
      free(the_tree->symbolname);
    free(the_tree);
  }
}
