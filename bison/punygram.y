%{
#include "../file_preprocessing/include/file_preprocessing.h"

extern int yylex();
extern int yyerror(char *);
extern path_wrapper * g_path_wrapper;
extern char * yytext;

const char * token_type_to_string(int type);
%}

%code requires {
  #include "../file_preprocessing/include/file_preprocessing.h"
  #include "../tree/include/tree.h"
}

%union {
  tree * ast;
}

%token <ast> AMPEREQUAL AMPERSAND AND AS ASSERT AT BAR BREAK
%token <ast> CIRCUMFLEX CIRCUMFLEXEQUAL CLASS COLON COMMA CONTINUE DEDENT
%token <ast> DEF DEL DOT DOUBLESLASH DOUBLESLASHEQUAL 
%token <ast> DOUBLESTAR DOUBLESTAREQUAL ELIF ELSE ENDMARKER EQEQUAL
%token <ast> EQUAL EXCEPT EXEC FINALLY FOR FROM GLOBAL GREATER GREATEREQUAL GRLT
%token <ast> IF IMPORT IN INDENT IS LEFTSHIFT LEFTSHIFTEQUAL LESS
%token <ast> LESSEQUAL LPAR MINUS MINEQUAL NEWLINE NOTEQUAL
%token <ast> OR PASS PERCENT PERCENTEQUAL PLUS PLUSEQUAL PRINT RAISE 
%token <ast> RBRACE RETURN RIGHTSHIFT RIGHTSHIFTEQUAL RPAR RSQB 
%token <ast> SEMI SLASH SLASHEQUAL STAR STAREQUAL
%token <ast> TRY VBAREQUAL WHILE WITH
%token <ast> LSQB LBRACE BACKQUOTE STRING LAMBDA YIELD NOT NUMBER NAME
%token <ast> TILDE NODENT VBAR AMPER ATEQUAL RARROW ELLIPSIS COLONEQUAL OP
%token <ast> AWAIT ASYNC TYPE TYPE_IGNORE TYPE_COMMENT ERRORTOKEN COMMENT
%token <ast> POUND_TYPE NL ENCODING NONE FALSE TRUE NONLOCAL

%type <ast> pick_PLUS_MINUS pick_multop pick_unop augassign star_trailer
%type <ast> print_stmt arith_expr term factor power atom opt_test opt_yield_test
%type <ast> star_EQUAL pick_yield_expr_testlist yield_expr testlist test
%type <ast> opt_test_2 plus_COMMA_test or_test opt_IF_ELSE lambdef
%type <ast> plus_STRING pick_yield_expr_testlist_comp and_test testlist_comp
%type <ast> not_test comparison expr xor_expr and_expr shift_expr
%type <ast> plus_stmt stmt expr_stmt simple_stmt compound_stmt small_stmt
%type <ast> if_stmt while_stmt for_stmt try_stmt with_stmt funcdef classdef
%type <ast> decorated decorators del_stmt pass_stmt flow_stmt import_stmt
%type <ast> global_stmt exec_stmt assert_stmt decorator break_stmt continue_stmt
%type <ast> return_stmt raise_stmt yield_stmt import_name import_from parameters
%type <ast> suite dotted_as_names dotted_name dotted_as_name start file_input
%type <ast> encoding_decl single_input star_NEWLINE_stmt pick_NEWLINE_stmt
%type <ast> opt_EQUAL_test star_COMMA_test

%%

start
	: file_input    { return ENDMARKER; }
	| encoding_decl { return ENDMARKER; }
	| single_input  { return ENDMARKER; }
	;

single_input
	: NEWLINE
	| stmt
	;

file_input
	: star_NEWLINE_stmt ENDMARKER
	;

pick_NEWLINE_stmt
	: NEWLINE
	| stmt
	;

star_NEWLINE_stmt
	: pick_NEWLINE_stmt star_NEWLINE_stmt
	| %empty
	;

decorator
	: AT dotted_name LPAR opt_arglist RPAR NEWLINE
	| AT dotted_name NEWLINE
	;

opt_arglist
	: arglist
	| %empty
	;

decorators
	: decorator decorators
	| decorator
	;

