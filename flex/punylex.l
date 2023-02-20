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

int allocate_tree(int category);
int update_stack(char * value);
int count_whitespace(char * value);
%}
%%

'(\\.|''|[^'\n])*'     |
\"(\\.|\"\"|[^\"\n])*\"         { yytoken = init_token(STRING, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return STRING; }

'(\\.|''|[^'\n])*[\n]     |
\"(\\.|\"\"|[^\"\n])*[\n]       { print_unmatched_quote(yytext, yylineno); }

<<EOF>>                         {  return allocate_tree(ENDMARKER); }
^[ \t]+                      { int stack_result = update_stack(yytext);
                             yytoken = init_token(stack_result, yytext,
                               yylineno, g_path_wrapper->filename);
                             return stack_result; }
\\[\n][ \t]*

[\n\v\f\r]/[^ \t\n\v\f\r]+ { int stack_result = update_stack(yytext);
                             yytoken = init_token(stack_result, yytext,
                               yylineno, g_path_wrapper->filename);
                             return stack_result; }
[\n\v\f\r]                     { yytoken = init_token(NEWLINE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NEWLINE; }

[ \t]

"#type"                         { yytoken = init_token(POUND_TYPE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return POUND_TYPE; }
#.*                             { yytoken = init_token(COMMENT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return COMMENT; }


"await"                         { yytoken = init_token(AWAIT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AWAIT; }
"async"                         { yytoken = init_token(ASYNC, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ASYNC; }
"type"                         { yytoken = init_token(TYPE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return TYPE; }
"False"                         { yytoken = init_token(FALSE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return FALSE; }
"None"                          { yytoken = init_token(NONE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NONE; }
"True"                          { yytoken = init_token(TRUE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return TRUE; }
"and"                           { yytoken = init_token(AND, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AND; }
"as"                            { yytoken = init_token(AS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AS; }
"assert"                        { yytoken = init_token(ASSERT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ASSERT; }
"break"                         { yytoken = init_token(BREAK, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return BREAK; }
"class"                         { yytoken = init_token(CLASS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return CLASS; }
"continue"                      { yytoken = init_token(CONTINUE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return CONTINUE; }
"def"                           { yytoken = init_token(DEF, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DEF; }
"del"                           { yytoken = init_token(DEL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DEL; }
"elif"                          { yytoken = init_token(ELIF, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ELIF; }
"else"                          { yytoken = init_token(ELSE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ELSE; }
"except"                        { yytoken = init_token(EXCEPT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return EXCEPT; }
"finally"                       { yytoken = init_token(FINALLY, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return FINALLY; }
"for"                           { yytoken = init_token(FOR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return FOR; }
"from"                          { yytoken = init_token(FROM, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return FROM; }
"if"                            { yytoken = init_token(IF, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return IF; }
"import"                        { yytoken = init_token(IMPORT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return IMPORT; }
"in"                            { yytoken = init_token(IN, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return IN; }
"is"                            { yytoken = init_token(IS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return IS; }
"lambda"                        { yytoken = init_token(LAMBDA, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LAMBDA; }
"nonlocal"                      { yytoken = init_token(NONLOCAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NONLOCAL; }
"not"                           { yytoken = init_token(NOT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NOT; }
"or"                            { yytoken = init_token(OR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return OR; }
"global"                        { yytoken = init_token(GLOBAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return GLOBAL; }
"raise"                         { yytoken = init_token(RAISE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RAISE; }
"return"                        { yytoken = init_token(RETURN, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RETURN; }
"try"                           { yytoken = init_token(TRY, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return TRY; }
"while"                         { yytoken = init_token(WHILE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return WHILE; }
"with"                          { yytoken = init_token(WITH, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return WITH; }
"yield"                         { yytoken = init_token(YIELD, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return YIELD; }
"pass"                          { yytoken = init_token(PASS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return PASS; }
[A-Za-z_][A-Za-z0-9_]*           { yytoken = init_token(NAME, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NAME; }

[0-9][0-9_]+                     |
[0-9][0-9_]+(e|E)[-+]?[0-9]*     |
[0-9][0-9_]*"."?                 |
[0-9][0-9_]*"."?(e|E)[-+]?[0-9]* |
"."[0-9]+                        |
"."[0-9]+(e|E)[-+]?[0-9]*        |
[0-9][0-9_]*"."[0-9]+            |
[0-9][0-9_]*"."[0-9]+(e|E)[-+]?[0-9]* { yytoken = init_token(NUMBER, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NUMBER; }

"("                             {  yytoken = init_token(LPAR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LPAR; }
")"                             {  yytoken = init_token(RPAR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RPAR; }
"["                             {  yytoken = init_token(LSQB, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LSQB; }
"]"                             {  yytoken = init_token(RSQB, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RSQB; }
":"                             {  yytoken = init_token(COLON, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return COLON; }
","                             {  yytoken = init_token(COMMA, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return COMMA; }
";"                             {  yytoken = init_token(SEMI, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return SEMI; }
"+"                             {  yytoken = init_token(PLUS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return PLUS; }
"-"                             {  yytoken = init_token(MINUS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return MINUS; }
"*"                             {  yytoken = init_token(STAR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return STAR; }
"/"                             {  yytoken = init_token(SLASH, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return SLASH; }
"|"                             {  yytoken = init_token(VBAR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return VBAR; }
"&"                             {  yytoken = init_token(AMPER, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AMPER; }
"<"                             {  yytoken = init_token(LESS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LESS; }
">"                             {  yytoken = init_token(GREATER, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return GREATER; }
"="                             {  yytoken = init_token(EQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return EQUAL; }
"."                             {  yytoken = init_token(DOT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DOT; }
"%"                             {  yytoken = init_token(PERCENT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return PERCENT; }
"{"                             {  yytoken = init_token(LBRACE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LBRACE; }
"}"                             {  yytoken = init_token(RBRACE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RBRACE; }
"=="                            {  yytoken = init_token(EQEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return EQEQUAL; }
"!="                            {  yytoken = init_token(NOTEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return NOTEQUAL; }
"<="                            {  yytoken = init_token(LESSEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LESSEQUAL; }
">="                            {  yytoken = init_token(GREATEREQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return GREATEREQUAL; }
"~"                             {  yytoken = init_token(TILDE, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return TILDE; }
"^"                             {  yytoken = init_token(CIRCUMFLEX, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return CIRCUMFLEX; }
"<<"                            {  yytoken = init_token(LEFTSHIFT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LEFTSHIFT; }
">>"                            {  yytoken = init_token(RIGHTSHIFT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RIGHTSHIFT; }
"**"                            {  yytoken = init_token(DOUBLESTAR, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DOUBLESTAR; }
"+="                            {  yytoken = init_token(PLUSEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return PLUSEQUAL; }
"-="                            {  yytoken = init_token(MINEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return MINEQUAL; }
"*="                            {  yytoken = init_token(STAREQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return STAREQUAL; }
"/="                            {  yytoken = init_token(SLASHEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return SLASHEQUAL; }
"%="                            {  yytoken = init_token(PERCENTEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return PERCENTEQUAL; }
"&="                            {  yytoken = init_token(AMPEREQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AMPEREQUAL; }
"|="                            {  yytoken = init_token(VBAREQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return VBAREQUAL; }
"^="                            {  yytoken = init_token(CIRCUMFLEXEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return CIRCUMFLEXEQUAL; }
"<<="                           {  yytoken = init_token(LEFTSHIFTEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return LEFTSHIFTEQUAL; }
">>="                           {  yytoken = init_token(RIGHTSHIFTEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RIGHTSHIFTEQUAL; }
"**="                           {  yytoken = init_token(DOUBLESTAREQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DOUBLESTAREQUAL; }
"//"                            {  yytoken = init_token(DOUBLESLASH, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DOUBLESLASH; }
"//="                           {  yytoken = init_token(DOUBLESLASHEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return DOUBLESLASHEQUAL; }
"@"                             {  yytoken = init_token(AT, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return AT; }
"@="                            {  yytoken = init_token(ATEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ATEQUAL; }
"->"                            {  yytoken = init_token(RARROW, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return RARROW; }
"..."                           {  yytoken = init_token(ELLIPSIS, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return ELLIPSIS; }
":="                            {  yytoken = init_token(COLONEQUAL, yytext,
                                    yylineno, g_path_wrapper->filename);
                                  return COLONEQUAL; }
%%

int allocate_tree(int category) {
  yylval.ast = init_tree(init_token(category, yytext, yylineno,
  g_path_wrapper->filename), category);
  return category;
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
