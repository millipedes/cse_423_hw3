%option noinput nounput noyywrap yylineno

%{
#include "../main/include/constants_macros.h"
#include "../token/include/token.h"
#include "../file_preprocessing/include/file_preprocessing.h"
#include "../parser/punygram.h"

extern path_wrapper * g_path_wrapper;
stack * indent_stack = NULL;
int dedent_qty = 0;
token * yytoken = NULL;
tree * head = NULL;

int allocate_tree(int category);
int allocate_tree_stack(int category, char * value);
int update_stack(char * value);
int count_whitespace(char * value);
%}
%%

'(\\.|''|[^'\n])*'     |
\"(\\.|\"\"|[^\"\n])*\"         { return allocate_tree(STRING); }

'(\\.|''|[^'\n])*[\n]     |
\"(\\.|\"\"|[^\"\n])*[\n]       { print_unmatched_quote(yytext, yylineno); }

<<EOF>>                         { return allocate_tree(ENDMARKER); }
^[ \t]+                         { 
                                  int value = allocate_tree_stack(NEWLINE, yytext);
                                  if(value != NODENT)
                                    return value;
                                  // int stack_result = update_stack(yytext);
                                  //   yytoken = init_token(stack_result, yytext,
                                  //   yylineno, g_path_wrapper->filename);
                                  // return stack_result;
                                }
\\[\n][ \t]*

[\n\v\f\r]/[^ \t\n\v\f\r]+      {
                                  int value = allocate_tree_stack(NEWLINE, yytext);
                                  if(value != NODENT)
                                    return value;
                                  // int stack_result = update_stack(yytext);
                                  //    yytoken = init_token(stack_result, yytext,
                                  //    yylineno, g_path_wrapper->filename);
                                  // return stack_result;
                                }
[\n\v\f\r]                      { return allocate_tree(NEWLINE); }

[ \t]

"#type"                         { return allocate_tree(POUND_TYPE); }
#.*                             { return allocate_tree(COMMENT); }
"await"                         { return allocate_tree(AWAIT); }
"async"                         { return allocate_tree(ASYNC); }
"type"                          { return allocate_tree(TYPE); }
"False"                         { return allocate_tree(FALSE); }
"None"                          { return allocate_tree(NONE); }
"True"                          { return allocate_tree(TRUE); }
"and"                           { return allocate_tree(AND); }
"as"                            { return allocate_tree(AS); }
"assert"                        { return allocate_tree(ASSERT); }
"break"                         { return allocate_tree(BREAK); }
"class"                         { return allocate_tree(CLASS); }
"continue"                      { return allocate_tree(CONTINUE); }
"print"                         { return allocate_tree(PRINT); }
"def"                           { return allocate_tree(DEF); }
"del"                           { return allocate_tree(DEL); }
"elif"                          { return allocate_tree(ELIF); }
"else"                          { return allocate_tree(ELSE); }
"except"                        { return allocate_tree(EXCEPT); }
"finally"                       { return allocate_tree(FINALLY); }
"for"                           { return allocate_tree(FOR); }
"from"                          { return allocate_tree(FROM); }
"if"                            { return allocate_tree(IF); }
"import"                        { return allocate_tree(IMPORT); }
"in"                            { return allocate_tree(IN); }
"is"                            { return allocate_tree(IS); }
"lambda"                        { return allocate_tree(LAMBDA); }
"nonlocal"                      { return allocate_tree(NONLOCAL); }
"not"                           { return allocate_tree(NOT); }
"or"                            { return allocate_tree(OR); }
"global"                        { return allocate_tree(GLOBAL); }
"raise"                         { return allocate_tree(RAISE); }
"return"                        { return allocate_tree(RETURN); }
"try"                           { return allocate_tree(TRY); }
"while"                         { return allocate_tree(WHILE); }
"with"                          { return allocate_tree(WITH); }
"yield"                         { return allocate_tree(YIELD); }
"pass"                          { return allocate_tree(PASS); }
[A-Za-z_][A-Za-z0-9_]*          { return allocate_tree(NAME); }

[0-9][0-9_]+                     |
[0-9][0-9_]+(e|E)[-+]?[0-9]*     |
[0-9][0-9_]*"."?                 |
[0-9][0-9_]*"."?(e|E)[-+]?[0-9]* |
"."[0-9]+                        |
"."[0-9]+(e|E)[-+]?[0-9]*        |
[0-9][0-9_]*"."[0-9]+            |
[0-9][0-9_]*"."[0-9]+(e|E)[-+]?[0-9]* { return allocate_tree(NUMBER); }