decorated
	: decorators classdef
	| decorators funcdef
	;

funcdef
	: DEF NAME parameters COLON suite {
                                      $1 = add_child($1, $2);
                                      $1 = add_child($1, $3);
                                      $1 = add_child($1, $4);
                                      $1 = add_child($1, $5);
                                    }
	;

parameters
	: LPAR varargslist RPAR
	| LPAR RPAR
	;

varargslist
	: star_fpdef_COMMA pick_STAR_DOUBLESTAR
	| fpdef opt_EQUAL_test star_COMMA_fpdef
	;

opt_EQUAL_test
	: EQUAL test {
                 $1 = add_child($1, $2);
                 $$ = $1;
               }
	| %empty
	;

star_fpdef_COMMA
	: fpdef opt_EQUAL_test COMMA star_fpdef_COMMA
	| %empty
	;

opt_DOUBLESTAR_NAME
	: COMMA DOUBLESTAR NAME
	| %empty
	;

pick_STAR_DOUBLESTAR
	: STAR NAME opt_DOUBLESTAR_NAME
	| DOUBLESTAR NAME
	;

fpdef
	: NAME
	| LPAR fplist RPAR
	;

fplist
	: fpdef star_fpdef_notest
	;

stmt
	: simple_stmt
	| compound_stmt
	;

simple_stmt
	: small_stmt small_stmt_STAR_OR_SEMI NEWLINE
	;

small_stmt
	: expr_stmt   { debug_tree($1, 0); return NEWLINE; }
	| print_stmt  { debug_tree($1, 0); return NEWLINE; }
	| del_stmt    { debug_tree($1, 0); return NEWLINE; }
	| pass_stmt   { debug_tree($1, 0); return NEWLINE; }
	| flow_stmt   { debug_tree($1, 0); return NEWLINE; }
	| import_stmt { debug_tree($1, 0); return NEWLINE; }
	| global_stmt { debug_tree($1, 0); return NEWLINE; }
	| exec_stmt   { debug_tree($1, 0); return NEWLINE; } 
	| assert_stmt { debug_tree($1, 0); return NEWLINE; }
	;

expr_stmt
	: testlist augassign pick_yield_expr_testlist
	| testlist star_EQUAL {
                          if($2) {
                            $1 = add_child($1, $2);
                            $$ = $1;
                          } else {
                            $$ = $1;
                          }
                        }
	;

pick_yield_expr_testlist
	: yield_expr 
	| testlist
	;

star_EQUAL
	: EQUAL pick_yield_expr_testlist star_EQUAL {
                                                if($3) {
                                                  $1 = add_child($1, $2);
                                                  $1 = add_child($1, $3);
                                                  $$ = $1;
                                                } else {
                                                  $1 = add_child($1, $2);
                                                  $$ = $1;
                                                }
                                              }
	| %empty                                    { $$ = NULL; }
	;

augassign
	: PLUSEQUAL		     { }
	| MINEQUAL		     { }
	| STAREQUAL		     { }
	| SLASHEQUAL		   { }
	| PERCENTEQUAL     { }
	| AMPEREQUAL		   { }
	| VBAREQUAL		     { }
	| CIRCUMFLEXEQUAL	 { }
	| LEFTSHIFTEQUAL	 { }
	| RIGHTSHIFTEQUAL	 { }
	| DOUBLESTAREQUAL	 { }
	| DOUBLESLASHEQUAL { }
	;

print_stmt
	: PRINT opt_test {
                     $1 = add_child($1, $2);
                     $$ = $1;
                   }
	| PRINT RIGHTSHIFT test opt_test_2
	;

opt_test
	: test star_COMMA_test
	| %empty { }
	;

opt_test_2
	: plus_COMMA_test
	| %empty { }
	;

del_stmt
	: DEL exprlist
	;

pass_stmt
	: PASS
	;

flow_stmt
	: break_stmt
	| continue_stmt
	| return_stmt
	| raise_stmt
	| yield_stmt
	;

break_stmt
	: BREAK
	;

continue_stmt
	: CONTINUE
	;

return_stmt
	: RETURN testlist
	| RETURN
	;

yield_stmt
	: yield_expr
	;

