/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "punygram.y"

#include "../file_preprocessing/include/file_preprocessing.h"

extern int yylex();
extern int yyerror(char *);
extern path_wrapper * g_path_wrapper;
extern char * yytext;

const char * token_type_to_string(int type);

#line 82 "punygram.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 12 "punygram.y"

  #include "../file_preprocessing/include/file_preprocessing.h"
  #include "../tree/include/tree.h"

#line 119 "punygram.tab.c"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AMPEREQUAL = 258,              /* AMPEREQUAL  */
    AMPERSAND = 259,               /* AMPERSAND  */
    AND = 260,                     /* AND  */
    AS = 261,                      /* AS  */
    ASSERT = 262,                  /* ASSERT  */
    AT = 263,                      /* AT  */
    BAR = 264,                     /* BAR  */
    BREAK = 265,                   /* BREAK  */
    CIRCUMFLEX = 266,              /* CIRCUMFLEX  */
    CIRCUMFLEXEQUAL = 267,         /* CIRCUMFLEXEQUAL  */
    CLASS = 268,                   /* CLASS  */
    COLON = 269,                   /* COLON  */
    COMMA = 270,                   /* COMMA  */
    CONTINUE = 271,                /* CONTINUE  */
    DEDENT = 272,                  /* DEDENT  */
    DEF = 273,                     /* DEF  */
    DEL = 274,                     /* DEL  */
    DOT = 275,                     /* DOT  */
    DOUBLESLASH = 276,             /* DOUBLESLASH  */
    DOUBLESLASHEQUAL = 277,        /* DOUBLESLASHEQUAL  */
    DOUBLESTAR = 278,              /* DOUBLESTAR  */
    DOUBLESTAREQUAL = 279,         /* DOUBLESTAREQUAL  */
    ELIF = 280,                    /* ELIF  */
    ELSE = 281,                    /* ELSE  */
    ENDMARKER = 282,               /* ENDMARKER  */
    EQEQUAL = 283,                 /* EQEQUAL  */
    EQUAL = 284,                   /* EQUAL  */
    EXCEPT = 285,                  /* EXCEPT  */
    EXEC = 286,                    /* EXEC  */
    FINALLY = 287,                 /* FINALLY  */
    FOR = 288,                     /* FOR  */
    FROM = 289,                    /* FROM  */
    GLOBAL = 290,                  /* GLOBAL  */
    GREATER = 291,                 /* GREATER  */
    GREATEREQUAL = 292,            /* GREATEREQUAL  */
    GRLT = 293,                    /* GRLT  */
    IF = 294,                      /* IF  */
    IMPORT = 295,                  /* IMPORT  */
    IN = 296,                      /* IN  */
    INDENT = 297,                  /* INDENT  */
    IS = 298,                      /* IS  */
    LEFTSHIFT = 299,               /* LEFTSHIFT  */
    LEFTSHIFTEQUAL = 300,          /* LEFTSHIFTEQUAL  */
    LESS = 301,                    /* LESS  */
    LESSEQUAL = 302,               /* LESSEQUAL  */
    LPAR = 303,                    /* LPAR  */
    MINUS = 304,                   /* MINUS  */
    MINEQUAL = 305,                /* MINEQUAL  */
    NEWLINE = 306,                 /* NEWLINE  */
    NOTEQUAL = 307,                /* NOTEQUAL  */
    OR = 308,                      /* OR  */
    PASS = 309,                    /* PASS  */
    PERCENT = 310,                 /* PERCENT  */
    PERCENTEQUAL = 311,            /* PERCENTEQUAL  */
    PLUS = 312,                    /* PLUS  */
    PLUSEQUAL = 313,               /* PLUSEQUAL  */
    PRINT = 314,                   /* PRINT  */
    RAISE = 315,                   /* RAISE  */
    RBRACE = 316,                  /* RBRACE  */
    RETURN = 317,                  /* RETURN  */
    RIGHTSHIFT = 318,              /* RIGHTSHIFT  */
    RIGHTSHIFTEQUAL = 319,         /* RIGHTSHIFTEQUAL  */
    RPAR = 320,                    /* RPAR  */
    RSQB = 321,                    /* RSQB  */
    SEMI = 322,                    /* SEMI  */
    SLASH = 323,                   /* SLASH  */
    SLASHEQUAL = 324,              /* SLASHEQUAL  */
    STAR = 325,                    /* STAR  */
    STAREQUAL = 326,               /* STAREQUAL  */
    TRY = 327,                     /* TRY  */
    VBAREQUAL = 328,               /* VBAREQUAL  */
    WHILE = 329,                   /* WHILE  */
    WITH = 330,                    /* WITH  */
    LSQB = 331,                    /* LSQB  */
    LBRACE = 332,                  /* LBRACE  */
    BACKQUOTE = 333,               /* BACKQUOTE  */
    STRING = 334,                  /* STRING  */
    LAMBDA = 335,                  /* LAMBDA  */
    YIELD = 336,                   /* YIELD  */
    NOT = 337,                     /* NOT  */
    NUMBER = 338,                  /* NUMBER  */
    NAME = 339,                    /* NAME  */
    TILDE = 340,                   /* TILDE  */
    NODENT = 341,                  /* NODENT  */
    VBAR = 342,                    /* VBAR  */
    AMPER = 343,                   /* AMPER  */
    ATEQUAL = 344,                 /* ATEQUAL  */
    RARROW = 345,                  /* RARROW  */
    ELLIPSIS = 346,                /* ELLIPSIS  */
    COLONEQUAL = 347,              /* COLONEQUAL  */
    OP = 348,                      /* OP  */
    AWAIT = 349,                   /* AWAIT  */
    ASYNC = 350,                   /* ASYNC  */
    TYPE = 351,                    /* TYPE  */
    TYPE_IGNORE = 352,             /* TYPE_IGNORE  */
    TYPE_COMMENT = 353,            /* TYPE_COMMENT  */
    ERRORTOKEN = 354,              /* ERRORTOKEN  */
    COMMENT = 355,                 /* COMMENT  */
    POUND_TYPE = 356,              /* POUND_TYPE  */
    NL = 357,                      /* NL  */
    ENCODING = 358,                /* ENCODING  */
    NONE = 359,                    /* NONE  */
    FALSE = 360,                   /* FALSE  */
    TRUE = 361,                    /* TRUE  */
    NONLOCAL = 362                 /* NONLOCAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "punygram.y"

  tree * ast;

#line 247 "punygram.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AMPEREQUAL = 3,                 /* AMPEREQUAL  */
  YYSYMBOL_AMPERSAND = 4,                  /* AMPERSAND  */
  YYSYMBOL_AND = 5,                        /* AND  */
  YYSYMBOL_AS = 6,                         /* AS  */
  YYSYMBOL_ASSERT = 7,                     /* ASSERT  */
  YYSYMBOL_AT = 8,                         /* AT  */
  YYSYMBOL_BAR = 9,                        /* BAR  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_CIRCUMFLEX = 11,                /* CIRCUMFLEX  */
  YYSYMBOL_CIRCUMFLEXEQUAL = 12,           /* CIRCUMFLEXEQUAL  */
  YYSYMBOL_CLASS = 13,                     /* CLASS  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_DEDENT = 17,                    /* DEDENT  */
  YYSYMBOL_DEF = 18,                       /* DEF  */
  YYSYMBOL_DEL = 19,                       /* DEL  */
  YYSYMBOL_DOT = 20,                       /* DOT  */
  YYSYMBOL_DOUBLESLASH = 21,               /* DOUBLESLASH  */
  YYSYMBOL_DOUBLESLASHEQUAL = 22,          /* DOUBLESLASHEQUAL  */
  YYSYMBOL_DOUBLESTAR = 23,                /* DOUBLESTAR  */
  YYSYMBOL_DOUBLESTAREQUAL = 24,           /* DOUBLESTAREQUAL  */
  YYSYMBOL_ELIF = 25,                      /* ELIF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_ENDMARKER = 27,                 /* ENDMARKER  */
  YYSYMBOL_EQEQUAL = 28,                   /* EQEQUAL  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_EXCEPT = 30,                    /* EXCEPT  */
  YYSYMBOL_EXEC = 31,                      /* EXEC  */
  YYSYMBOL_FINALLY = 32,                   /* FINALLY  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_FROM = 34,                      /* FROM  */
  YYSYMBOL_GLOBAL = 35,                    /* GLOBAL  */
  YYSYMBOL_GREATER = 36,                   /* GREATER  */
  YYSYMBOL_GREATEREQUAL = 37,              /* GREATEREQUAL  */
  YYSYMBOL_GRLT = 38,                      /* GRLT  */
  YYSYMBOL_IF = 39,                        /* IF  */
  YYSYMBOL_IMPORT = 40,                    /* IMPORT  */
  YYSYMBOL_IN = 41,                        /* IN  */
  YYSYMBOL_INDENT = 42,                    /* INDENT  */
  YYSYMBOL_IS = 43,                        /* IS  */
  YYSYMBOL_LEFTSHIFT = 44,                 /* LEFTSHIFT  */
  YYSYMBOL_LEFTSHIFTEQUAL = 45,            /* LEFTSHIFTEQUAL  */
  YYSYMBOL_LESS = 46,                      /* LESS  */
  YYSYMBOL_LESSEQUAL = 47,                 /* LESSEQUAL  */
  YYSYMBOL_LPAR = 48,                      /* LPAR  */
  YYSYMBOL_MINUS = 49,                     /* MINUS  */
  YYSYMBOL_MINEQUAL = 50,                  /* MINEQUAL  */
  YYSYMBOL_NEWLINE = 51,                   /* NEWLINE  */
  YYSYMBOL_NOTEQUAL = 52,                  /* NOTEQUAL  */
  YYSYMBOL_OR = 53,                        /* OR  */
  YYSYMBOL_PASS = 54,                      /* PASS  */
  YYSYMBOL_PERCENT = 55,                   /* PERCENT  */
  YYSYMBOL_PERCENTEQUAL = 56,              /* PERCENTEQUAL  */
  YYSYMBOL_PLUS = 57,                      /* PLUS  */
  YYSYMBOL_PLUSEQUAL = 58,                 /* PLUSEQUAL  */
  YYSYMBOL_PRINT = 59,                     /* PRINT  */
  YYSYMBOL_RAISE = 60,                     /* RAISE  */
  YYSYMBOL_RBRACE = 61,                    /* RBRACE  */
  YYSYMBOL_RETURN = 62,                    /* RETURN  */
  YYSYMBOL_RIGHTSHIFT = 63,                /* RIGHTSHIFT  */
  YYSYMBOL_RIGHTSHIFTEQUAL = 64,           /* RIGHTSHIFTEQUAL  */
  YYSYMBOL_RPAR = 65,                      /* RPAR  */
  YYSYMBOL_RSQB = 66,                      /* RSQB  */
  YYSYMBOL_SEMI = 67,                      /* SEMI  */
  YYSYMBOL_SLASH = 68,                     /* SLASH  */
  YYSYMBOL_SLASHEQUAL = 69,                /* SLASHEQUAL  */
  YYSYMBOL_STAR = 70,                      /* STAR  */
  YYSYMBOL_STAREQUAL = 71,                 /* STAREQUAL  */
  YYSYMBOL_TRY = 72,                       /* TRY  */
  YYSYMBOL_VBAREQUAL = 73,                 /* VBAREQUAL  */
  YYSYMBOL_WHILE = 74,                     /* WHILE  */
  YYSYMBOL_WITH = 75,                      /* WITH  */
  YYSYMBOL_LSQB = 76,                      /* LSQB  */
  YYSYMBOL_LBRACE = 77,                    /* LBRACE  */
  YYSYMBOL_BACKQUOTE = 78,                 /* BACKQUOTE  */
  YYSYMBOL_STRING = 79,                    /* STRING  */
  YYSYMBOL_LAMBDA = 80,                    /* LAMBDA  */
  YYSYMBOL_YIELD = 81,                     /* YIELD  */
  YYSYMBOL_NOT = 82,                       /* NOT  */
  YYSYMBOL_NUMBER = 83,                    /* NUMBER  */
  YYSYMBOL_NAME = 84,                      /* NAME  */
  YYSYMBOL_TILDE = 85,                     /* TILDE  */
  YYSYMBOL_NODENT = 86,                    /* NODENT  */
  YYSYMBOL_VBAR = 87,                      /* VBAR  */
  YYSYMBOL_AMPER = 88,                     /* AMPER  */
  YYSYMBOL_ATEQUAL = 89,                   /* ATEQUAL  */
  YYSYMBOL_RARROW = 90,                    /* RARROW  */
  YYSYMBOL_ELLIPSIS = 91,                  /* ELLIPSIS  */
  YYSYMBOL_COLONEQUAL = 92,                /* COLONEQUAL  */
  YYSYMBOL_OP = 93,                        /* OP  */
  YYSYMBOL_AWAIT = 94,                     /* AWAIT  */
  YYSYMBOL_ASYNC = 95,                     /* ASYNC  */
  YYSYMBOL_TYPE = 96,                      /* TYPE  */
  YYSYMBOL_TYPE_IGNORE = 97,               /* TYPE_IGNORE  */
  YYSYMBOL_TYPE_COMMENT = 98,              /* TYPE_COMMENT  */
  YYSYMBOL_ERRORTOKEN = 99,                /* ERRORTOKEN  */
  YYSYMBOL_COMMENT = 100,                  /* COMMENT  */
  YYSYMBOL_POUND_TYPE = 101,               /* POUND_TYPE  */
  YYSYMBOL_NL = 102,                       /* NL  */
  YYSYMBOL_ENCODING = 103,                 /* ENCODING  */
  YYSYMBOL_NONE = 104,                     /* NONE  */
  YYSYMBOL_FALSE = 105,                    /* FALSE  */
  YYSYMBOL_TRUE = 106,                     /* TRUE  */
  YYSYMBOL_NONLOCAL = 107,                 /* NONLOCAL  */
  YYSYMBOL_YYACCEPT = 108,                 /* $accept  */
  YYSYMBOL_start = 109,                    /* start  */
  YYSYMBOL_single_input = 110,             /* single_input  */
  YYSYMBOL_file_input = 111,               /* file_input  */
  YYSYMBOL_pick_NEWLINE_stmt = 112,        /* pick_NEWLINE_stmt  */
  YYSYMBOL_star_NEWLINE_stmt = 113,        /* star_NEWLINE_stmt  */
  YYSYMBOL_decorator = 114,                /* decorator  */
  YYSYMBOL_opt_arglist = 115,              /* opt_arglist  */
  YYSYMBOL_decorators = 116,               /* decorators  */
  YYSYMBOL_decorated = 117,                /* decorated  */
  YYSYMBOL_funcdef = 118,                  /* funcdef  */
  YYSYMBOL_parameters = 119,               /* parameters  */
  YYSYMBOL_varargslist = 120,              /* varargslist  */
  YYSYMBOL_opt_EQUAL_test = 121,           /* opt_EQUAL_test  */
  YYSYMBOL_star_fpdef_COMMA = 122,         /* star_fpdef_COMMA  */
  YYSYMBOL_opt_DOUBLESTAR_NAME = 123,      /* opt_DOUBLESTAR_NAME  */
  YYSYMBOL_pick_STAR_DOUBLESTAR = 124,     /* pick_STAR_DOUBLESTAR  */
  YYSYMBOL_fpdef = 125,                    /* fpdef  */
  YYSYMBOL_fplist = 126,                   /* fplist  */
  YYSYMBOL_stmt = 127,                     /* stmt  */
  YYSYMBOL_simple_stmt = 128,              /* simple_stmt  */
  YYSYMBOL_small_stmt = 129,               /* small_stmt  */
  YYSYMBOL_expr_stmt = 130,                /* expr_stmt  */
  YYSYMBOL_pick_yield_expr_testlist = 131, /* pick_yield_expr_testlist  */
  YYSYMBOL_star_EQUAL = 132,               /* star_EQUAL  */
  YYSYMBOL_augassign = 133,                /* augassign  */
  YYSYMBOL_print_stmt = 134,               /* print_stmt  */
  YYSYMBOL_opt_test = 135,                 /* opt_test  */
  YYSYMBOL_opt_test_2 = 136,               /* opt_test_2  */
  YYSYMBOL_del_stmt = 137,                 /* del_stmt  */
  YYSYMBOL_pass_stmt = 138,                /* pass_stmt  */
  YYSYMBOL_flow_stmt = 139,                /* flow_stmt  */
  YYSYMBOL_break_stmt = 140,               /* break_stmt  */
  YYSYMBOL_continue_stmt = 141,            /* continue_stmt  */
  YYSYMBOL_return_stmt = 142,              /* return_stmt  */
  YYSYMBOL_yield_stmt = 143,               /* yield_stmt  */
  YYSYMBOL_raise_stmt = 144,               /* raise_stmt  */
  YYSYMBOL_opt_COMMA_test = 145,           /* opt_COMMA_test  */
  YYSYMBOL_opt_test_3 = 146,               /* opt_test_3  */
  YYSYMBOL_import_stmt = 147,              /* import_stmt  */
  YYSYMBOL_import_name = 148,              /* import_name  */
  YYSYMBOL_import_from = 149,              /* import_from  */
  YYSYMBOL_star_DOT = 150,                 /* star_DOT  */
  YYSYMBOL_plus_DOT = 151,                 /* plus_DOT  */
  YYSYMBOL_pick_STAR_import = 152,         /* pick_STAR_import  */
  YYSYMBOL_import_as_name = 153,           /* import_as_name  */
  YYSYMBOL_dotted_as_name = 154,           /* dotted_as_name  */
  YYSYMBOL_import_as_names = 155,          /* import_as_names  */
  YYSYMBOL_dotted_as_names = 156,          /* dotted_as_names  */
  YYSYMBOL_dotted_name = 157,              /* dotted_name  */
  YYSYMBOL_global_stmt = 158,              /* global_stmt  */
  YYSYMBOL_exec_stmt = 159,                /* exec_stmt  */
  YYSYMBOL_assert_stmt = 160,              /* assert_stmt  */
  YYSYMBOL_compound_stmt = 161,            /* compound_stmt  */
  YYSYMBOL_if_stmt = 162,                  /* if_stmt  */
  YYSYMBOL_star_ELIF = 163,                /* star_ELIF  */
  YYSYMBOL_while_stmt = 164,               /* while_stmt  */
  YYSYMBOL_for_stmt = 165,                 /* for_stmt  */
  YYSYMBOL_try_stmt = 166,                 /* try_stmt  */
  YYSYMBOL_plus_except = 167,              /* plus_except  */
  YYSYMBOL_opt_ELSE = 168,                 /* opt_ELSE  */
  YYSYMBOL_opt_FINALLY = 169,              /* opt_FINALLY  */
  YYSYMBOL_with_stmt = 170,                /* with_stmt  */
  YYSYMBOL_star_COMMA_with_item = 171,     /* star_COMMA_with_item  */
  YYSYMBOL_with_item = 172,                /* with_item  */
  YYSYMBOL_except_clause = 173,            /* except_clause  */
  YYSYMBOL_pick_AS_COMMA = 174,            /* pick_AS_COMMA  */
  YYSYMBOL_opt_AS_COMMA = 175,             /* opt_AS_COMMA  */
  YYSYMBOL_suite = 176,                    /* suite  */
  YYSYMBOL_177_1 = 177,                    /* $@1  */
  YYSYMBOL_plus_stmt = 178,                /* plus_stmt  */
  YYSYMBOL_testlist_safe = 179,            /* testlist_safe  */
  YYSYMBOL_old_test = 180,                 /* old_test  */
  YYSYMBOL_old_lambdef = 181,              /* old_lambdef  */
  YYSYMBOL_test = 182,                     /* test  */
  YYSYMBOL_opt_IF_ELSE = 183,              /* opt_IF_ELSE  */
  YYSYMBOL_or_test = 184,                  /* or_test  */
  YYSYMBOL_and_test = 185,                 /* and_test  */
  YYSYMBOL_not_test = 186,                 /* not_test  */
  YYSYMBOL_comparison = 187,               /* comparison  */
  YYSYMBOL_comp_op = 188,                  /* comp_op  */
  YYSYMBOL_expr = 189,                     /* expr  */
  YYSYMBOL_xor_expr = 190,                 /* xor_expr  */
  YYSYMBOL_and_expr = 191,                 /* and_expr  */
  YYSYMBOL_shift_expr = 192,               /* shift_expr  */
  YYSYMBOL_pick_LEFTSHIFT_RIGHTSHIFT = 193, /* pick_LEFTSHIFT_RIGHTSHIFT  */
  YYSYMBOL_arith_expr = 194,               /* arith_expr  */
  YYSYMBOL_pick_PLUS_MINUS = 195,          /* pick_PLUS_MINUS  */
  YYSYMBOL_term = 196,                     /* term  */
  YYSYMBOL_pick_multop = 197,              /* pick_multop  */
  YYSYMBOL_factor = 198,                   /* factor  */
  YYSYMBOL_pick_unop = 199,                /* pick_unop  */
  YYSYMBOL_power = 200,                    /* power  */
  YYSYMBOL_star_trailer = 201,             /* star_trailer  */
  YYSYMBOL_atom = 202,                     /* atom  */
  YYSYMBOL_pick_yield_expr_testlist_comp = 203, /* pick_yield_expr_testlist_comp  */
  YYSYMBOL_opt_yield_test = 204,           /* opt_yield_test  */
  YYSYMBOL_opt_listmaker = 205,            /* opt_listmaker  */
  YYSYMBOL_opt_dictorsetmaker = 206,       /* opt_dictorsetmaker  */
  YYSYMBOL_plus_STRING = 207,              /* plus_STRING  */
  YYSYMBOL_listmaker = 208,                /* listmaker  */
  YYSYMBOL_testlist_comp = 209,            /* testlist_comp  */
  YYSYMBOL_lambdef = 210,                  /* lambdef  */
  YYSYMBOL_trailer = 211,                  /* trailer  */
  YYSYMBOL_subscriptlist = 212,            /* subscriptlist  */
  YYSYMBOL_subscript = 213,                /* subscript  */
  YYSYMBOL_opt_test_only = 214,            /* opt_test_only  */
  YYSYMBOL_opt_sliceop = 215,              /* opt_sliceop  */
  YYSYMBOL_sliceop = 216,                  /* sliceop  */
  YYSYMBOL_exprlist = 217,                 /* exprlist  */
  YYSYMBOL_testlist = 218,                 /* testlist  */
  YYSYMBOL_dictorsetmaker = 219,           /* dictorsetmaker  */
  YYSYMBOL_pick_comp_for = 220,            /* pick_comp_for  */
  YYSYMBOL_pick_for_test = 221,            /* pick_for_test  */
  YYSYMBOL_classdef = 222,                 /* classdef  */
  YYSYMBOL_opt_testlist = 223,             /* opt_testlist  */
  YYSYMBOL_arglist = 224,                  /* arglist  */
  YYSYMBOL_argument = 225,                 /* argument  */
  YYSYMBOL_opt_comp_for = 226,             /* opt_comp_for  */
  YYSYMBOL_list_iter = 227,                /* list_iter  */
  YYSYMBOL_list_for = 228,                 /* list_for  */
  YYSYMBOL_list_if = 229,                  /* list_if  */
  YYSYMBOL_comp_iter = 230,                /* comp_iter  */
  YYSYMBOL_comp_for = 231,                 /* comp_for  */
  YYSYMBOL_comp_if = 232,                  /* comp_if  */
  YYSYMBOL_testlist1 = 233,                /* testlist1  */
  YYSYMBOL_encoding_decl = 234,            /* encoding_decl  */
  YYSYMBOL_yield_expr = 235,               /* yield_expr  */
  YYSYMBOL_star_fpdef_notest = 236,        /* star_fpdef_notest  */
  YYSYMBOL_star_COMMA_expr = 237,          /* star_COMMA_expr  */
  YYSYMBOL_star_COMMA_fpdef = 238,         /* star_COMMA_fpdef  */
  YYSYMBOL_star_COMMA_test = 239,          /* star_COMMA_test  */
  YYSYMBOL_star_test_COLON_test = 240,     /* star_test_COLON_test  */
  YYSYMBOL_star_COMMA_subscript = 241,     /* star_COMMA_subscript  */
  YYSYMBOL_star_COMMA_import_as_name = 242, /* star_COMMA_import_as_name  */
  YYSYMBOL_plus_COMMA_test = 243,          /* plus_COMMA_test  */
  YYSYMBOL_plus_COMMA_old_test = 244,      /* plus_COMMA_old_test  */
  YYSYMBOL_dictarg = 245,                  /* dictarg  */
  YYSYMBOL_listarg = 246,                  /* listarg  */
  YYSYMBOL_arglist_postlist = 247,         /* arglist_postlist  */
  YYSYMBOL_small_stmt_STAR_OR_SEMI = 248   /* small_stmt_STAR_OR_SEMI  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  141
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   871

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  327
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  493

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   362


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    57,    58,    62,    63,    67,    71,    72,
      76,    84,    88,    89,    93,    94,    98,    99,   103,   104,
     109,   119,   123,   127,   128,   139,   143,   147,   149,   153,
     154,   158,   159,   163,   164,   171,   182,   183,   187,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   203,   204,
     215,   216,   220,   230,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   249,   253,   257,   258,
     262,   263,   267,   271,   275,   276,   277,   278,   279,   283,
     287,   291,   292,   296,   300,   301,   305,   306,   310,   311,
     315,   316,   320,   324,   325,   329,   330,   334,   335,   339,
     340,   341,   345,   346,   350,   351,   355,   359,   360,   364,
     365,   373,   374,   378,   379,   383,   384,   388,   389,   390,
     391,   392,   393,   394,   395,   399,   400,   404,   405,   409,
     410,   414,   415,   419,   420,   424,   425,   429,   430,   434,
     435,   439,   443,   444,   448,   449,   453,   454,   458,   459,
     463,   464,   468,   469,   469,   473,   480,   490,   491,   495,
     496,   500,   501,   505,   506,   510,   511,   515,   516,   520,
     521,   525,   526,   530,   531,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   549,   550,   554,   555,
     559,   560,   564,   565,   569,   570,   574,   575,   583,   584,
     588,   589,   602,   603,   604,   605,   606,   610,   617,   621,
     622,   623,   627,   632,   647,   650,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   666,   667,   671,   672,   676,
     677,   681,   682,   686,   687,   691,   692,   696,   697,   701,
     702,   706,   707,   708,   712,   716,   717,   718,   722,   723,
     727,   728,   732,   733,   737,   741,   745,   746,   750,   751,
     755,   756,   760,   761,   765,   766,   770,   771,   772,   773,
     774,   775,   779,   780,   784,   785,   789,   790,   794,   795,
     799,   800,   804,   805,   809,   810,   814,   815,   819,   820,
     824,   828,   829,   833,   834,   835,   839,   840,   841,   845,
     853,   854,   858,   868,   869,   873,   874,   875,   879,   880,
     881,   885,   886,   887,   891,   892,   893,   897,   898,   899,
     903,   907,   911,   912,   913,   917,   918,   919
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AMPEREQUAL",
  "AMPERSAND", "AND", "AS", "ASSERT", "AT", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS",
  "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR", "MINUS",
  "MINEQUAL", "NEWLINE", "NOTEQUAL", "OR", "PASS", "PERCENT",
  "PERCENTEQUAL", "PLUS", "PLUSEQUAL", "PRINT", "RAISE", "RBRACE",
  "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR", "RSQB", "SEMI",
  "SLASH", "SLASHEQUAL", "STAR", "STAREQUAL", "TRY", "VBAREQUAL", "WHILE",
  "WITH", "LSQB", "LBRACE", "BACKQUOTE", "STRING", "LAMBDA", "YIELD",
  "NOT", "NUMBER", "NAME", "TILDE", "NODENT", "VBAR", "AMPER", "ATEQUAL",
  "RARROW", "ELLIPSIS", "COLONEQUAL", "OP", "AWAIT", "ASYNC", "TYPE",
  "TYPE_IGNORE", "TYPE_COMMENT", "ERRORTOKEN", "COMMENT", "POUND_TYPE",
  "NL", "ENCODING", "NONE", "FALSE", "TRUE", "NONLOCAL", "$accept",
  "start", "single_input", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "fpdef", "fplist", "stmt", "simple_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "augassign", "print_stmt",
  "opt_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "star_DOT", "plus_DOT", "pick_STAR_import",
  "import_as_name", "dotted_as_name", "import_as_names", "dotted_as_names",
  "dotted_name", "global_stmt", "exec_stmt", "assert_stmt",
  "compound_stmt", "if_stmt", "star_ELIF", "while_stmt", "for_stmt",
  "try_stmt", "plus_except", "opt_ELSE", "opt_FINALLY", "with_stmt",
  "star_COMMA_with_item", "with_item", "except_clause", "pick_AS_COMMA",
  "opt_AS_COMMA", "suite", "$@1", "plus_stmt", "testlist_safe", "old_test",
  "old_lambdef", "test", "opt_IF_ELSE", "or_test", "and_test", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "subscript", "opt_test_only",
  "opt_sliceop", "sliceop", "exprlist", "testlist", "dictorsetmaker",
  "pick_comp_for", "pick_for_test", "classdef", "opt_testlist", "arglist",
  "argument", "opt_comp_for", "list_iter", "list_for", "list_if",
  "comp_iter", "comp_for", "comp_if", "testlist1", "encoding_decl",
  "yield_expr", "star_fpdef_notest", "star_COMMA_expr", "star_COMMA_fpdef",
  "star_COMMA_test", "star_test_COLON_test", "star_COMMA_subscript",
  "star_COMMA_import_as_name", "plus_COMMA_test", "plus_COMMA_old_test",
  "dictarg", "listarg", "arglist_postlist", "small_stmt_STAR_OR_SEMI", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-373)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-310)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     327,   703,   -30,  -373,   -29,  -373,    -7,   765,   765,   765,
      67,    16,   703,   -30,   201,  -373,    88,  -373,  -373,   653,
     703,   703,   113,   703,   703,   703,   703,   703,    55,    46,
     703,   753,  -373,   143,  -373,  -373,  -373,   174,  -373,  -373,
     428,   123,   172,   178,  -373,  -373,   184,  -373,   127,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,   182,  -373,  -373,  -373,  -373,  -373,  -373,  -373,
    -373,   185,    83,   194,  -373,   437,   193,   196,   204,     4,
     100,    48,  -373,   765,  -373,    50,  -373,  -373,    35,  -373,
    -373,  -373,  -373,   195,  -373,    38,    25,   161,    66,  -373,
      37,   175,    23,   -30,   180,  -373,   208,  -373,   200,   109,
     133,  -373,   153,  -373,  -373,   703,  -373,   185,   211,  -373,
     586,   214,   215,   225,   156,   167,  -373,   150,   177,  -373,
    -373,     5,  -373,   703,   -18,  -373,   226,    -2,   210,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,  -373,   665,
     190,   162,   703,  -373,   753,   753,  -373,   753,  -373,  -373,
    -373,  -373,  -373,   169,  -373,  -373,  -373,   213,   765,   765,
     765,   765,  -373,  -373,   765,  -373,  -373,   765,  -373,  -373,
    -373,  -373,  -373,   765,  -373,   171,   248,    76,   222,    50,
    -373,  -373,  -373,  -373,   201,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,   201,   703,   173,   248,  -373,   586,
     703,   -12,   245,   765,  -373,   703,   703,  -373,  -373,    97,
      -8,   586,   -30,   176,   765,  -373,  -373,  -373,   246,  -373,
     703,  -373,   223,  -373,   163,   586,   703,   250,   765,   765,
    -373,  -373,  -373,   703,  -373,  -373,  -373,  -373,   703,  -373,
    -373,   251,   202,   703,   186,   188,  -373,   703,   253,   127,
    -373,  -373,   185,    18,   194,  -373,  -373,  -373,   193,   196,
     204,     4,   100,    48,  -373,  -373,   703,   703,   209,   144,
    -373,   258,  -373,   272,   268,   275,   224,   276,   278,   765,
    -373,   264,  -373,  -373,  -373,  -373,  -373,   229,  -373,  -373,
     230,  -373,   233,   586,    66,   285,   287,    -8,   218,  -373,
     297,  -373,   289,  -373,   283,  -373,  -373,   270,   703,  -373,
    -373,   285,  -373,   703,   295,   288,   299,   293,   215,   586,
     193,   274,   157,  -373,   -18,  -373,  -373,  -373,  -373,   305,
    -373,    36,  -373,  -373,  -373,   703,  -373,  -373,  -373,   703,
    -373,  -373,   248,   574,   301,  -373,    62,  -373,   703,  -373,
    -373,   290,   309,  -373,  -373,  -373,   703,  -373,   586,  -373,
     271,   255,   218,  -373,   703,   316,   753,   332,  -373,   507,
     106,   586,   335,   318,   586,   342,  -373,  -373,   715,   703,
    -373,  -373,  -373,   251,   336,  -373,  -373,   210,  -373,  -373,
    -373,   348,  -373,  -373,  -373,   276,  -373,   350,  -373,   586,
    -373,   343,  -373,  -373,   289,   354,   356,    12,   703,  -373,
     507,   355,  -373,  -373,   703,  -373,  -373,   586,   357,  -373,
     344,   586,    47,   130,   362,  -373,   326,   368,  -373,   306,
     253,   574,  -373,   703,  -373,  -373,  -373,   369,  -373,   586,
     586,   715,  -373,  -373,  -373,  -373,  -373,  -373,  -373,   586,
    -373,  -373,   715,   371,   715,  -373,  -373,  -373,   715,  -373,
     703,  -373,  -373,  -373,  -373,   586,   283,  -373,   137,  -373,
    -373,   715,   130,   376,   377,  -373,  -373,  -373,  -373,  -373,
     715,  -373,  -373
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,     0,    79,     0,    80,     0,     0,     0,     0,
      96,     0,     0,     0,   228,   210,     8,    73,   209,    69,
      85,    82,     0,     0,     0,   230,   232,     0,   234,    28,
     292,     0,   221,   220,   211,   223,   222,     0,     3,     2,
      11,     0,    17,     0,   124,   122,     9,    36,   327,    39,
      40,    41,    42,    43,    74,    75,    76,    78,    77,    44,
      90,    91,    45,    46,    47,    37,   117,   118,   119,   120,
     121,   304,   166,   167,   169,   172,   173,   186,   188,   190,
     192,   196,   200,     0,   208,   215,   224,   164,    53,   123,
       4,    83,   220,   116,   109,     0,     0,     0,   298,    72,
     114,     0,    96,     0,     0,   112,     0,   107,    92,   105,
     304,   227,     0,   226,   225,     0,    66,   304,    89,    81,
       0,     0,   143,   145,   304,     0,   229,   304,     0,   231,
     288,     0,   233,     0,     0,    33,     0,     0,    26,   291,
     171,     1,     8,    10,     9,     7,    16,    19,    18,   326,
       0,     0,   303,   255,     0,     0,   163,     0,   177,   176,
     178,   180,   182,   184,   175,   179,   181,     0,     0,     0,
       0,     0,   194,   195,     0,   199,   198,     0,   203,   206,
     205,   204,   202,     0,   207,     0,    15,   249,   213,   215,
      59,    61,    65,    64,     0,    62,    55,    58,    54,    63,
      57,    56,    60,    49,     0,     0,     0,    15,    13,     0,
     265,    28,     0,   297,   254,     0,     0,    95,    97,     0,
       0,     0,     0,     0,     0,   237,   238,   216,    71,    68,
       0,    84,     0,   152,     0,     0,     0,     0,     0,     0,
     235,   236,   217,     0,   257,   260,   261,   218,     0,   219,
     240,   295,     0,     0,     0,     0,    23,     0,   301,   327,
      38,   111,   304,     0,   168,   170,   185,   183,   174,   187,
     189,   191,   193,   197,   201,   243,     0,     0,     0,   275,
      14,   268,   271,   270,     0,   246,     0,   310,     0,     0,
     214,    53,    51,    50,    48,   115,   110,     0,   263,   264,
       0,    22,     0,     0,   298,    87,     0,     0,     0,    99,
     103,    94,   313,   101,   128,   108,   104,     0,     0,    67,
      70,    87,   153,   147,     0,   138,     0,   130,   143,     0,
     144,     0,   307,   289,   294,    35,    34,   239,    32,    30,
      25,    28,    24,   325,   302,     0,   320,   321,   241,     0,
     272,   274,   267,     0,     0,   242,   249,   244,   249,   212,
      52,     0,     0,    21,    20,   296,     0,   113,     0,    93,
       0,     0,   312,   106,     0,   126,     0,   316,    88,     0,
     151,     0,     0,   140,     0,     0,   142,   141,     0,   306,
     256,   258,   259,   295,     0,    31,    27,    26,   165,   273,
     266,   324,   323,   269,   245,   310,   248,   251,    12,     0,
      86,   132,   100,   102,   313,     0,     0,   285,   315,   314,
     156,     0,   148,   149,     0,   146,   134,     0,     0,   133,
     136,     0,    28,   279,   158,   160,   159,     0,   293,     0,
     301,     0,   308,   253,   247,   250,   262,     0,   311,     0,
       0,     0,   284,   282,   283,   155,   154,   150,   137,     0,
     135,   129,     0,     0,     0,   278,   276,   277,     0,   157,
       0,    29,   299,   322,   252,     0,   128,   125,   287,   139,
     162,     0,   281,   319,   307,   131,   127,   286,   161,   280,
     318,   317,   305
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -373,  -373,  -373,  -373,  -373,   353,  -373,   187,   358,  -373,
     352,  -373,  -205,     0,    57,  -373,  -373,  -129,  -373,    34,
       1,   247,  -373,   212,   122,  -373,  -373,  -373,  -373,  -373,
    -373,  -373,  -373,  -373,  -373,  -373,  -373,    93,  -373,  -373,
    -373,  -373,   313,   317,   111,    52,   198,   114,  -373,    10,
    -373,  -373,  -373,  -373,  -373,   -51,  -373,  -373,  -373,    -4,
    -373,  -373,  -373,    99,   192,  -373,  -373,  -373,  -206,  -373,
       9,  -373,  -372,  -373,    -1,  -373,  -152,   279,   -22,  -373,
    -373,    24,   261,   267,   260,  -373,   265,  -373,   266,  -373,
     -76,  -373,  -373,   256,  -373,  -373,  -373,  -373,  -373,   420,
    -373,  -373,  -373,  -373,  -373,    94,    91,  -373,  -373,    -5,
       7,  -373,  -373,  -373,   408,  -373,   101,  -339,  -373,   -28,
     328,  -373,   -23,  -100,  -373,  -373,  -373,    -6,    63,   154,
      17,   -75,   -24,    59,    56,    89,   -11,  -336,  -373,    30,
     227
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    37,    38,    39,    40,    41,    42,   278,    43,    44,
      45,   212,   136,   258,   137,   395,   256,   138,   252,   420,
     233,    48,    49,   291,   203,   204,    50,   116,   319,    51,
      52,    53,    54,    55,    56,    57,    58,   367,   231,    59,
      60,    61,   103,   104,   311,   312,   107,   313,   108,   109,
      62,    63,    64,    65,    66,   375,    67,    68,    69,   325,
     383,   429,    70,   237,   122,   326,   424,   425,   234,   379,
     421,   433,   483,   435,    71,   156,    72,    73,    74,    75,
     168,    76,    77,    78,    79,   174,    80,   177,    81,   183,
      82,    83,    84,   188,    85,   111,   112,   125,   128,    86,
     126,   113,    87,   189,   286,   287,   288,   444,   445,    99,
      88,   129,   390,   244,    89,   300,   280,   281,   350,   465,
     466,   467,   452,   453,   454,   131,    90,    91,   335,   214,
     342,   153,   392,   357,   373,   320,   469,   282,   283,   403,
     150
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      93,    47,   263,   298,   101,   251,   302,   184,   114,   140,
     225,   106,    95,   110,   401,   314,   434,   402,   117,   118,
     248,   254,   121,   123,   124,   127,   130,   245,   119,   327,
     134,    98,   100,    98,    46,   226,   134,   139,   190,   209,
     308,    47,   229,   102,   345,   224,   169,   191,   172,   241,
    -300,   451,   246,   301,    94,    96,   178,   192,   206,   193,
     133,   462,   309,   -98,   194,   155,   135,   173,   255,   179,
     185,   155,   135,   210,   144,   169,   310,    97,   215,   478,
     195,   213,   284,   249,   134,   196,   207,   102,    -5,   208,
     480,   197,   482,   198,   134,   134,   284,   364,   186,   199,
     105,  -300,   401,   180,   200,   402,   201,   274,   202,   488,
      14,    15,   422,   219,   228,   223,   181,   206,   182,    18,
     135,   423,   154,   387,    14,    15,   187,   120,  -309,   206,
     135,   135,   250,    18,    28,   265,   155,   307,    25,    26,
      27,    28,    29,  -290,    31,    32,    92,    34,   152,   175,
     145,   262,    25,    26,    27,    28,    29,   176,    31,    32,
      92,    34,   411,   239,   243,   152,   224,    35,    36,   464,
     224,   152,   389,   349,   141,   426,   451,   224,   430,   351,
       2,    35,    36,   224,    -6,   279,   285,   344,   293,   239,
     224,     4,   268,   323,   149,   324,     6,   151,   293,   157,
     152,   292,   169,   446,   295,   393,   279,   170,   171,   211,
     205,   292,   397,   359,   305,   222,   216,   299,   227,   317,
     220,   458,   221,   306,   417,   461,   230,   463,   235,   321,
     236,   238,   391,   242,   331,   123,   436,   304,   247,   257,
     253,   260,   332,   476,   477,   289,   261,   333,    98,    14,
      15,   266,   337,   479,   267,   275,   340,   296,    18,   303,
     316,   318,   330,    98,   329,   322,   334,   336,   341,   485,
     338,   276,   339,   352,   348,   346,   347,    25,    26,    27,
      28,    29,    30,    31,    32,    92,    34,   353,   354,  -248,
     355,   356,   358,   194,   361,   362,    14,    15,   363,   436,
     366,   368,   310,   371,   372,    18,    35,    36,   374,   381,
     436,   376,   436,   384,   382,   388,   436,   377,   277,   385,
     394,   404,   380,   409,    25,    26,    27,    28,    29,   436,
      31,    32,    92,    34,     1,     2,   412,     3,   436,   413,
       4,   408,   416,     5,   398,     6,     7,   418,   399,   427,
     428,   279,   279,    35,    36,   285,   431,   406,     8,   439,
       9,    10,    11,   441,   443,   410,    12,    13,   449,   447,
     450,   459,   456,   415,   323,    14,    15,   468,    16,   155,
      47,    17,   470,   475,    18,   481,    19,    20,   437,    21,
     471,   490,   389,   143,   297,   147,   259,   440,   396,    22,
     146,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,   360,   378,   217,   294,   377,   369,   218,
     315,    47,   370,   457,   414,   486,   460,   386,   328,   455,
     269,   271,    35,    36,   264,     1,     2,   270,     3,   272,
     279,     4,   474,   273,     5,   290,     6,     7,   132,   407,
     405,   148,   240,   400,   489,   487,   438,   472,   365,     8,
     492,     9,    10,    11,   442,   158,   419,    12,    13,   484,
     448,   473,   491,   159,   160,   161,    14,    15,   162,   142,
     163,     0,    17,   164,   165,    18,   343,    19,    20,   166,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    92,    34,     1,     2,     0,     3,     0,   167,
       4,     0,     0,     5,     0,     6,     7,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     8,     0,
       9,    10,    11,     0,     0,     0,    12,    13,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,    17,     0,     0,    18,     0,    19,    20,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    92,    34,     1,     0,     0,     3,   276,     0,     0,
       0,     0,     5,     0,     0,     7,     0,     0,     0,     0,
       0,     0,    35,    36,     0,     0,     0,     8,     0,     0,
      10,    11,    14,    15,     0,     0,    13,     0,     0,     0,
       0,    18,     0,     0,    14,    15,     0,   232,     0,     0,
      17,     0,     0,    18,     0,    19,    20,     0,    21,     0,
      25,    26,    27,    28,    29,     0,    31,    32,    92,    34,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      92,    34,     1,     0,     0,     3,     0,     0,     0,    35,
      36,     5,     0,     0,     7,     0,     0,     0,     0,     0,
       0,    35,    36,     0,     0,     0,     8,     0,     0,    10,
      11,    14,    15,     0,     0,    13,     0,     0,     0,     0,
      18,     0,     0,    14,    15,     0,   115,     0,     0,    17,
       0,     0,    18,     0,    19,    20,     0,    21,     0,    25,
      26,    27,    28,    29,     0,    31,    32,    92,    34,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,    92,
      34,    14,    15,     0,     0,     0,     0,     0,    35,    36,
      18,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      35,    36,    18,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,    29,     0,    31,    32,    92,    34,     0,
       0,    25,    26,    27,    28,   432,     0,    31,    32,    92,
      34,    14,    15,     0,     0,     0,     0,     0,    35,    36,
      18,     0,     0,    14,    15,     0,     0,     0,     0,     0,
      35,    36,    18,     0,     0,     0,     0,     0,     0,    25,
      26,    27,    28,     0,     0,    31,    32,    92,    34,     0,
       0,    25,    26,    27,    28,     0,     0,     0,    32,    92,
      34,     0,     0,     0,     0,     0,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36
};

static const yytype_int16 yycheck[] =
{
       1,     0,   154,   209,     9,   134,   211,    83,    14,    31,
     110,    12,     2,    14,   353,   221,   388,   353,    19,    20,
      15,    23,    23,    24,    25,    26,    27,   127,    21,   235,
      48,     7,     8,     9,     0,   110,    48,    30,     3,    14,
      48,    40,   117,    20,    26,    33,     9,    12,    44,   124,
      14,    39,   127,    65,    84,    84,     8,    22,    20,    24,
      14,    14,    70,    40,    29,    53,    84,    63,    70,    21,
      20,    53,    84,    48,    40,     9,    84,    84,    41,   451,
      45,    15,    20,    78,    48,    50,    48,    20,     0,    51,
     462,    56,   464,    58,    48,    48,    20,   303,    48,    64,
      84,    65,   441,    55,    69,   441,    71,   183,    73,   481,
      48,    49,     6,   103,   115,     6,    68,    20,    70,    57,
      84,    15,    39,   329,    48,    49,    76,    14,    66,    20,
      84,    84,   133,    57,    79,   157,    53,    40,    76,    77,
      78,    79,    80,     0,    82,    83,    84,    85,    15,    49,
      27,   152,    76,    77,    78,    79,    80,    57,    82,    83,
      84,    85,   368,    33,    14,    15,    33,   105,   106,    39,
      33,    15,    15,    29,     0,   381,    39,    33,   384,   279,
       8,   105,   106,    33,     0,   186,   187,   262,   194,    33,
      33,    13,   168,    30,    67,    32,    18,    15,   204,     5,
      15,   194,     9,   409,   205,   334,   207,    11,     4,    48,
      15,   204,   341,   289,   215,    15,    41,   210,    65,   224,
      40,   427,    14,   216,   376,   431,    15,   432,    14,   230,
      15,     6,   332,    66,   239,   236,   388,   213,    61,    29,
      14,    51,   243,   449,   450,    23,    84,   248,   224,    48,
      49,    82,   253,   459,    41,    84,   257,    84,    57,    14,
      84,    15,   238,   239,    14,    42,    15,    65,    15,   475,
      84,    23,    84,    15,    65,   276,   277,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    15,    20,    14,
      66,    15,    14,    29,    65,    65,    48,    49,    65,   451,
      15,    14,    84,     6,    15,    57,   105,   106,    25,    14,
     462,    41,   464,    14,    26,    41,   468,   318,    70,    26,
      15,    20,   323,    14,    76,    77,    78,    79,    80,   481,
      82,    83,    84,    85,     7,     8,    65,    10,   490,    84,
      13,    51,    26,    16,   345,    18,    19,    15,   349,    14,
      32,   352,   353,   105,   106,   356,    14,   358,    31,    23,
      33,    34,    35,    15,    14,   366,    39,    40,    14,    26,
      14,    14,    17,   374,    30,    48,    49,    15,    51,    53,
     379,    54,    14,    14,    57,    14,    59,    60,   389,    62,
      84,    15,    15,    40,   207,    43,   149,   397,   341,    72,
      42,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,   291,   321,   102,   204,   418,   307,   102,
     222,   420,   308,   424,   372,   476,   430,   328,   236,   420,
     169,   171,   105,   106,   155,     7,     8,   170,    10,   174,
     441,    13,   443,   177,    16,   189,    18,    19,    28,   358,
     356,    43,   124,   352,   482,   478,   393,   440,   304,    31,
     484,    33,    34,    35,   405,    28,   377,    39,    40,   470,
     414,   441,   483,    36,    37,    38,    48,    49,    41,    51,
      43,    -1,    54,    46,    47,    57,   259,    59,    60,    52,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,     7,     8,    -1,    10,    -1,    82,
      13,    -1,    -1,    16,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,    -1,    31,    -1,
      33,    34,    35,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,     7,    -1,    -1,    10,    23,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,    -1,    31,    -1,    -1,
      34,    35,    48,    49,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    48,    49,    -1,    51,    -1,    -1,
      54,    -1,    -1,    57,    -1,    59,    60,    -1,    62,    -1,
      76,    77,    78,    79,    80,    -1,    82,    83,    84,    85,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,     7,    -1,    -1,    10,    -1,    -1,    -1,   105,
     106,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    48,    49,    -1,    -1,    40,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    48,    49,    -1,    63,    -1,    -1,    54,
      -1,    -1,    57,    -1,    59,    60,    -1,    62,    -1,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    48,    49,    -1,    -1,    -1,    -1,    -1,   105,   106,
      57,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
     105,   106,    57,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    82,    83,    84,    85,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    83,    84,
      85,    48,    49,    -1,    -1,    -1,    -1,    -1,   105,   106,
      57,    -1,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,
     105,   106,    57,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    -1,    -1,    82,    83,    84,    85,    -1,
      -1,    76,    77,    78,    79,    -1,    -1,    -1,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,   106
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    13,    16,    18,    19,    31,    33,
      34,    35,    39,    40,    48,    49,    51,    54,    57,    59,
      60,    62,    72,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   105,   106,   109,   110,   111,
     112,   113,   114,   116,   117,   118,   127,   128,   129,   130,
     134,   137,   138,   139,   140,   141,   142,   143,   144,   147,
     148,   149,   158,   159,   160,   161,   162,   164,   165,   166,
     170,   182,   184,   185,   186,   187,   189,   190,   191,   192,
     194,   196,   198,   199,   200,   202,   207,   210,   218,   222,
     234,   235,    84,   182,    84,   157,    84,    84,   189,   217,
     189,   217,    20,   150,   151,    84,   182,   154,   156,   157,
     182,   203,   204,   209,   235,    63,   135,   182,   182,   218,
      14,   182,   172,   182,   182,   205,   208,   182,   206,   219,
     182,   233,   207,    14,    48,    84,   120,   122,   125,   218,
     186,     0,    51,   113,   127,    27,   116,   118,   222,    67,
     248,    15,    15,   239,    39,    53,   183,     5,    28,    36,
      37,    38,    41,    43,    46,    47,    52,    82,   188,     9,
      11,     4,    44,    63,   193,    49,    57,   195,     8,    21,
      55,    68,    70,   197,   198,    20,    48,    76,   201,   211,
       3,    12,    22,    24,    29,    45,    50,    56,    58,    64,
      69,    71,    73,   132,   133,    15,    20,    48,    51,    14,
      48,    48,   119,    15,   237,    41,    41,   150,   151,   157,
      40,    14,    15,     6,    33,   231,   239,    65,   182,   239,
      15,   146,    51,   128,   176,    14,    15,   171,     6,    33,
     228,   239,    66,    14,   221,   231,   239,    61,    15,    78,
     182,   125,   126,    14,    23,    70,   124,    29,   121,   129,
      51,    84,   182,   184,   185,   186,    82,    41,   189,   190,
     191,   192,   194,   196,   198,    84,    23,    70,   115,   182,
     224,   225,   245,   246,    20,   182,   212,   213,   214,    23,
     201,   131,   218,   235,   131,   182,    84,   115,   176,   218,
     223,    65,   120,    14,   189,   182,   218,    40,    48,    70,
      84,   152,   153,   155,   176,   154,    84,   217,    15,   136,
     243,   182,    42,    30,    32,   167,   173,   176,   172,    14,
     189,   217,   182,   182,    15,   236,    65,   182,    84,    84,
     182,    15,   238,   248,   239,    26,   182,   182,    65,    29,
     226,   231,    15,    15,    20,    66,    15,   241,    14,   198,
     132,    65,    65,    65,   176,   237,    15,   145,    14,   152,
     155,     6,    15,   242,    25,   163,    41,   182,   145,   177,
     182,    14,    26,   168,    14,    26,   171,   176,    41,    15,
     220,   231,   240,   125,    15,   123,   122,   125,   182,   182,
     224,   225,   245,   247,    20,   213,   182,   214,    51,    14,
     182,   176,    65,    84,   153,   182,    26,   184,    15,   243,
     127,   178,     6,    15,   174,   175,   176,    14,    32,   169,
     176,    14,    80,   179,   180,   181,   184,   182,   236,    23,
     121,    15,   241,    14,   215,   216,   176,    26,   242,    14,
      14,    39,   230,   231,   232,   178,    17,   182,   176,    14,
     167,   176,    14,   120,    39,   227,   228,   229,    15,   244,
      14,    84,   238,   247,   182,    14,   176,   176,   180,   176,
     180,    14,   180,   180,   182,   176,   163,   230,   180,   227,
      15,   244,   240
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   116,   116,   117,   117,
     118,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   126,   127,   127,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   138,   139,   139,   139,   139,   139,   140,
     141,   142,   142,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   148,   149,   149,   150,   150,   151,   151,   152,
     152,   152,   153,   153,   154,   154,   155,   156,   156,   157,
     157,   158,   158,   159,   159,   160,   160,   161,   161,   161,
     161,   161,   161,   161,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     169,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   177,   176,   178,   178,   179,   179,   180,
     180,   181,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   187,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   189,   189,   190,   190,
     191,   191,   192,   192,   193,   193,   194,   194,   195,   195,
     196,   196,   197,   197,   197,   197,   197,   198,   198,   199,
     199,   199,   200,   200,   201,   201,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   211,   212,   213,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   218,   219,   219,   220,   220,
     221,   221,   222,   222,   223,   223,   224,   224,   224,   224,
     224,   224,   225,   225,   226,   226,   227,   227,   228,   228,
     229,   229,   230,   230,   231,   231,   232,   232,   233,   233,
     234,   235,   235,   236,   236,   236,   237,   237,   237,   238,
     238,   238,   239,   239,   239,   240,   240,   240,   241,   241,
     241,   242,   242,   242,   243,   243,   243,   244,   244,   244,
     245,   246,   247,   247,   247,   248,   248,   248
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     0,     6,     3,     1,     0,     2,     1,     2,     2,
       5,     3,     2,     2,     3,     2,     0,     4,     0,     3,
       0,     3,     2,     1,     3,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     0,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     1,     2,     0,     3,     0,
       1,     1,     2,     5,     4,     2,     0,     2,     1,     1,
       3,     1,     3,     1,     3,     1,     2,     1,     3,     1,
       3,     3,     2,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     0,     5,     2,     1,     2,     1,     1,
       1,     4,     3,     2,     1,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     1,     0,     2,     1,     2,     2,     2,     2,     4,
       3,     3,     3,     2,     2,     3,     1,     4,     1,     0,
       1,     0,     2,     1,     2,     2,     4,     2,     1,     1,
       1,     1,     7,     4,     1,     0,     3,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     1,     1,     5,     4,
       3,     2,     1,     1,     5,     4,     3,     2,     1,     3,
       1,     2,     1,     3,     1,     0,     3,     1,     0,     4,
       1,     0,     3,     1,     0,     5,     1,     0,     3,     1,
       0,     3,     1,     0,     3,     3,     2,     3,     3,     2,
       2,     2,     3,     1,     1,     3,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: file_input  */
