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
#line 1 "./syntax.y"

#include "tree.h"
#include <stdio.h>

extern int lexical_errs;
extern int syntax_errs;
extern int yylineno;
extern char* yytext;
int yyerr_line=0;
void yyerror(const char *msg);
int yylex();
#define YYDEBUG 1
extern struct node* root;

void yyerror(const char *msg) {
    if(yyerr_line==yylineno)return;
    yyerr_line=yylineno;
    syntax_errs++;
    printf("Error type B at Line %d: %s.\n",yylineno,msg);
}

#line 93 "./syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_STAR = 12,                      /* STAR  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_DOT = 16,                       /* DOT  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_LP = 19,                        /* LP  */
  YYSYMBOL_RP = 20,                        /* RP  */
  YYSYMBOL_LB = 21,                        /* LB  */
  YYSYMBOL_RB = 22,                        /* RB  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_UMINUS = 30,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 36,                /* ExtDecList  */
  YYSYMBOL_Specifier = 37,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 38,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 39,                    /* OptTag  */
  YYSYMBOL_Tag = 40,                       /* Tag  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_StmtList = 46,                  /* StmtList  */
  YYSYMBOL_Stmt = 47,                      /* Stmt  */
  YYSYMBOL_DefList = 48,                   /* DefList  */
  YYSYMBOL_Def = 49,                       /* Def  */
  YYSYMBOL_DecList = 50,                   /* DecList  */
  YYSYMBOL_Dec = 51,                       /* Dec  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   104,   104,   106,   107,   109,   110,   111,   112,   113,
     114,   115,   116,   118,   119,   122,   123,   125,   126,   127,
     129,   130,   132,   135,   136,   138,   139,   141,   142,   144,
     147,   149,   150,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   166,   167,   169,   170,   171,
     173,   174,   176,   177,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   214,   215,   216
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "DOT", "NOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "UMINUS", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,     7,   -44,    13,    21,   -44,    11,    79,   -44,   -44,
      -8,   -44,   -44,    58,    59,   -44,   -44,   -44,     8,    69,
     -44,    84,    30,    74,    14,    49,    -8,    -8,   -44,   -44,
      73,   -44,    91,   102,   -44,   101,   -44,     1,    68,   106,
     105,   -44,   -44,    93,   186,   203,   208,   344,    98,    99,
     -44,    95,    49,   144,   -44,     4,   -44,    91,   100,   114,
     -44,   103,   -44,   344,   117,   -44,    91,   -44,   -44,   181,
     -44,    83,   -44,    83,   107,   160,   356,   225,   230,   -44,
     -44,   -44,   -44,   247,   252,   269,   274,   291,   296,   313,
     318,   121,   335,   109,   -44,   125,   -44,    -8,   -44,   428,
     -44,   -44,    50,   -44,   128,   110,   -44,   -44,   -44,   -44,
     127,   400,   131,   414,   -44,   428,   -44,   461,   -44,    46,
     -44,    46,   -44,    83,   -44,    83,   -44,   454,   -44,   441,
     -44,   140,   370,   -44,   -44,   344,   -44,   -44,   340,   -44,
      60,    60,    60,    60,   -44,   -44,   428,   156,   386,   -44,
     136,   138,   -44,   -44,    60,    60,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    15,    21,     0,     2,     0,     0,    16,    10,
      46,     8,     9,    22,     0,    18,     1,     3,     0,    23,
       6,     0,    13,     0,     0,     0,    46,    46,    11,    12,
       0,     5,     0,     0,     7,     0,    23,    52,     0,    50,
       0,    70,    71,    69,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,    45,     0,    26,     0,     0,    28,
      14,     0,    49,     0,     0,    47,     0,    39,    40,     0,
      82,    63,    83,    64,     0,     0,     0,     0,     0,    30,
      31,    41,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    29,    25,     0,    24,    53,
      48,    51,     0,    66,     0,     0,    80,    81,    62,    35,
       0,     0,     0,     0,    72,    54,    75,    57,    76,    58,
      77,    59,    78,    60,    79,    61,    73,    55,    74,    56,
      68,     0,     0,    19,    27,     0,    84,    85,     0,    65,
       0,     0,     0,     0,    86,    67,    89,     0,    88,    87,
      42,    36,    44,    38,     0,     0,    43,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   161,   176,   146,    -3,   -44,   -44,   -44,   -18,
     -44,    82,   -44,    15,   141,   -40,    29,   -44,   122,   -44,
     -43,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    21,     7,     8,    14,    15,    22,
      23,    58,    59,    50,    51,    52,    25,    26,    38,    39,
      53,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    71,    73,    75,    76,    93,    37,    24,     1,    63,
       2,    -4,     1,     9,    28,    35,    12,     3,    13,    36,
      99,    16,    33,    24,    24,     2,   104,    57,    94,     2,
      10,    10,     3,    29,   111,   113,     3,    32,    34,    95,
     115,   117,   119,   121,   123,   125,   127,   129,    37,   132,
      40,    33,    41,    42,    43,    54,    55,   135,    87,    88,
      44,    40,    91,    41,    42,    43,    45,    92,    46,    64,
     136,    44,    10,   -32,    65,    47,    48,    45,    49,    46,
      18,   -20,    27,    10,    19,    20,    47,    48,    30,    49,
      31,     2,   146,    56,    57,   148,    36,    10,     3,    91,
     150,   151,   152,   153,    92,    61,    40,    62,    41,    42,
      43,    67,    69,    66,   156,   157,    44,    77,    78,    79,
      96,    97,    45,   100,    46,    98,   130,   106,    10,   137,
     139,    47,    48,   133,    49,   138,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    81,    33,   140,   -88,    92,
      82,   142,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   107,   144,   135,   154,    92,   155,    17,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    11,    60,   134,
     108,    92,   102,   149,    41,    42,    43,    70,   101,    41,
      42,    43,    44,    80,     0,     0,     0,    44,    45,     0,
      46,   103,     0,    45,    72,    46,    41,    42,    43,    74,
       0,    41,    42,    43,    44,     0,     0,     0,     0,    44,
      45,     0,    46,     0,     0,    45,   110,    46,    41,    42,
      43,   112,     0,    41,    42,    43,    44,     0,     0,     0,
       0,    44,    45,     0,    46,     0,     0,    45,   114,    46,
      41,    42,    43,   116,     0,    41,    42,    43,    44,     0,
       0,     0,     0,    44,    45,     0,    46,     0,     0,    45,
     118,    46,    41,    42,    43,   120,     0,    41,    42,    43,
      44,     0,     0,     0,     0,    44,    45,     0,    46,     0,
       0,    45,   122,    46,    41,    42,    43,   124,     0,    41,
      42,    43,    44,     0,     0,     0,     0,    44,    45,     0,
      46,     0,     0,    45,   126,    46,    41,    42,    43,   128,
       0,    41,    42,    43,    44,     0,     0,     0,     0,    44,
      45,     0,    46,     0,     0,    45,   131,    46,    41,    42,
      43,   147,     0,    41,    42,    43,    44,    41,    42,    43,
       0,    44,    45,     0,    46,    44,     0,    45,     0,    46,
       0,    45,   109,    46,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,    92,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,    92,   145,   138,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,    92,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
     141,    92,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   143,    92,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,    92,
      84,    85,    86,    87,    88,    89,     0,    91,     0,     0,
       0,     0,    92,    84,    85,    86,    87,    88,     0,     0,
      91,    85,    86,    87,    88,    92,     0,    91,     0,     0,
       0,     0,    92
};

static const yytype_int16 yycheck[] =
{
      40,    44,    45,    46,    47,     1,    24,    10,     1,     8,
      18,     0,     1,     6,     6,     1,     1,    25,     5,     5,
      63,     0,    21,    26,    27,    18,    69,    30,    24,    18,
      23,    23,    25,    18,    77,    78,    25,     7,    23,    57,
      83,    84,    85,    86,    87,    88,    89,    90,    66,    92,
       1,    21,     3,     4,     5,    26,    27,     7,    12,    13,
      11,     1,    16,     3,     4,     5,    17,    21,    19,     1,
      20,    11,    23,    24,     6,    26,    27,    17,    29,    19,
       1,    23,    23,    23,     5,     6,    26,    27,    19,    29,
       6,    18,   135,    20,    97,   138,     5,    23,    25,    16,
     140,   141,   142,   143,    21,     3,     1,     6,     3,     4,
       5,     6,    19,     7,   154,   155,    11,    19,    19,    24,
      20,     7,    17,     6,    19,    22,     5,    20,    23,     1,
      20,    26,    27,    24,    29,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     1,    21,    20,    20,    21,
       6,    20,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     1,    22,     7,    28,    21,    28,     6,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     1,    32,    97,
      20,    21,     1,   138,     3,     4,     5,     1,    66,     3,
       4,     5,    11,    52,    -1,    -1,    -1,    11,    17,    -1,
      19,    20,    -1,    17,     1,    19,     3,     4,     5,     1,
      -1,     3,     4,     5,    11,    -1,    -1,    -1,    -1,    11,
      17,    -1,    19,    -1,    -1,    17,     1,    19,     3,     4,
       5,     1,    -1,     3,     4,     5,    11,    -1,    -1,    -1,
      -1,    11,    17,    -1,    19,    -1,    -1,    17,     1,    19,
       3,     4,     5,     1,    -1,     3,     4,     5,    11,    -1,
      -1,    -1,    -1,    11,    17,    -1,    19,    -1,    -1,    17,
       1,    19,     3,     4,     5,     1,    -1,     3,     4,     5,
      11,    -1,    -1,    -1,    -1,    11,    17,    -1,    19,    -1,
      -1,    17,     1,    19,     3,     4,     5,     1,    -1,     3,
       4,     5,    11,    -1,    -1,    -1,    -1,    11,    17,    -1,
      19,    -1,    -1,    17,     1,    19,     3,     4,     5,     1,
      -1,     3,     4,     5,    11,    -1,    -1,    -1,    -1,    11,
      17,    -1,    19,    -1,    -1,    17,     1,    19,     3,     4,
       5,     1,    -1,     3,     4,     5,    11,     3,     4,     5,
      -1,    11,    17,    -1,    19,    11,    -1,    17,    -1,    19,
      -1,    17,     6,    19,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    21,    22,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    21,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,    21,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    21,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    21,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    21,     9,    10,    11,    12,    13,    -1,    -1,
      16,    10,    11,    12,    13,    21,    -1,    16,    -1,    -1,
      -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    25,    33,    34,    35,    37,    38,     6,
      23,    35,    45,     5,    39,    40,     0,    34,     1,     5,
       6,    36,    41,    42,    37,    48,    49,    23,     6,    45,
      19,     6,     7,    21,    45,     1,     5,    41,    50,    51,
       1,     3,     4,     5,    11,    17,    19,    26,    27,    29,
      45,    46,    47,    52,    48,    48,    20,    37,    43,    44,
      36,     3,     6,     8,     1,     6,     7,     6,    47,    19,
       1,    52,     1,    52,     1,    52,    52,    19,    19,    24,
      46,     1,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    21,     1,    24,    41,    20,     7,    22,    52,
       6,    50,     1,    20,    52,    53,    20,     1,    20,     6,
       1,    52,     1,    52,     1,    52,     1,    52,     1,    52,
       1,    52,     1,    52,     1,    52,     1,    52,     1,    52,
       5,     1,    52,    24,    43,     7,    20,     1,     7,    20,
      20,    20,    20,    20,    22,    22,    52,     1,    52,    53,
      47,    47,    47,    47,    28,    28,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    36,    37,    37,    38,    38,    38,
      39,    39,    40,    41,    41,    42,    42,    43,    43,    44,
      45,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     2,
       2,     3,     3,     1,     3,     1,     1,     5,     2,     6,
       1,     0,     1,     1,     4,     4,     3,     3,     1,     2,
       4,     2,     0,     2,     1,     3,     5,     7,     5,     2,
       2,     2,     5,     7,     5,     2,     0,     3,     4,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     4,     4,     3,     1,     3
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 104 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Program",(yyloc).first_line,1,(yyvsp[0].node));root=(yyval.node); }
#line 1684 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 106 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDefList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1690 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 107 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1696 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 109 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDef",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1702 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 110 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDef",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1708 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 111 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDef",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1714 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error ExtDef  */
#line 112 "./syntax.y"
                                                    {}