raise_stmt
	: RAISE test opt_test_3
	| RAISE
	;

opt_COMMA_test
	: COMMA test
	| %empty
	;

opt_test_3
	: COMMA test opt_COMMA_test
	| %empty
	;

import_stmt
	: import_name
	| import_from
	;

import_name
	: IMPORT dotted_as_names { $1 = add_child($1, $2); }
	;

import_from
	: FROM star_DOT dotted_name IMPORT pick_STAR_import
	| FROM plus_DOT IMPORT pick_STAR_import
	;

star_DOT
	: DOT star_DOT
	| %empty
	;

plus_DOT
	: DOT plus_DOT
	| DOT
	;

pick_STAR_import
	: STAR
	| LPAR import_as_names RPAR
	| import_as_names
	;

import_as_name
	: NAME AS NAME
	| NAME
	;

dotted_as_name
	: dotted_name AS NAME
	| dotted_name
	;

import_as_names
	: import_as_name star_COMMA_import_as_name
	;

dotted_as_names
	: dotted_as_name
	| dotted_as_names COMMA dotted_as_name
	;

dotted_name
	: NAME
	| dotted_name DOT NAME {
                           $1 = add_child($1, $2);
                           $1 = add_child($1, $3);
                           $$ = $1;
                         }
	;

global_stmt
	: global_stmt COMMA NAME
	| GLOBAL NAME
	;

exec_stmt
	: EXEC expr IN test opt_COMMA_test
	| EXEC expr
	;

assert_stmt
	: ASSERT test COMMA test
	| ASSERT test
	;

compound_stmt
	: if_stmt      { $$ = $1; }
	| while_stmt   { $$ = $1; }
	| for_stmt     { $$ = $1; }
	| try_stmt     { $$ = $1; }
	| with_stmt    { $$ = $1; }
	| funcdef      { $$ = $1; }
	| classdef     { $$ = $1; }
	| decorated    { $$ = $1; }
	;

if_stmt
	: IF test COLON suite star_ELIF ELSE COLON suite
	| IF test COLON suite star_ELIF
	;

star_ELIF
	: ELIF test COLON suite star_ELIF
	| %empty
	;

while_stmt
	: WHILE test COLON suite ELSE COLON suite
	| WHILE test COLON suite
	;

for_stmt
	: FOR exprlist IN testlist COLON suite ELSE COLON suite
	| FOR exprlist IN testlist COLON suite
	;

try_stmt
	: TRY COLON suite plus_except opt_ELSE opt_FINALLY
	| TRY COLON suite FINALLY COLON suite
	;

plus_except
	: except_clause COLON suite plus_except
	| except_clause COLON suite
	;

opt_ELSE
	: ELSE COLON suite
	| %empty
	;

opt_FINALLY
	: FINALLY COLON suite
	| %empty
	;

with_stmt
	: WITH with_item star_COMMA_with_item COLON suite
	;

star_COMMA_with_item
	: COMMA with_item star_COMMA_with_item
	| %empty
	;

with_item
	: test AS expr
	| test
	;

except_clause
	: EXCEPT test opt_AS_COMMA
	| EXCEPT
	;

pick_AS_COMMA
	: AS
	| COMMA
	;

opt_AS_COMMA
	: pick_AS_COMMA test
	| %empty
	;

suite
  : simple_stmt 
	| NEWLINE INDENT {
                     // TableManager::getInstance().incrScope();
                   } plus_stmt DEDENT
	;

plus_stmt
	: stmt plus_stmt {
                     // if($1 != NULL)
                     //       funcStmt->push_back($1);
                     //       else funcStmt->push_back(a);
                     //     }
                   }
	| stmt           { 
                     $$ = $1;
                     // funcStmt = new std::vector<Ast*>();
                     // if($1 != NULL)
                     // funcStmt->push_back($1);
                     // else funcStmt->push_back(a);
                   }
	;

testlist_safe
	: old_test plus_COMMA_old_test
	| old_test
	;

old_test
	: or_test
	| old_lambdef
	;

old_lambdef
	: LAMBDA varargslist COLON old_test
	| LAMBDA COLON old_test
	;

