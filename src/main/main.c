/**
 * @file   main.c
 * @brief  This file contains the entry point to the code and performs specified
 * functionality.
 * @author Matthew C. Lindeman
 * @date   February 05, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "../file_preprocessing/include/file_preprocessing.h"
#include "../parser/include/yyerror.h"
#include "../tree/include/tree.h"
#include "../parser/punygram.h"

path_wrapper * g_path_wrapper = NULL;
extern token * yytoken;
extern int yyparse();

int main(int argc, char * argv[]) {
  g_path_wrapper = init_path_wrapper(argv[1]);
  yyin = fopen(g_path_wrapper->path_file, "r");
  printf("main: %d\n", yyparse());
  debug_tree(yylval.ast, 0);
  free_path_wrapper(g_path_wrapper);
  free_tree(yylval.ast);
  free_token(yytoken);
  fclose(yyin);
  yylex_destroy();
  // token_list * the_list = NULL;
  // int value = -2;
  // for(int i = 1; i < argc; i++) {
  //   the_list = init_token_list();
  //   g_path_wrapper = init_path_wrapper(argv[i]);
  //   yyin = fopen(g_path_wrapper->path_file, "r");
  //   if(!yyin) {
  //     fprintf(stderr, "File: ");
  //     fprintf(stderr, ERROR_COLOR);
  //     fprintf(stderr, BOLD_COLOR);
  //     fprintf(stderr, "%s", g_path_wrapper->path_file);
  //     fprintf(stderr, END_COLOR);
  //     fprintf(stderr, " Does not exist\nExiting\n");
  //     exit(1);
  //   }
  //   while(value != -1) {
  //     value = yylex();
  //     if(RESERVED_WORD_NOT_SUPPORTED(value))
  //       print_not_puny_supported_reserved_word(value, yylineno);
  //     if(OPERATOR_NOT_SUPPORTED(value))
  //       print_not_puny_supported_operator(value, yylineno);
  //     if(value == DEDENT) {
  //       if(indent_stack->ate_newline) {
  //         token * new_line_copy = deep_copy_token(yytoken);
  //         new_line_copy->category = NEWLINE;
  //         the_list = add_token(the_list, new_line_copy);
  //         indent_stack->ate_newline = 0;
  //       }
  //       while(dedent_qty > 0) {
  //         token * copy = deep_copy_token(yytoken);
  //         the_list = add_token(the_list, copy);
  //         dedent_qty--;
  //       }
  //       free_token(yytoken);
  //     } else if(!NO_TOK(value)) {
  //       the_list = add_token(the_list, yytoken);
  //     } else if(NO_TOK(value)) {
  //       free_token(yytoken);
  //     }
  //   }
  //   printf("Category%-9sText%-10sLineno%-2sIval/Dval/Sval\n", " ", " ", " ");
  //   for(int i = 0; i < 80; i++)
  //     printf("-");
  //   printf("\n");
  //   debug_token_list(the_list);
  //   free_token_list(the_list);
  //   fclose(yyin);
  //   free_path_wrapper(g_path_wrapper);
  //   value = -2;
  //   yylineno = 1;
  //   if(indent_stack)
  //     while(INT_CAST(indent_stack->value)) indent_stack = pop(indent_stack);
  // }
  // free_current_stack(indent_stack);
  // yylex_destroy();
  return 0;
}