#line 1720 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error CompSt  */
#line 113 "./syntax.y"
                                                    { yyerrok; }
#line 1726 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: error SEMI  */
#line 114 "./syntax.y"
                                                    { yyerrok; }
#line 1732 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: Specifier error SEMI  */
#line 115 "./syntax.y"
                                                    { yyerrok; }
#line 1738 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: Specifier error CompSt  */
#line 116 "./syntax.y"
                                                    { yyerrok; }
#line 1744 "./syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec  */
#line 118 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDecList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1750 "./syntax.tab.c"
    break;

  case 14: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 119 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ExtDecList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1756 "./syntax.tab.c"
    break;

  case 15: /* Specifier: TYPE  */
#line 122 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Specifier",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1762 "./syntax.tab.c"
    break;

  case 16: /* Specifier: StructSpecifier  */
#line 123 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Specifier",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1768 "./syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 125 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("StructSpecifier",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1774 "./syntax.tab.c"
    break;

  case 18: /* StructSpecifier: STRUCT Tag  */
#line 126 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("StructSpecifier",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1780 "./syntax.tab.c"
    break;

  case 19: /* StructSpecifier: STRUCT OptTag LC DefList error RC  */
#line 127 "./syntax.y"
                                                    { yyerrok; }
#line 1786 "./syntax.tab.c"
    break;

  case 20: /* OptTag: ID  */