test
	: or_test opt_IF_ELSE
	| lambdef
	;

opt_IF_ELSE
	: IF or_test ELSE test
	| %empty { }
	;

or_test
	: and_test
	| or_test OR and_test
	;

and_test
	: not_test
	| and_test AND not_test
	;

not_test
	: NOT not_test
	| comparison
	;

comparison
	: expr
	| comparison comp_op expr
	;

comp_op
	: LESS
	| GREATER
	| EQEQUAL
	| GREATEREQUAL
	| LESSEQUAL
	| GRLT
	| NOTEQUAL
	| IN
	| NOT IN
	| IS
	| IS NOT
	;

expr
	: xor_expr
	| expr BAR xor_expr
	;

xor_expr
	: and_expr
	| xor_expr CIRCUMFLEX and_expr
	;

and_expr
	: shift_expr
	| and_expr AMPERSAND shift_expr
	;

shift_expr
	: arith_expr
	| shift_expr pick_LEFTSHIFT_RIGHTSHIFT arith_expr
	;

pick_LEFTSHIFT_RIGHTSHIFT
	: LEFTSHIFT
	| RIGHTSHIFT
	;

arith_expr
	: term
	| arith_expr pick_PLUS_MINUS term {
                                      $2 = add_child($2, $1);
                                      $2 = add_child($2, $3);
                                      $$ = $2;
                                    }
	;

pick_PLUS_MINUS
	: PLUS  {  $$ = $1; }
	| MINUS {  $$ = $1; }
	;

term
	: factor
	| term pick_multop factor
          {
            $2 = add_child($2, $1);
            $2 = add_child($2, $3);
            $$ = $2;
            // if($2 == '*') $$ = new MultNode($2,$1, $3);
            // if($2 == '/') $$ = new DivNode($2,$1, $3);
            // if($2 == '%') $$ = new ModNode($2,$1,$3);
            // if($2 == '!') $$ = new IntDivNode($2,$1, $3);
          }
	;

pick_multop
	: STAR        { $$ = $1; }
  | AT          { $$ = $1; }
	| SLASH       { $$ = $1; }
	| PERCENT     { $$ = $1; }
	| DOUBLESLASH { $$ = $1; }
	;

factor
	: pick_unop factor
          {
            $1 = add_child($1, $2);
            $$ = $1;
            // if(char($1) == '+') $$ = new UPlusNode('P', $2, NULL);
            // if(char($1) == '-') $$ = new UMinusNode('M', $2, NULL);
          }
	| power
	;

pick_unop
	: PLUS  { $$ = $1; }
	| MINUS { $$ = $1; }
	| TILDE { $$ = $1; }
	;

power
	: atom star_trailer DOUBLESTAR factor  { 
                                           $3 = add_child($3, $1);
                                           $3 = add_child($3, $4);
                                           $$ = $3;
                                         }
	| atom star_trailer
          {
            $$ = $1;
            // exit(1);
            // if($2 == 'c') {
            //   a = new CallNode('2', $1->getKey());
            //   $$ = new CallNode('2',($1)->getKey());
            //   if(TableManager::getInstance().getCurrScope() == 0)
            //   $$->eval();
            //   delete $$;
            // }
          } 
	;

star_trailer
	: trailer star_trailer {
                           // $$ = 'c';
                         }
	| %empty { }
	;

atom
	: LPAR opt_yield_test RPAR { $$ = $2; }
	| LSQB opt_listmaker RSQB
	| LBRACE opt_dictorsetmaker RBRACE
	| BACKQUOTE testlist1 BACKQUOTE
	| NAME   { $$ = $1; }
	| NUMBER { $$ = $1; }
  | TRUE   { $$ = $1; }
  | FALSE  { $$ = $1; }
	| plus_STRING { $$ = $1; }
	;

pick_yield_expr_testlist_comp
	: yield_expr
	| testlist_comp
	;

opt_yield_test
	: pick_yield_expr_testlist_comp
	| %empty { }
	;

opt_listmaker
	: listmaker
	| %empty
	;

opt_dictorsetmaker
	: dictorsetmaker
	| %empty
	;

plus_STRING
	: STRING plus_STRING
	| STRING { $$ = $1; }
	;