"("                             { return allocate_tree(LPAR); }
")"                             { return allocate_tree(RPAR); }
"["                             { return allocate_tree(LSQB); }
"]"                             { return allocate_tree(RSQB); }
":"                             { return allocate_tree(COLON); }
","                             { return allocate_tree(COMMA); }
";"                             { return allocate_tree(SEMI); }
"+"                             { return allocate_tree(PLUS); }
"-"                             { return allocate_tree(MINUS); }
"*"                             { return allocate_tree(STAR); }
"/"                             { return allocate_tree(SLASH); }
"|"                             { return allocate_tree(VBAR); }
"&"                             { return allocate_tree(AMPER); }
"<"                             { return allocate_tree(LESS); }
">"                             { return allocate_tree(GREATER); }
"="                             { return allocate_tree(EQUAL); }
"."                             { return allocate_tree(DOT); }
"%"                             { return allocate_tree(PERCENT); }
"{"                             { return allocate_tree(LBRACE); }
"}"                             { return allocate_tree(RBRACE); }
"=="                            { return allocate_tree(EQEQUAL); }
"!="                            { return allocate_tree(NOTEQUAL); }
"<="                            { return allocate_tree(LESSEQUAL); }
">="                            { return allocate_tree(GREATEREQUAL); }
"~"                             { return allocate_tree(TILDE); }
"^"                             { return allocate_tree(CIRCUMFLEX); }
"<<"                            { return allocate_tree(LEFTSHIFT); }
">>"                            { return allocate_tree(RIGHTSHIFT); }
"**"                            { return allocate_tree(DOUBLESTAR); }
"+="                            { return allocate_tree(PLUSEQUAL); }
"-="                            { return allocate_tree(MINEQUAL); }
"*="                            { return allocate_tree(STAREQUAL); }
"/="                            { return allocate_tree(SLASHEQUAL); }
"%="                            { return allocate_tree(PERCENTEQUAL); }
"&="                            { return allocate_tree(AMPEREQUAL); }
"|="                            { return allocate_tree(VBAREQUAL); }
"^="                            { return allocate_tree(CIRCUMFLEXEQUAL); }
"<<="                           { return allocate_tree(LEFTSHIFTEQUAL); }
">>="                           { return allocate_tree(RIGHTSHIFTEQUAL); }
"**="                           { return allocate_tree(DOUBLESTAREQUAL); }
"//"                            { return allocate_tree(DOUBLESLASH); }
"//="                           { return allocate_tree(DOUBLESLASHEQUAL); }
"@"                             { return allocate_tree(AT); }
"@="                            { return allocate_tree(ATEQUAL); }
"->"                            { return allocate_tree(RARROW); }
"..."                           { return allocate_tree(ELLIPSIS); }
":="                            { return allocate_tree(COLONEQUAL); }
%%

int allocate_tree(int category) {
  yytoken = init_token(category, yytext, yylineno, g_path_wrapper->filename);
  yylval.ast = init_tree(init_token(category, yytext, yylineno,
  g_path_wrapper->filename), category);
  return category;
}

int allocate_tree_stack(int category, char * value) {
  if(!indent_stack) {
    void * zero_value = calloc(1, sizeof(int));
    INT_CAST(zero_value) = 0;
    indent_stack = init_stack(zero_value);
  }

  if(IS_NEWLINE(value[0])) {
    while(INT_CAST(indent_stack->value)) {
      dedent_qty++;
      indent_stack = pop(indent_stack);
    }
    indent_stack->ate_newline = 1;
    return allocate_tree(NEWLINE);
  } else if(IS_TAB_SPACE(value[0])) {
    int stack_value = count_whitespace(value);
    if(stack_value > INT_CAST(indent_stack->value)) {
      void * p_stack_value = calloc(1, sizeof(int));
      INT_CAST(p_stack_value) = stack_value;
      indent_stack = push(indent_stack, p_stack_value);
      return allocate_tree(INDENT);
    } else if(stack_value < INT_CAST(indent_stack->value)) {
      while(stack_value < INT_CAST(indent_stack->value)) {
        dedent_qty++;
        indent_stack = pop(indent_stack);
      }
      return allocate_tree(DEDENT);
    } else {
      return allocate_tree(NODENT);
    }
  } else {
    fprintf(stderr, "[UPDATE_STACK]: Error\n");
    exit(1);
  }
}

/**
 * This function updates the indent_stack with the given spacing value.
 * @param value - The value of the spacing.
 * @return   .\ - The corresponding token_type of the in/dedentation
 */
int update_stack(char * value) {
  if(!indent_stack) {
    void * zero_value = calloc(1, sizeof(int));
    INT_CAST(zero_value) = 0;
    indent_stack = init_stack(zero_value);
  }

  if(IS_NEWLINE(value[0])) {
    while(INT_CAST(indent_stack->value)) {
      dedent_qty++;
      indent_stack = pop(indent_stack);
    }
    indent_stack->ate_newline = 1;
    return DEDENT;
  } else if(IS_TAB_SPACE(value[0])) {
    int stack_value = count_whitespace(value);
    if(stack_value > INT_CAST(indent_stack->value)) {
      void * p_stack_value = calloc(1, sizeof(int));
      INT_CAST(p_stack_value) = stack_value;
      indent_stack = push(indent_stack, p_stack_value);
      return INDENT;
    } else if(stack_value < INT_CAST(indent_stack->value)) {
      while(stack_value < INT_CAST(indent_stack->value)) {
        dedent_qty++;
        indent_stack = pop(indent_stack);
      }
      return DEDENT;
    } else {
      return NODENT;
    }
  } else {
    fprintf(stderr, "[UPDATE_STACK]: Error\n");
    exit(1);
  }
}

int count_whitespace(char * value) {
  int value_size = strnlen(value, MAX_LEXEME_SIZE);
  int index = 0;
  int whitespace_value = 0;
  struct { int value : 3; } current_group;
  current_group.value = indent_stack->current_tabstop->value;
  while(index < value_size) {
    if(value[index] == ' ') {
      whitespace_value++;
      current_group.value++;
    } else if(value[index] == '\t') {
      whitespace_value += (TAB_MULTIPLE - current_group.value);
    }
    index++;
  }
  return whitespace_value;
}