#line 129 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("OptTag",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1792 "./syntax.tab.c"
    break;

  case 21: /* OptTag: %empty  */
#line 130 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1798 "./syntax.tab.c"
    break;

  case 22: /* Tag: ID  */
#line 132 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Tag",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1804 "./syntax.tab.c"
    break;

  case 23: /* VarDec: ID  */
#line 135 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("VarDec",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1810 "./syntax.tab.c"
    break;

  case 24: /* VarDec: VarDec LB INT RB  */
#line 136 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("VarDec",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1816 "./syntax.tab.c"
    break;

  case 25: /* FunDec: ID LP VarList RP  */
#line 138 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("FunDec",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1822 "./syntax.tab.c"
    break;

  case 26: /* FunDec: ID LP RP  */
#line 139 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("FunDec",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1828 "./syntax.tab.c"
    break;

  case 27: /* VarList: ParamDec COMMA VarList  */
#line 141 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("VarList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1834 "./syntax.tab.c"
    break;

  case 28: /* VarList: ParamDec  */
#line 142 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("VarList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1840 "./syntax.tab.c"
    break;

  case 29: /* ParamDec: Specifier VarDec  */
#line 144 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("ParamDec",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1846 "./syntax.tab.c"
    break;

  case 30: /* CompSt: LC DefList StmtList RC  */