listmaker
	: test list_for
	| test star_COMMA_test
	;

testlist_comp
	: test comp_for
	| test star_COMMA_test
	;

lambdef
	: LAMBDA varargslist COLON test
	| LAMBDA COLON test
	;

trailer
	: LPAR opt_arglist RPAR
	| LSQB subscriptlist RSQB
	| DOT NAME
	;

subscriptlist
	: subscript star_COMMA_subscript
	;

subscript
	: DOT DOT DOT
	| test
	| opt_test_only COLON opt_test_only opt_sliceop
	;

opt_test_only
	: test
	| %empty
	;

opt_sliceop
	: sliceop
	| %empty
	;

sliceop
	: COLON test
	| COLON
	;

exprlist
	: expr star_COMMA_expr
	;

testlist
	: test star_COMMA_test
  ;

dictorsetmaker
	: test COLON test pick_comp_for
	| test pick_for_test
	;

pick_comp_for
	: comp_for
	| star_test_COLON_test
	;

pick_for_test
	: comp_for
	| star_COMMA_test
	;

classdef
	: CLASS NAME LPAR opt_testlist RPAR COLON suite
	| CLASS NAME COLON suite
	;

opt_testlist
	: testlist
	| %empty
	;

arglist
	: argument COMMA arglist
	| argument COMMA
	| argument
	| listarg COMMA arglist_postlist
	| listarg
	| dictarg
	;

argument
	: test opt_comp_for
	| test EQUAL test
	;

opt_comp_for
	: comp_for
	| %empty
	;

list_iter
	: list_for
	| list_if
	;

list_for
	: FOR exprlist IN testlist_safe list_iter
	| FOR exprlist IN testlist_safe
	;

list_if
	: IF old_test list_iter
	| IF old_test
	;

comp_iter
	: comp_for
	| comp_if
	;

comp_for
	: FOR exprlist IN or_test comp_iter
	| FOR exprlist IN or_test
	;

comp_if
	: IF old_test comp_iter
	| IF old_test
	;

testlist1
	: test
	| testlist1 COMMA test
	;

encoding_decl
	: NAME
	;

yield_expr
	: YIELD testlist
	| YIELD
	;

star_fpdef_notest
	: COMMA fpdef star_fpdef_notest
	| COMMA
	| %empty
	;

star_COMMA_expr
	: COMMA expr star_COMMA_expr
	| COMMA
	| %empty
	;

star_COMMA_fpdef
	: COMMA fpdef opt_EQUAL_test star_COMMA_fpdef
	| COMMA
	| %empty
	;

star_COMMA_test
	: COMMA test star_COMMA_test {
                                 if($3) {
                                   $1 = add_child($1, $2);
                                   $1 = add_child($1, $3);
                                   $$ = $1;
                                 } else {
                                   $1 = add_child($1, $2);
                                   $$ = $1;
                                 }
                               }
	| COMMA
	| %empty { $$ = NULL; }
	;

star_test_COLON_test
	: COMMA test COLON test star_test_COLON_test
	| COMMA
	| %empty
	;

star_COMMA_subscript
	: COMMA subscript star_COMMA_subscript
	| COMMA
	| %empty
	;

star_COMMA_import_as_name
	: COMMA import_as_name star_COMMA_import_as_name
	| COMMA
	| %empty
	;

plus_COMMA_test
	: COMMA test plus_COMMA_test
	| COMMA test COMMA
	| COMMA test
	;

plus_COMMA_old_test
	: COMMA old_test plus_COMMA_old_test
	| COMMA old_test COMMA
	| COMMA old_test
	;

dictarg
	: DOUBLESTAR test
	;

listarg
	: STAR test
	;

arglist_postlist
	: argument COMMA arglist_postlist
	| dictarg
	| argument
	;

small_stmt_STAR_OR_SEMI
	: SEMI small_stmt small_stmt_STAR_OR_SEMI
	| SEMI
	| %empty
	;

%%