#line 56 "punygram.y"
                        { return ENDMARKER; }
#line 1962 "punygram.tab.c"
    break;

  case 3: /* start: single_input  */
#line 57 "punygram.y"
                        { return ENDMARKER; }
#line 1968 "punygram.tab.c"
    break;

  case 4: /* start: encoding_decl  */
#line 58 "punygram.y"
                        { return ENDMARKER; }
#line 1974 "punygram.tab.c"
    break;

  case 9: /* pick_NEWLINE_stmt: stmt  */
#line 72 "punygram.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 1980 "punygram.tab.c"
    break;

  case 10: /* star_NEWLINE_stmt: pick_NEWLINE_stmt star_NEWLINE_stmt  */
#line 76 "punygram.y"
                                              {
                                          if((yyvsp[0].ast)) {
                                            (yyvsp[0].ast) = add_child((yyvsp[0].ast), (yyvsp[-1].ast));
                                            (yyval.ast) = (yyvsp[0].ast);
                                          } else {
                                            (yyval.ast) = (yyvsp[-1].ast);
                                          }
                                        }
#line 1993 "punygram.tab.c"
    break;

  case 19: /* decorated: decorators funcdef  */
#line 104 "punygram.y"
                             {
                   }
#line 2000 "punygram.tab.c"
    break;

  case 20: /* funcdef: DEF NAME parameters COLON suite  */