#line 147 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("CompSt",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1852 "./syntax.tab.c"
    break;

  case 31: /* StmtList: Stmt StmtList  */
#line 149 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("StmtList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1858 "./syntax.tab.c"
    break;

  case 32: /* StmtList: %empty  */
#line 150 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1864 "./syntax.tab.c"
    break;

  case 33: /* Stmt: Exp SEMI  */
#line 152 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1870 "./syntax.tab.c"
    break;

  case 34: /* Stmt: CompSt  */
#line 153 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1876 "./syntax.tab.c"
    break;

  case 35: /* Stmt: RETURN Exp SEMI  */
#line 154 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1882 "./syntax.tab.c"
    break;

  case 36: /* Stmt: IF LP Exp RP Stmt  */
#line 155 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1888 "./syntax.tab.c"
    break;

  case 37: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 156 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1894 "./syntax.tab.c"
    break;

  case 38: /* Stmt: WHILE LP Exp RP Stmt  */
#line 157 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Stmt",(yyloc).first_line,5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1900 "./syntax.tab.c"
    break;

  case 39: /* Stmt: error SEMI  */
#line 158 "./syntax.y"
                                                    { yyerrok; }
#line 1906 "./syntax.tab.c"
    break;

  case 40: /* Stmt: error Stmt  */
#line 159 "./syntax.y"
                                                    { yyerrok; }
#line 1912 "./syntax.tab.c"
    break;

  case 41: /* Stmt: Exp error  */
#line 160 "./syntax.y"
                                                    {}
#line 1918 "./syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP error RP Stmt  */
#line 161 "./syntax.y"
                                                    {}
#line 1924 "./syntax.tab.c"
    break;

  case 43: /* Stmt: IF LP error RP Stmt ELSE Stmt  */
#line 162 "./syntax.y"
                                                    {}
#line 1930 "./syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP error RP Stmt  */
#line 163 "./syntax.y"
                                                    { yyerrok; }
#line 1936 "./syntax.tab.c"
    break;

  case 45: /* DefList: Def DefList  */
#line 166 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("DefList",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1942 "./syntax.tab.c"
    break;

  case 46: /* DefList: %empty  */
#line 167 "./syntax.y"
                                                    { (yyval.node)=NULL; }
#line 1948 "./syntax.tab.c"
    break;

  case 47: /* Def: Specifier DecList SEMI  */
#line 169 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Def",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1954 "./syntax.tab.c"
    break;

  case 48: /* Def: Specifier DecList error SEMI  */
#line 170 "./syntax.y"
                                                    { yyerrok; }
#line 1960 "./syntax.tab.c"
    break;

  case 49: /* Def: Specifier error SEMI  */
#line 171 "./syntax.y"
                                                    { yyerrok; }
#line 1966 "./syntax.tab.c"
    break;

  case 50: /* DecList: Dec  */
#line 173 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("DecList",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1972 "./syntax.tab.c"
    break;

  case 51: /* DecList: Dec COMMA DecList  */
#line 174 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("DecList",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1978 "./syntax.tab.c"
    break;

  case 52: /* Dec: VarDec  */