const char * token_type_to_string(int type) {
  switch(type) {
    case ENDMARKER:        return "Endmarker";
    case NAME:             return "Name";
    case NUMBER:           return "Number";
    case STRING:           return "String";
    case NEWLINE:          return "Newline";
    case INDENT:           return "Indent";
    case DEDENT:           return "Dedent";
    case NODENT:           return "Nodent";
    case LPAR:             return "Lpar";
    case RPAR:             return "Rpar";
    case LSQB:             return "Lsqb";
    case RSQB:             return "Rsqb";
    case COLON:            return "Colon";
    case COMMA:            return "Comma";
    case SEMI:             return "Semi";
    case PLUS:             return "Plus";
    case MINUS:            return "Minus";
    case STAR:             return "Star";
    case SLASH:            return "Slash";
    case VBAR:             return "Vbar";
    case AMPER:            return "Amper";
    case LESS:             return "Less";
    case GREATER:          return "Greater";
    case EQUAL:            return "Equal";
    case DOT:              return "Dot";
    case PERCENT:          return "Percent";
    case LBRACE:           return "Lbrace";
    case RBRACE:           return "Rbrace";
    case EQEQUAL:          return "Eqequal";
    case NOTEQUAL:         return "Notequal";
    case LESSEQUAL:        return "Lessequal";
    case GREATEREQUAL:     return "Greaterequal";
    case TILDE:            return "Tilde";
    case CIRCUMFLEX:       return "Circumflex";
    case LEFTSHIFT:        return "Leftshift";
    case RIGHTSHIFT:       return "Rightshift";
    case DOUBLESTAR:       return "Doublestar";
    case PLUSEQUAL:        return "Plusequal";
    case MINEQUAL:         return "Minequal";
    case STAREQUAL:        return "Starequal";
    case SLASHEQUAL:       return "Slashequal";
    case PERCENTEQUAL:     return "Percentequal";
    case AMPEREQUAL:       return "Amperequal";
    case VBAREQUAL:        return "Vbarequal";
    case CIRCUMFLEXEQUAL:  return "Circumflexequal";
    case LEFTSHIFTEQUAL:   return "Leftshiftequal";
    case RIGHTSHIFTEQUAL:  return "Rightshiftequal";
    case DOUBLESTAREQUAL:  return "Doublestarequal";
    case DOUBLESLASH:      return "Doubleslash";
    case DOUBLESLASHEQUAL: return "Doubleslashequal";
    case AT:               return "At";
    case ATEQUAL:          return "Atequal";
    case RARROW:           return "Rarrow";
    case ELLIPSIS:         return "Ellipsis";
    case COLONEQUAL:       return "Colonequal";
    case OP:               return "Op";
    case AWAIT:            return "Await";
    case ASYNC:            return "Async";
    case TYPE:             return "type";
    case TYPE_IGNORE:      return "Type Ignore";
    case TYPE_COMMENT:     return "Type Comment";
    case ERRORTOKEN:       return "Errortoken";
    case COMMENT:          return "Comment";
    case POUND_TYPE:       return "#type";
    case NL:               return "Nl";
    case ENCODING:         return "Encoding";
    case FALSE:            return "False";
    case NONE:             return "None";
    case TRUE:             return "True";
    case AND:              return "And";
    case AS:               return "As";
    case ASSERT:           return "Assert";
    case BREAK:            return "Break";
    case CLASS:            return "Class";
    case CONTINUE:         return "Continue";
    case DEF:              return "Def";
    case PRINT:            return "print";
    case DEL:              return "Del";
    case ELIF:             return "Elif";
    case ELSE:             return "Else";
    case EXCEPT:           return "Except";
    case FINALLY:          return "Finally";
    case FOR:              return "For";
    case FROM:             return "From";
    case IF:               return "If";
    case IMPORT:           return "Import";
    case IN:               return "In";
    case IS:               return "Is";
    case LAMBDA:           return "Lambda";
    case NONLOCAL:         return "Nonlocal";
    case NOT:              return "Not";
    case OR:               return "Or";
    case GLOBAL:           return "Global";
    case RAISE:            return "Raise";
    case RETURN:           return "Return";
    case TRY:              return "Try";
    case WHILE:            return "While";
    case WITH:             return "With";
    case YIELD:            return "Yield";
    case PASS:             return "Pass";
  }
  return NULL;
}