#line 109 "punygram.y"
                                          {
                                      debug_tree((yyvsp[-2].ast), 5);
                                      (yyvsp[-4].ast) = add_child((yyvsp[-4].ast), (yyvsp[-3].ast));
                                      (yyvsp[-4].ast) = add_child((yyvsp[-4].ast), (yyvsp[-2].ast));
                                      (yyvsp[-4].ast) = add_child((yyvsp[-4].ast), (yyvsp[-1].ast));
                                      (yyval.ast) = (yyvsp[-4].ast);
                                    }
#line 2012 "punygram.tab.c"
    break;

  case 21: /* parameters: LPAR varargslist RPAR  */
#line 119 "punygram.y"
                                {
                            (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                            (yyval.ast) = (yyvsp[-2].ast);
                          }
#line 2021 "punygram.tab.c"
    break;

  case 22: /* parameters: LPAR RPAR  */
#line 123 "punygram.y"
                    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2027 "punygram.tab.c"
    break;

  case 24: /* varargslist: fpdef opt_EQUAL_test star_COMMA_fpdef  */
#line 128 "punygram.y"
                                                { 
                                          if((yyvsp[0].ast)) {
                                            (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[0].ast));
                                            (yyval.ast) = (yyvsp[-2].ast);
                                          } else {
                                            (yyval.ast) = (yyvsp[-2].ast);
                                          }
                                          }