#line 176 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Dec",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 1984 "./syntax.tab.c"
    break;

  case 53: /* Dec: VarDec ASSIGNOP Exp  */
#line 177 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Dec",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1990 "./syntax.tab.c"
    break;

  case 54: /* Exp: Exp ASSIGNOP Exp  */
#line 180 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1996 "./syntax.tab.c"
    break;

  case 55: /* Exp: Exp AND Exp  */
#line 181 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2002 "./syntax.tab.c"
    break;

  case 56: /* Exp: Exp OR Exp  */
#line 182 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2008 "./syntax.tab.c"
    break;

  case 57: /* Exp: Exp RELOP Exp  */
#line 183 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2014 "./syntax.tab.c"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 184 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2020 "./syntax.tab.c"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 185 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2026 "./syntax.tab.c"
    break;

  case 60: /* Exp: Exp STAR Exp  */
#line 186 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2032 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 187 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2038 "./syntax.tab.c"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 188 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2044 "./syntax.tab.c"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 189 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2050 "./syntax.tab.c"
    break;

  case 64: /* Exp: NOT Exp  */
#line 190 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2056 "./syntax.tab.c"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 191 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2062 "./syntax.tab.c"
    break;

  case 66: /* Exp: ID LP RP  */
#line 192 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2068 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 193 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2074 "./syntax.tab.c"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 194 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2080 "./syntax.tab.c"
    break;

  case 69: /* Exp: ID  */
#line 195 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2086 "./syntax.tab.c"
    break;

  case 70: /* Exp: INT  */
#line 196 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2092 "./syntax.tab.c"
    break;

  case 71: /* Exp: FLOAT  */
#line 197 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Exp",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2098 "./syntax.tab.c"
    break;

  case 72: /* Exp: Exp ASSIGNOP error  */
#line 198 "./syntax.y"
                                                    {}
#line 2104 "./syntax.tab.c"
    break;

  case 73: /* Exp: Exp AND error  */
#line 199 "./syntax.y"
                                                    {}
#line 2110 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp OR error  */
#line 200 "./syntax.y"
                                                    {}
#line 2116 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp RELOP error  */
#line 201 "./syntax.y"
                                                    {}
#line 2122 "./syntax.tab.c"
    break;

  case 76: /* Exp: Exp PLUS error  */
#line 202 "./syntax.y"
                                                    {}
#line 2128 "./syntax.tab.c"
    break;

  case 77: /* Exp: Exp MINUS error  */
#line 203 "./syntax.y"
                                                    {}
#line 2134 "./syntax.tab.c"
    break;

  case 78: /* Exp: Exp STAR error  */
#line 204 "./syntax.y"
                                                    {}
#line 2140 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp DIV error  */
#line 205 "./syntax.y"
                                                    {}
#line 2146 "./syntax.tab.c"
    break;

  case 80: /* Exp: LP error RP  */
#line 206 "./syntax.y"
                                                    { yyerrok; }
#line 2152 "./syntax.tab.c"
    break;

  case 81: /* Exp: LP Exp error  */
#line 207 "./syntax.y"
                                                    {}
#line 2158 "./syntax.tab.c"
    break;

  case 82: /* Exp: MINUS error  */
#line 208 "./syntax.y"
                                                    {}
#line 2164 "./syntax.tab.c"
    break;

  case 83: /* Exp: NOT error  */
#line 209 "./syntax.y"
                                                    {}
#line 2170 "./syntax.tab.c"
    break;

  case 84: /* Exp: ID LP error RP  */
#line 210 "./syntax.y"
                                                    { yyerrok; }
#line 2176 "./syntax.tab.c"
    break;

  case 85: /* Exp: ID LP Exp error  */
#line 211 "./syntax.y"
                                                    {}
#line 2182 "./syntax.tab.c"
    break;

  case 86: /* Exp: Exp LB error RB  */
#line 212 "./syntax.y"
                                                    { yyerrok; }
#line 2188 "./syntax.tab.c"
    break;

  case 87: /* Args: Exp COMMA Args  */
#line 214 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Args",(yyloc).first_line,3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); }
#line 2194 "./syntax.tab.c"
    break;

  case 88: /* Args: Exp  */
#line 215 "./syntax.y"
                                                    { (yyval.node)=nonterminal_node("Args",(yyloc).first_line,1,(yyvsp[0].node)); }
#line 2200 "./syntax.tab.c"
    break;

  case 89: /* Args: error COMMA Exp  */
#line 216 "./syntax.y"
                                                    {}
#line 2206 "./syntax.tab.c"
    break;


#line 2210 "./syntax.tab.c"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 218 "./syntax.y"

#include "lex.yy.c"
