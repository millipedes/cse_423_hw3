%{
/*
# Grammar for Python

# NOTE WELL: You should also follow all the steps listed at
# https://devguide.python.org/grammar/

# Start symbols for the grammar:
#       single_input is a single interactive statement;
#       file_input is a module or sequence of commands read from an input file;
#       eval_input is the input for the eval() functions.
#       func_type_input is a PEP 484 Python 2 function type comment
# NB: compound_stmt in single_input is followed by extra NEWLINE!
# NB: due to the way TYPE_COMMENT is tokenized it will always be followed
#     by a NEWLINE
*/
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

%token <ast> NAME
%token <ast> ENDMARKER
%token <ast> NUMBER
%token <ast> STRING
%token <ast> NEWLINE
%token <ast> INDENT
%token <ast> DEDENT
%token <ast> NODENT
%token <ast> LPAR
%token <ast> RPAR
%token <ast> LSQB
%token <ast> RSQB
%token <ast> COLON
%token <ast> COMMA
%token <ast> SEMI
%token <ast> PLUS
%token <ast> MINUS
%token <ast> STAR
%token <ast> SLASH
%token <ast> VBAR
%token <ast> AMPER
%token <ast> LESS
%token <ast> GREATER
%token <ast> EQUAL
%token <ast> DOT
%token <ast> PERCENT
%token <ast> LBRACE
%token <ast> RBRACE
%token <ast> EQEQUAL
%token <ast> NOTEQUAL
%token <ast> LESSEQUAL
%token <ast> GREATEREQUAL
%token <ast> TILDE
%token <ast> CIRCUMFLEX
%token <ast> LEFTSHIFT
%token <ast> RIGHTSHIFT
%token <ast> DOUBLESTAR
%token <ast> PLUSEQUAL
%token <ast> MINEQUAL
%token <ast> STAREQUAL
%token <ast> SLASHEQUAL
%token <ast> PERCENTEQUAL
%token <ast> AMPEREQUAL
%token <ast> VBAREQUAL
%token <ast> CIRCUMFLEXEQUAL
%token <ast> LEFTSHIFTEQUAL
%token <ast> RIGHTSHIFTEQUAL
%token <ast> DOUBLESTAREQUAL
%token <ast> DOUBLESLASH
%token <ast> DOUBLESLASHEQUAL
%token <ast> AT
%token <ast> ATEQUAL
%token <ast> RARROW
%token <ast> ELLIPSIS
%token <ast> COLONEQUAL
%token <ast> OP
%token <ast> AWAIT
%token <ast> ASYNC
%token <ast> TYPE
%token <ast> TYPE_IGNORE
%token <ast> TYPE_COMMENT
%token <ast> ERRORTOKEN
%token <ast> POUND_TYPE
%token <ast> COMMENT
%token <ast> NL
%token <ast> ENCODING
%token <ast> FALSE
%token <ast> NONE
%token <ast> TRUE
%token <ast> AND
%token <ast> AS
%token <ast> ASSERT
%token <ast> BREAK
%token <ast> CLASS
%token <ast> CONTINUE
%token <ast> DEF
%token <ast> DEL
%token <ast> ELIF
%token <ast> ELSE
%token <ast> EXCEPT
%token <ast> FINALLY
%token <ast> FOR
%token <ast> FROM
%token <ast> IF
%token <ast> IMPORT
%token <ast> IN
%token <ast> IS
%token <ast> LAMBDA
%token <ast> NONLOCAL
%token <ast> NOT
%token <ast> OR
%token <ast> GLOBAL
%token <ast> RAISE
%token <ast> RETURN
%token <ast> TRY
%token <ast> WHILE
%token <ast> WITH
%token <ast> YIELD
%token <ast> PASS

%type <ast> file_input arith_expr term factor atom

%%

file_input
  : arith_expr { debug_tree($$, 0); return ENDMARKER; }
  | ENDMARKER { return ENDMARKER; }
  ;

arith_expr
  : term
  | term PLUS term {
                     $2 = add_child($2, $1);
                     $2 = add_child($2, $3);
                     $$ = $2;
                   }
  ;

term
  : factor      { $$ = $1; }
  | factor AT factor {
                         $2 = add_child($2, $1);
                         $2 = add_child($2, $3);
                         $$ = $2;
                       }
  | factor STAR factor {
                         $2 = add_child($2, $1);
                         $2 = add_child($2, $3);
                         $$ = $2;
                       }
  | factor SLASH factor {
                         $2 = add_child($2, $1);
                         $2 = add_child($2, $3);
                         $$ = $2;
                        }
  ;

factor
  : PLUS factor { $$ = add_child($1, $2); }
  | atom { $$ = $1; }
  ;

atom
  : NUMBER { $$ = $1; }
  ;

%%
/*
file_input: (NEWLINE | stmt)* ENDMARKER
stmt: simple_stmt | compound_stmt
  simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE
    small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt | import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
      expr_stmt: testlist_star_expr (annassign | augassign (yield_expr|testlist) | [('=' (yield_expr|testlist_star_expr))+ [TYPE_COMMENT]] )
        yield_expr: 'yield' [yield_arg]
        testlist_star_expr: (test|star_expr) (',' (test|star_expr))* [',']
          star_expr: '*' expr
            expr: xor_expr ('|' xor_expr)*
              xor_expr: and_expr ('^' and_expr)*
                and_expr: shift_expr ('&' shift_expr)*
                  shift_expr: arith_expr (('<<'|'>>') arith_expr)*
                    arith_expr: term (('+'|'-') term)*
                      term: factor (('*'|'@'|'/'|'%'|'//') factor)*
                        factor: ('+'|'-'|'~') factor | power
                          power: atom_expr ['**' factor]
                            atom_expr: [AWAIT] atom trailer*
                              atom: ('(' [yield_expr|testlist_comp] ')' | '[' [testlist_comp] ']' | '{' [dictorsetmaker] '}' | NAME | NUMBER | STRING+ | '...' | 'None' | 'True' | 'False')
                                dictorsetmaker: ( ((test ':' test | '**' expr) (comp_for | (',' (test ':' test | '**' expr))* [','])) | ((test | star_expr) (comp_for | (',' (test | star_expr))* [','])) )
                                testlist_comp: (namedexpr_test|star_expr) ( comp_for | (',' (namedexpr_test|star_expr))* [','] )
                                  namedexpr_test: test [':=' test]
                                    test: or_test ['if' or_test 'else' test] | lambdef
                                      lambdef: 'lambda' [varargslist] ':' test
                                  comp_for: [ASYNC] sync_comp_for
                                    sync_comp_for: 'for' exprlist 'in' or_test [comp_iter]
                                      exprlist: (expr|star_expr) (',' (expr|star_expr))* [',']
                              trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME
                                subscriptlist: subscript (',' subscript)* [',']
                                  subscript: test | [test] ':' [test] [sliceop]
                                    sliceop: ':' [test]
        testlist: test (',' test)* [',']
        annassign: ':' test ['=' (yield_expr|testlist_star_expr)]
        augassign: ('+=' | '-=' | '*=' | '@=' | '/=' | '%=' | '&=' | '|=' | '^=' | '<<=' | '>>=' | '**=' | '//=')
        testlist: test (',' test)* [',']
*/

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

/*

##############
#  COMPLETE  #
##############

##############
#   PARTIAL  #
##############
file_input: (NEWLINE | stmt)* ENDMARKER
stmt: simple_stmt | compound_stmt
  simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE
    small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt | import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
      expr_stmt: testlist_star_expr (annassign | augassign (yield_expr|testlist) | [('=' (yield_expr|testlist_star_expr))+ [TYPE_COMMENT]] )
        yield_expr: 'yield' [yield_arg]
        testlist_star_expr: (test|star_expr) (',' (test|star_expr))* [',']
          star_expr: '*' expr
            expr: xor_expr ('|' xor_expr)*
              xor_expr: and_expr ('^' and_expr)*
                and_expr: shift_expr ('&' shift_expr)*
                  shift_expr: arith_expr (('<<'|'>>') arith_expr)*
                    arith_expr: term (('+'|'-') term)*
                      term: factor (('*'|'@'|'/'|'%'|'//') factor)*
                        factor: ('+'|'-'|'~') factor | power
                          power: atom_expr ['**' factor]
                            atom_expr: [AWAIT] atom trailer*
                              atom: ('(' [yield_expr|testlist_comp] ')' | '[' [testlist_comp] ']' | '{' [dictorsetmaker] '}' | NAME | NUMBER | STRING+ | '...' | 'None' | 'True' | 'False')
                                dictorsetmaker: ( ((test ':' test | '**' expr) (comp_for | (',' (test ':' test | '**' expr))* [','])) | ((test | star_expr) (comp_for | (',' (test | star_expr))* [','])) )
                                testlist_comp: (namedexpr_test|star_expr) ( comp_for | (',' (namedexpr_test|star_expr))* [','] )
                                  namedexpr_test: test [':=' test]
                                    test: or_test ['if' or_test 'else' test] | lambdef
                                      lambdef: 'lambda' [varargslist] ':' test
                                  comp_for: [ASYNC] sync_comp_for
                                    sync_comp_for: 'for' exprlist 'in' or_test [comp_iter]
                                      exprlist: (expr|star_expr) (',' (expr|star_expr))* [',']
                              trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME
                                subscriptlist: subscript (',' subscript)* [',']
                                  subscript: test | [test] ':' [test] [sliceop]
                                    sliceop: ':' [test]
        testlist: test (',' test)* [',']
        annassign: ':' test ['=' (yield_expr|testlist_star_expr)]
        augassign: ('+=' | '-=' | '*=' | '@=' | '/=' | '%=' | '&=' | '|=' | '^=' | '<<=' | '>>=' | '**=' | '//=')
        testlist: test (',' test)* [',']


##############
# INCOMPLETE #
##############

single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE
file_input: (NEWLINE | stmt)* ENDMARKER
eval_input: testlist NEWLINE* ENDMARKER

decorator: '@' namedexpr_test NEWLINE
decorators: decorator+
decorated: decorators (classdef | funcdef | async_funcdef)

async_funcdef: ASYNC funcdef
funcdef: 'def' NAME parameters ['->' test] ':' [TYPE_COMMENT] func_body_suite

parameters: '(' [typedargslist] ')'

# The following definition for typedarglist is equivalent to this set of rules:
#
#     arguments = argument (',' [TYPE_COMMENT] argument)*
#     argument = tfpdef ['=' test]
#     kwargs = '**' tfpdef [','] [TYPE_COMMENT]
#     args = '*' [tfpdef]
#     kwonly_kwargs = (',' [TYPE_COMMENT] argument)* (TYPE_COMMENT | [',' [TYPE_COMMENT] [kwargs]])
#     args_kwonly_kwargs = args kwonly_kwargs | kwargs
#     poskeyword_args_kwonly_kwargs = arguments ( TYPE_COMMENT | [',' [TYPE_COMMENT] [args_kwonly_kwargs]])
#     typedargslist_no_posonly  = poskeyword_args_kwonly_kwargs | args_kwonly_kwargs
#     typedarglist = (arguments ',' [TYPE_COMMENT] '/' [',' [[TYPE_COMMENT] typedargslist_no_posonly]])|(typedargslist_no_posonly)"
#
# It needs to be fully expanded to allow our LL(1) parser to work on it.

typedargslist: (
  (tfpdef ['=' test] (',' [TYPE_COMMENT] tfpdef ['=' test])* ',' [TYPE_COMMENT] '/' [',' [ [TYPE_COMMENT] tfpdef ['=' test] (
        ',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] [
        '*' [tfpdef] (',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] ['**' tfpdef [','] [TYPE_COMMENT]]])
      | '**' tfpdef [','] [TYPE_COMMENT]]])
  | '*' [tfpdef] (',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] ['**' tfpdef [','] [TYPE_COMMENT]]])
  | '**' tfpdef [','] [TYPE_COMMENT]]] )
|  (tfpdef ['=' test] (',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] [
   '*' [tfpdef] (',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] ['**' tfpdef [','] [TYPE_COMMENT]]])
  | '**' tfpdef [','] [TYPE_COMMENT]]])
  | '*' [tfpdef] (',' [TYPE_COMMENT] tfpdef ['=' test])* (TYPE_COMMENT | [',' [TYPE_COMMENT] ['**' tfpdef [','] [TYPE_COMMENT]]])
  | '**' tfpdef [','] [TYPE_COMMENT])
)
tfpdef: NAME [':' test]

# The following definition for varargslist is equivalent to this set of rules:
#
#     arguments = argument (',' argument )*
#     argument = vfpdef ['=' test]
#     kwargs = '**' vfpdef [',']
#     args = '*' [vfpdef]
#     kwonly_kwargs = (',' argument )* [',' [kwargs]]
#     args_kwonly_kwargs = args kwonly_kwargs | kwargs
#     poskeyword_args_kwonly_kwargs = arguments [',' [args_kwonly_kwargs]]
#     vararglist_no_posonly = poskeyword_args_kwonly_kwargs | args_kwonly_kwargs
#     varargslist = arguments ',' '/' [','[(vararglist_no_posonly)]] | (vararglist_no_posonly)
#
# It needs to be fully expanded to allow our LL(1) parser to work on it.

varargslist: vfpdef ['=' test ](',' vfpdef ['=' test])* ',' '/' [',' [ (vfpdef ['=' test] (',' vfpdef ['=' test])* [',' [
        '*' [vfpdef] (',' vfpdef ['=' test])* [',' ['**' vfpdef [',']]]
      | '**' vfpdef [',']]]
  | '*' [vfpdef] (',' vfpdef ['=' test])* [',' ['**' vfpdef [',']]]
  | '**' vfpdef [',']) ]] | (vfpdef ['=' test] (',' vfpdef ['=' test])* [',' [
        '*' [vfpdef] (',' vfpdef ['=' test])* [',' ['**' vfpdef [',']]]
      | '**' vfpdef [',']]]
  | '*' [vfpdef] (',' vfpdef ['=' test])* [',' ['**' vfpdef [',']]]
  | '**' vfpdef [',']
)
vfpdef: NAME

stmt: simple_stmt | compound_stmt
simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE
small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt |
             import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
expr_stmt: testlist_star_expr (annassign | augassign (yield_expr|testlist) |
                     [('=' (yield_expr|testlist_star_expr))+ [TYPE_COMMENT]] )
annassign: ':' test ['=' (yield_expr|testlist_star_expr)]
testlist_star_expr: (test|star_expr) (',' (test|star_expr))* [',']
augassign: ('+=' | '-=' | '*=' | '@=' | '/=' | '%=' | '&=' | '|=' | '^=' |
            '<<=' | '>>=' | '**=' | '//=')
# For normal and annotated assignments, additional restrictions enforced by the interpreter
del_stmt: 'del' exprlist
pass_stmt: 'pass'
flow_stmt: break_stmt | continue_stmt | return_stmt | raise_stmt | yield_stmt
break_stmt: 'break'
continue_stmt: 'continue'
return_stmt: 'return' [testlist_star_expr]
yield_stmt: yield_expr
raise_stmt: 'raise' [test ['from' test]]
import_stmt: import_name | import_from
import_name: 'import' dotted_as_names
# note below: the ('.' | '...') is necessary because '...' is tokenized as ELLIPSIS
import_from: ('from' (('.' | '...')* dotted_name | ('.' | '...')+)
              'import' ('*' | '(' import_as_names ')' | import_as_names))
import_as_name: NAME ['as' NAME]
dotted_as_name: dotted_name ['as' NAME]
import_as_names: import_as_name (',' import_as_name)* [',']
dotted_as_names: dotted_as_name (',' dotted_as_name)*
dotted_name: NAME ('.' NAME)*
global_stmt: 'global' NAME (',' NAME)*
nonlocal_stmt: 'nonlocal' NAME (',' NAME)*
assert_stmt: 'assert' test [',' test]

compound_stmt: if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef | classdef | decorated | async_stmt
async_stmt: ASYNC (funcdef | with_stmt | for_stmt)
if_stmt: 'if' namedexpr_test ':' suite ('elif' namedexpr_test ':' suite)* ['else' ':' suite]
while_stmt: 'while' namedexpr_test ':' suite ['else' ':' suite]
for_stmt: 'for' exprlist 'in' testlist ':' [TYPE_COMMENT] suite ['else' ':' suite]
try_stmt: ('try' ':' suite
           ((except_clause ':' suite)+
            ['else' ':' suite]
            ['finally' ':' suite] |
           'finally' ':' suite))
with_stmt: 'with' with_item (',' with_item)*  ':' [TYPE_COMMENT] suite
with_item: test ['as' expr]
# NB compile.c makes sure that the default except clause is last
except_clause: 'except' [test ['as' NAME]]
suite: simple_stmt | NEWLINE INDENT stmt+ DEDENT

namedexpr_test: test [':=' test]
test: or_test ['if' or_test 'else' test] | lambdef
test_nocond: or_test | lambdef_nocond
lambdef: 'lambda' [varargslist] ':' test
lambdef_nocond: 'lambda' [varargslist] ':' test_nocond
or_test: and_test ('or' and_test)*
and_test: not_test ('and' not_test)*
not_test: 'not' not_test | comparison
comparison: expr (comp_op expr)*
# <> isn't actually a valid comparison operator in Python. It's here for the
# sake of a __future__ import described in PEP 401 (which really works :-)
comp_op: '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'
star_expr: '*' expr
expr: xor_expr ('|' xor_expr)*
xor_expr: and_expr ('^' and_expr)*
and_expr: shift_expr ('&' shift_expr)*
shift_expr: arith_expr (('<<'|'>>') arith_expr)*
arith_expr: term (('+'|'-') term)*
term: factor (('*'|'@'|'/'|'%'|'//') factor)*
factor: ('+'|'-'|'~') factor | power
power: atom_expr ['**' factor]
atom_expr: [AWAIT] atom trailer*
atom: ('(' [yield_expr|testlist_comp] ')' |
       '[' [testlist_comp] ']' |
       '{' [dictorsetmaker] '}' |
       NAME | NUMBER | STRING+ | '...' | 'None' | 'True' | 'False')
testlist_comp: (namedexpr_test|star_expr) ( comp_for | (',' (namedexpr_test|star_expr))* [','] )
trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME
subscriptlist: subscript (',' subscript)* [',']
subscript: test | [test] ':' [test] [sliceop]
sliceop: ':' [test]
exprlist: (expr|star_expr) (',' (expr|star_expr))* [',']
testlist: test (',' test)* [',']
dictorsetmaker: ( ((test ':' test | '**' expr)
                   (comp_for | (',' (test ':' test | '**' expr))* [','])) |
                  ((test | star_expr)
                   (comp_for | (',' (test | star_expr))* [','])) )

classdef: 'class' NAME ['(' [arglist] ')'] ':' suite

arglist: argument (',' argument)*  [',']

# The reason that keywords are test nodes instead of NAME is that using NAME
# results in an ambiguity. ast.c makes sure it's a NAME.
# "test '=' test" is really "keyword '=' test", but we have no such token.
# These need to be in a single rule to avoid grammar that is ambiguous
# to our LL(1) parser. Even though 'test' includes '*expr' in star_expr,
# we explicitly match '*' here, too, to give it proper precedence.
# Illegal combinations and orderings are blocked in ast.c:
# multiple (test comp_for) arguments are blocked; keyword unpackings
# that precede iterable unpackings are blocked; etc.
argument: ( test [comp_for] |
            test ':=' test |
            test '=' test |
            '**' test |
            '*' test )

comp_iter: comp_for | comp_if
sync_comp_for: 'for' exprlist 'in' or_test [comp_iter]
comp_for: [ASYNC] sync_comp_for
comp_if: 'if' test_nocond [comp_iter]

# not used in grammar, but may appear in "node" passed from Parser to Compiler
encoding_decl: NAME

yield_expr: 'yield' [yield_arg]
yield_arg: 'from' test | testlist_star_expr

# the TYPE_COMMENT in suites is only parsed for funcdefs,
# but can't go elsewhere due to ambiguity
func_body_suite: simple_stmt | NEWLINE [TYPE_COMMENT NEWLINE] INDENT stmt+ DEDENT

func_type_input: func_type NEWLINE* ENDMARKER
func_type: '(' [typelist] ')' '->' test
# typelist is a modified typedargslist (see above)
typelist: (test (',' test)* [','
       ['*' [test] (',' test)* [',' '**' test] | '**' test]]
     |  '*' [test] (',' test)* [',' '**' test] | '**' test)

*/