#line 2040 "punygram.tab.c"
    break;

  case 25: /* opt_EQUAL_test: EQUAL test  */
#line 139 "punygram.y"
                     {
                 (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                 (yyval.ast) = (yyvsp[-1].ast);
               }
#line 2049 "punygram.tab.c"
    break;

  case 27: /* star_fpdef_COMMA: fpdef opt_EQUAL_test COMMA star_fpdef_COMMA  */
#line 147 "punygram.y"
                                                      {
                                                }
#line 2056 "punygram.tab.c"
    break;

  case 33: /* fpdef: NAME  */
#line 163 "punygram.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 2062 "punygram.tab.c"
    break;

  case 34: /* fpdef: LPAR fplist RPAR  */
#line 164 "punygram.y"
                           {
                       (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                       (yyval.ast) = (yyvsp[-2].ast);
                     }
#line 2071 "punygram.tab.c"
    break;

  case 35: /* fplist: fpdef star_fpdef_notest  */
#line 171 "punygram.y"
                                  {
                              if((yyvsp[0].ast)) {
                                (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                                (yyval.ast) = (yyvsp[-1].ast);
                              } else {
                                (yyval.ast) = (yyvsp[-1].ast);
                              }
                            }
#line 2084 "punygram.tab.c"
    break;

  case 39: /* small_stmt: expr_stmt  */
#line 191 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2090 "punygram.tab.c"
    break;

  case 40: /* small_stmt: print_stmt  */
#line 192 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2096 "punygram.tab.c"
    break;

  case 41: /* small_stmt: del_stmt  */
#line 193 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2102 "punygram.tab.c"
    break;

  case 42: /* small_stmt: pass_stmt  */
#line 194 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2108 "punygram.tab.c"
    break;

  case 43: /* small_stmt: flow_stmt  */
#line 195 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2114 "punygram.tab.c"
    break;

  case 44: /* small_stmt: import_stmt  */
#line 196 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2120 "punygram.tab.c"
    break;

  case 45: /* small_stmt: global_stmt  */
#line 197 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2126 "punygram.tab.c"
    break;

  case 46: /* small_stmt: exec_stmt  */
#line 198 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2132 "punygram.tab.c"
    break;

  case 47: /* small_stmt: assert_stmt  */
#line 199 "punygram.y"
                      { debug_tree((yyvsp[0].ast), 0); (yyval.ast) = (yyvsp[0].ast); }
#line 2138 "punygram.tab.c"
    break;

  case 49: /* expr_stmt: testlist star_EQUAL  */
#line 204 "punygram.y"
                              {
                          if((yyvsp[0].ast)) {
                            (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                            (yyval.ast) = (yyvsp[-1].ast);
                          } else {
                            (yyval.ast) = (yyvsp[-1].ast);
                          }
                        }
#line 2151 "punygram.tab.c"
    break;

  case 52: /* star_EQUAL: EQUAL pick_yield_expr_testlist star_EQUAL  */
#line 220 "punygram.y"
                                                    {
                                                if((yyvsp[0].ast)) {
                                                  (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                                                  (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[0].ast));
                                                  (yyval.ast) = (yyvsp[-2].ast);
                                                } else {
                                                  (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                                                  (yyval.ast) = (yyvsp[-2].ast);
                                                }
                                              }
#line 2166 "punygram.tab.c"
    break;

  case 53: /* star_EQUAL: %empty  */
#line 230 "punygram.y"
                                                    { (yyval.ast) = NULL; }
#line 2172 "punygram.tab.c"
    break;

  case 54: /* augassign: PLUSEQUAL  */
#line 234 "punygram.y"
                                     { }
#line 2178 "punygram.tab.c"
    break;

  case 55: /* augassign: MINEQUAL  */
#line 235 "punygram.y"
                                     { }
#line 2184 "punygram.tab.c"
    break;

  case 56: /* augassign: STAREQUAL  */
#line 236 "punygram.y"
                                     { }
#line 2190 "punygram.tab.c"
    break;

  case 57: /* augassign: SLASHEQUAL  */
#line 237 "punygram.y"
                                   { }
#line 2196 "punygram.tab.c"
    break;

  case 58: /* augassign: PERCENTEQUAL  */
#line 238 "punygram.y"
                           { }
#line 2202 "punygram.tab.c"
    break;

  case 59: /* augassign: AMPEREQUAL  */
#line 239 "punygram.y"
                                   { }
#line 2208 "punygram.tab.c"
    break;

  case 60: /* augassign: VBAREQUAL  */
#line 240 "punygram.y"
                                     { }
#line 2214 "punygram.tab.c"
    break;

  case 61: /* augassign: CIRCUMFLEXEQUAL  */
#line 241 "punygram.y"
                                 { }
#line 2220 "punygram.tab.c"
    break;

  case 62: /* augassign: LEFTSHIFTEQUAL  */
#line 242 "punygram.y"
                                 { }
#line 2226 "punygram.tab.c"
    break;

  case 63: /* augassign: RIGHTSHIFTEQUAL  */
#line 243 "punygram.y"
                                 { }
#line 2232 "punygram.tab.c"
    break;

  case 64: /* augassign: DOUBLESTAREQUAL  */
#line 244 "punygram.y"
                                 { }
#line 2238 "punygram.tab.c"
    break;

  case 65: /* augassign: DOUBLESLASHEQUAL  */
#line 245 "punygram.y"
                           { }
#line 2244 "punygram.tab.c"
    break;

  case 66: /* print_stmt: PRINT opt_test  */
#line 249 "punygram.y"
                         {
                     (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                     (yyval.ast) = (yyvsp[-1].ast);
                   }
#line 2253 "punygram.tab.c"
    break;

  case 69: /* opt_test: %empty  */
#line 258 "punygram.y"
                 { }
#line 2259 "punygram.tab.c"
    break;

  case 71: /* opt_test_2: %empty  */
#line 263 "punygram.y"
                 { }
#line 2265 "punygram.tab.c"
    break;

  case 92: /* import_name: IMPORT dotted_as_names  */
#line 320 "punygram.y"
                                 { (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast)); }
#line 2271 "punygram.tab.c"
    break;

  case 110: /* dotted_name: dotted_name DOT NAME  */
#line 365 "punygram.y"
                               {
                           (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                           (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[0].ast));
                           (yyval.ast) = (yyvsp[-2].ast);
                         }
#line 2281 "punygram.tab.c"
    break;

  case 117: /* compound_stmt: if_stmt  */
#line 388 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2287 "punygram.tab.c"
    break;

  case 118: /* compound_stmt: while_stmt  */
#line 389 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2293 "punygram.tab.c"
    break;

  case 119: /* compound_stmt: for_stmt  */
#line 390 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2299 "punygram.tab.c"
    break;

  case 120: /* compound_stmt: try_stmt  */
#line 391 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2305 "punygram.tab.c"
    break;

  case 121: /* compound_stmt: with_stmt  */
#line 392 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2311 "punygram.tab.c"
    break;

  case 122: /* compound_stmt: funcdef  */
#line 393 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2317 "punygram.tab.c"
    break;

  case 123: /* compound_stmt: classdef  */
#line 394 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2323 "punygram.tab.c"
    break;

  case 124: /* compound_stmt: decorated  */
#line 395 "punygram.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 2329 "punygram.tab.c"
    break;

  case 153: /* $@1: %empty  */
#line 469 "punygram.y"
                          {  }
#line 2335 "punygram.tab.c"
    break;

  case 155: /* plus_stmt: stmt plus_stmt  */
#line 473 "punygram.y"
                         {
                     (yyval.ast) = (yyvsp[-1].ast);
                     // if($1 != NULL)
                     //       funcStmt->push_back($1);
                     //       else funcStmt->push_back(a);
                     //     }
                   }
#line 2347 "punygram.tab.c"
    break;

  case 156: /* plus_stmt: stmt  */
#line 480 "punygram.y"
                         { 
                     (yyval.ast) = (yyvsp[0].ast);
                     // funcStmt = new std::vector<Ast*>();
                     // if($1 != NULL)
                     // funcStmt->push_back($1);
                     // else funcStmt->push_back(a);
                   }
#line 2359 "punygram.tab.c"
    break;

  case 166: /* opt_IF_ELSE: %empty  */
#line 511 "punygram.y"
                 { }
#line 2365 "punygram.tab.c"
    break;

  case 197: /* arith_expr: arith_expr pick_PLUS_MINUS term  */
#line 575 "punygram.y"
                                          {
                                      (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[-2].ast));
                                      (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                                      (yyval.ast) = (yyvsp[-1].ast);
                                    }
#line 2375 "punygram.tab.c"
    break;

  case 198: /* pick_PLUS_MINUS: PLUS  */
#line 583 "punygram.y"
                {  (yyval.ast) = (yyvsp[0].ast); }
#line 2381 "punygram.tab.c"
    break;

  case 199: /* pick_PLUS_MINUS: MINUS  */
#line 584 "punygram.y"
                {  (yyval.ast) = (yyvsp[0].ast); }
#line 2387 "punygram.tab.c"
    break;

  case 201: /* term: term pick_multop factor  */
#line 590 "punygram.y"
          {
            (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[-2].ast));
            (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
            (yyval.ast) = (yyvsp[-1].ast);
            // if($2 == '*') $$ = new MultNode($2,$1, $3);
            // if($2 == '/') $$ = new DivNode($2,$1, $3);
            // if($2 == '%') $$ = new ModNode($2,$1,$3);
            // if($2 == '!') $$ = new IntDivNode($2,$1, $3);
          }
#line 2401 "punygram.tab.c"
    break;

  case 202: /* pick_multop: STAR  */
#line 602 "punygram.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 2407 "punygram.tab.c"
    break;

  case 203: /* pick_multop: AT  */
#line 603 "punygram.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2413 "punygram.tab.c"
    break;

  case 204: /* pick_multop: SLASH  */
#line 604 "punygram.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 2419 "punygram.tab.c"
    break;

  case 205: /* pick_multop: PERCENT  */
#line 605 "punygram.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 2425 "punygram.tab.c"
    break;

  case 206: /* pick_multop: DOUBLESLASH  */
#line 606 "punygram.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 2431 "punygram.tab.c"
    break;

  case 207: /* factor: pick_unop factor  */
#line 611 "punygram.y"
          {
            (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
            (yyval.ast) = (yyvsp[-1].ast);
            // if(char($1) == '+') $$ = new UPlusNode('P', $2, NULL);
            // if(char($1) == '-') $$ = new UMinusNode('M', $2, NULL);
          }
#line 2442 "punygram.tab.c"
    break;

  case 209: /* pick_unop: PLUS  */
#line 621 "punygram.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2448 "punygram.tab.c"
    break;

  case 210: /* pick_unop: MINUS  */
#line 622 "punygram.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2454 "punygram.tab.c"
    break;

  case 211: /* pick_unop: TILDE  */
#line 623 "punygram.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2460 "punygram.tab.c"
    break;

  case 212: /* power: atom star_trailer DOUBLESTAR factor  */
#line 627 "punygram.y"
                                               { 
                                           (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[-3].ast));
                                           (yyvsp[-1].ast) = add_child((yyvsp[-1].ast), (yyvsp[0].ast));
                                           (yyval.ast) = (yyvsp[-1].ast);
                                         }
#line 2470 "punygram.tab.c"
    break;

  case 213: /* power: atom star_trailer  */
#line 633 "punygram.y"
          {
            (yyval.ast) = (yyvsp[-1].ast);
            // exit(1);
            // if($2 == 'c') {
            //   a = new CallNode('2', $1->getKey());
            //   $$ = new CallNode('2',($1)->getKey());
            //   if(TableManager::getInstance().getCurrScope() == 0)
            //   $$->eval();
            //   delete $$;
            // }
          }
#line 2486 "punygram.tab.c"
    break;

  case 214: /* star_trailer: trailer star_trailer  */
#line 647 "punygram.y"
                               {
                           // $$ = 'c';
                         }
#line 2494 "punygram.tab.c"
    break;

  case 215: /* star_trailer: %empty  */
#line 650 "punygram.y"
                 { }
#line 2500 "punygram.tab.c"
    break;

  case 216: /* atom: LPAR opt_yield_test RPAR  */
#line 654 "punygram.y"
                                   { (yyval.ast) = (yyvsp[-1].ast); }
#line 2506 "punygram.tab.c"
    break;

  case 220: /* atom: NAME  */
#line 658 "punygram.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2512 "punygram.tab.c"
    break;

  case 221: /* atom: NUMBER  */
#line 659 "punygram.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2518 "punygram.tab.c"
    break;

  case 222: /* atom: TRUE  */
#line 660 "punygram.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 2524 "punygram.tab.c"
    break;

  case 223: /* atom: FALSE  */
#line 661 "punygram.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 2530 "punygram.tab.c"
    break;

  case 224: /* atom: plus_STRING  */
#line 662 "punygram.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 2536 "punygram.tab.c"
    break;

  case 228: /* opt_yield_test: %empty  */
#line 672 "punygram.y"
                 { }
#line 2542 "punygram.tab.c"
    break;

  case 234: /* plus_STRING: STRING  */
#line 687 "punygram.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2548 "punygram.tab.c"
    break;

  case 299: /* star_COMMA_fpdef: COMMA fpdef opt_EQUAL_test star_COMMA_fpdef  */
#line 845 "punygram.y"
                                                      {
                                                if((yyvsp[-2].ast)) {
                                                  (yyvsp[-3].ast) = add_child((yyvsp[-3].ast), (yyvsp[-2].ast));
                                                  (yyval.ast) = (yyvsp[-3].ast);
                                                } else {
                                                  (yyval.ast) = (yyvsp[-3].ast);
                                                }
                                                }
#line 2561 "punygram.tab.c"
    break;

  case 302: /* star_COMMA_test: COMMA test star_COMMA_test  */
#line 858 "punygram.y"
                                     {
                                 if((yyvsp[0].ast)) {
                                   (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                                   (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[0].ast));
                                   (yyval.ast) = (yyvsp[-2].ast);
                                 } else {
                                   (yyvsp[-2].ast) = add_child((yyvsp[-2].ast), (yyvsp[-1].ast));
                                   (yyval.ast) = (yyvsp[-2].ast);
                                 }
                               }
#line 2576 "punygram.tab.c"
    break;

  case 304: /* star_COMMA_test: %empty  */
#line 869 "punygram.y"
                 { (yyval.ast) = NULL; }
#line 2582 "punygram.tab.c"
    break;


#line 2586 "punygram.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 922 "punygram.y"


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
