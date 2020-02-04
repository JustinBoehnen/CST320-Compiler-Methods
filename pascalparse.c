/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "pascal.y" /* yacc.c:339  */

//**************************************
// pascal.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"
#include "cSymbolTable.h"

#line 82 "pascalparse.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "pascalparse.h".  */
#ifndef YY_YY_PASCALPARSE_H_INCLUDED
# define YY_YY_PASCALPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    PROCEDURE = 259,
    FUNCTION = 260,
    FORWARD = 261,
    OPEN = 262,
    CLOSE = 263,
    WRITE = 264,
    WHILE = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    REPEAT = 269,
    UNTIL = 270,
    FOR = 271,
    DO = 272,
    TO = 273,
    DOWNTO = 274,
    CONST = 275,
    TYPE = 276,
    VAR = 277,
    RECORD = 278,
    ARRAY = 279,
    OF = 280,
    NIL = 281,
    CHAR = 282,
    INTEGER = 283,
    REAL = 284,
    JUNK_TOKEN = 285,
    IDENTIFIER = 286,
    TYPE_ID = 287,
    CHAR_VAL = 288,
    INT_VAL = 289,
    REAL_VAL = 290,
    AND = 291,
    OR = 292,
    NOT = 293,
    DIV = 294,
    MOD = 295,
    NOT_EQUAL = 296,
    LE = 297,
    GE = 298,
    ASSIGN = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "pascal.y" /* yacc.c:355  */

    int             int_val;
    double          real_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprListNode*  expr_list_node;
    cExprNode*      expr_node;
    cSymbol*        symbol;
    cDeclsNode*     decls_node;
    cDeclNode*      decl_node;
    cIdListNode*    id_list_node;
    cVarDeclsNode*  var_decls_node;
    cBaseTypeNode*  base_type_node;
    cVarExprNode*   var_expr_node;
    

#line 187 "pascalparse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PASCALPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 39 "pascal.y" /* yacc.c:358  */

    int yyerror(const char *msg);

    cAstNode *yyast_root;
    extern cSymbolTable g_symbolTable;

#line 224 "pascalparse.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    58,    57,    50,    54,    45,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    46,
      56,    47,    55,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   122,   126,   129,   138,   141,   142,   144,
     146,   149,   150,   152,   154,   156,   158,   160,   162,   164,
     167,   170,   171,   176,   178,   180,   182,   184,   187,   189,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   210,
     212,   217,   220,   222,   224,   226,   229,   231,   233,   235,
     237,   240,   245,   248,   250,   252,   254,   256,   258,   260,
     262,   264,   266,   268,   270,   272,   275,   280,   283,   284,
     287,   290,   292,   294,   297,   300,   302,   304,   306,   308,
     310,   312,   315,   317,   319,   321,   323,   326,   328,   330,
     332,   334,   336,   339,   341,   343,   345,   347,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "PROCEDURE", "FUNCTION",
  "FORWARD", "OPEN", "CLOSE", "WRITE", "WHILE", "IF", "THEN", "ELSE",
  "REPEAT", "UNTIL", "FOR", "DO", "TO", "DOWNTO", "CONST", "TYPE", "VAR",
  "RECORD", "ARRAY", "OF", "NIL", "CHAR", "INTEGER", "REAL", "JUNK_TOKEN",
  "IDENTIFIER", "TYPE_ID", "CHAR_VAL", "INT_VAL", "REAL_VAL", "AND", "OR",
  "NOT", "DIV", "MOD", "NOT_EQUAL", "LE", "GE", "ASSIGN", "'.'", "';'",
  "'='", "'['", "']'", "','", "':'", "'('", "')'", "'-'", "'>'", "'<'",
  "'+'", "'*'", "'/'", "$accept", "program", "header", "block", "decls",
  "constdecls", "constdecl", "typedecls", "typedecl", "singleType",
  "rangeList", "range", "vardecls", "vardecl", "onevar", "goodvar",
  "procdecls", "procdecl", "procHeader", "funcHeader", "funcProto",
  "paramSpec", "idlist", "parlist", "type", "recHeader", "recorddef",
  "constant", "statements", "statement", "exprList", "oneExpr",
  "func_call", "variable", "varpart", "expr", "addit", "term", "fact", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    46,    59,    61,    91,    93,
      44,    58,    40,    41,    45,    62,    60,    43,    42,    47
};
# endif

#define YYPACT_NINF -149

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-149)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    12,    60,    59,    56,  -149,    65,    62,   150,   142,
    -149,   122,   143,  -149,   185,    22,   171,    64,   175,   156,
     185,   158,   169,   169,   185,   191,   178,    16,   112,  -149,
     131,  -149,   199,   173,   218,  -149,    23,  -149,  -149,   225,
    -149,   217,  -149,   139,   169,   213,  -149,  -149,   174,   169,
     174,  -149,    89,    -8,   102,    41,  -149,    -5,   157,   222,
    -149,  -149,   169,  -149,  -149,   169,   236,   169,  -149,    49,
    -149,   223,  -149,    21,  -149,   224,   111,   128,  -149,    64,
    -149,    92,  -149,   205,   169,  -149,   172,    41,   185,   169,
     169,   169,   169,   169,   169,   174,   174,   174,   174,   174,
     174,   174,   174,   185,   169,   169,   132,   188,  -149,  -149,
     148,  -149,   220,    23,  -149,  -149,  -149,   240,   241,   226,
     243,   244,  -149,   227,   227,   230,  -149,   169,   231,   134,
    -149,  -149,   102,   102,   102,   102,   102,   102,    41,    41,
      41,  -149,  -149,  -149,  -149,  -149,   265,   195,    69,   234,
    -149,  -149,   247,    10,   237,  -149,  -149,  -149,    88,  -149,
    -149,    73,   238,   235,   124,  -149,  -149,  -149,   185,  -149,
     169,   169,  -149,   242,   168,  -149,  -149,  -149,   239,   245,
     251,   130,   -26,   154,   241,   246,   248,  -149,    28,    50,
     250,   263,   247,  -149,  -149,   182,   241,   105,  -149,   252,
     253,  -149,  -149,  -149,   185,   185,   255,   241,  -149,   241,
    -149,   251,   189,  -149,  -149,  -149,  -149,  -149,   254,  -149,
     212,   241,  -149,   241,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     0,    11,
       3,     0,     0,     2,     0,     0,    21,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    52,
       0,    73,     0,     0,    10,    13,     0,    28,    49,     0,
       9,     0,    65,     0,    68,    74,    94,    95,     0,     0,
       0,    97,    96,     0,    81,    85,    92,     0,     0,     0,
      64,    61,    68,     4,    51,     0,     0,    68,    14,     0,
      12,     0,    41,     0,    23,     0,     0,     0,    50,     0,
      63,     0,    67,    69,    68,    98,     0,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    71,
       0,    47,     0,     0,    25,    22,    24,     0,     0,     0,
       0,     0,    27,    39,    39,     0,     8,     0,     0,     0,
      93,    57,    80,    78,    79,    75,    76,    77,    84,    83,
      82,    91,    90,    89,    87,    88,    54,     0,     0,     0,
      53,    72,     0,     0,     0,    40,    46,    26,     7,    35,
      36,     0,     0,     0,     7,    66,    62,    70,     0,    56,
       0,     0,    60,     0,     0,    18,    48,    15,     0,     0,
       0,     0,     0,     7,     0,     0,     0,    55,     0,     0,
       0,     0,     0,    34,    33,     0,     0,     0,    38,     0,
       0,    37,    32,    31,     0,     0,     0,     0,    17,     0,
      45,     0,     0,    30,    29,    58,    59,    19,     0,    44,
       0,     0,    16,     0,    43,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,  -143,  -149,  -149,  -149,  -149,  -149,   256,
    -149,   101,  -149,   183,   -71,  -149,  -149,  -149,  -149,  -149,
    -149,   177,  -148,  -149,  -106,  -149,  -149,   228,   -12,   -27,
      47,   170,  -149,   -14,   249,   -19,   164,   -31,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    12,    16,    34,    35,
     174,   175,    37,    73,    74,    75,    77,   122,   123,   124,
     125,   162,    76,   182,   157,   113,   154,    40,    28,    29,
      81,    82,    51,    52,    31,    83,    54,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    64,   115,    53,    57,    85,    30,   103,    43,    88,
      30,    71,    58,   181,    30,   179,    64,     1,   176,    87,
     197,   186,    71,    32,    71,   -20,   -20,   198,   -20,    30,
      86,    64,   195,    89,    90,    91,    89,    90,    91,    92,
     200,    72,    92,     4,    30,   204,   107,    93,    94,   212,
      93,    94,    72,    33,    72,   141,   142,   143,   144,   145,
       5,   131,    61,   220,   138,   139,   140,   205,    62,    89,
      90,    91,   111,   112,    30,    92,   146,    98,   201,     6,
      99,   100,   115,    93,    94,   147,   148,   170,   171,    30,
     210,    89,    90,    91,   178,   180,    11,    92,    38,   101,
     102,   218,    10,   219,    72,    93,    94,    13,     6,   106,
      89,    90,    91,    19,   110,   224,    92,   225,    39,    20,
      63,    21,    22,    23,    93,    94,    24,   211,    25,   119,
     185,   129,   120,   121,    66,    -5,    72,    67,    26,    95,
      19,   187,   127,    27,     6,   128,    20,    80,    21,    22,
      23,   188,   189,    24,    30,    25,    96,    14,    19,    97,
     199,   117,   118,    15,    20,    26,    21,    22,    23,    17,
      27,    24,   104,    25,     6,    65,    66,   215,   216,    67,
     117,   196,   127,    26,   127,   149,    19,   167,    27,    18,
      30,    30,    20,    36,    21,    22,    23,   151,   127,    24,
      45,    25,    42,    46,    47,    45,    41,    48,    46,    47,
      44,    26,    48,    89,    90,    91,    27,   191,   192,    92,
      69,    49,    59,    50,    60,   130,    49,    93,    94,    89,
      90,    91,   117,   209,   150,    92,    89,    90,    91,   117,
     221,   169,    92,    93,    94,    68,    89,    90,    91,    33,
      93,    94,    92,   132,   133,   134,   135,   136,   137,    78,
      93,    94,   117,   223,    79,    84,   105,   108,   152,   114,
     116,   155,   158,   156,   159,   160,   164,   166,   168,   161,
     172,   173,    72,   177,   183,   193,   184,   190,   207,   217,
      70,   194,   202,   208,   203,   206,   153,   165,   213,   214,
     222,   163,     0,     0,     0,     0,     0,   126,     0,     0,
       0,     0,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      14,    28,    73,    22,    23,    48,    20,    12,    20,    17,
      24,     1,    24,   161,    28,   158,    43,     3,     8,    50,
      46,   164,     1,     1,     1,     4,     5,    53,     7,    43,
      49,    58,   180,    41,    42,    43,    41,    42,    43,    47,
     183,    31,    47,    31,    58,    17,    65,    55,    56,   197,
      55,    56,    31,    31,    31,    98,    99,   100,   101,   102,
       0,    88,    46,   211,    95,    96,    97,    17,    52,    41,
      42,    43,    23,    24,    88,    47,   103,    36,   184,    20,
      39,    40,   153,    55,    56,   104,   105,    18,    19,   103,
     196,    41,    42,    43,     6,    22,    31,    47,    34,    58,
      59,   207,    46,   209,    31,    55,    56,    45,    20,    62,
      41,    42,    43,     1,    67,   221,    47,   223,    54,     7,
       8,     9,    10,    11,    55,    56,    14,    22,    16,     1,
       6,    84,     4,     5,    45,     7,    31,    48,    26,    37,
       1,   168,    50,    31,    20,    53,     7,     8,     9,    10,
      11,   170,   171,    14,   168,    16,    54,     7,     1,    57,
       6,    50,    51,    21,     7,    26,     9,    10,    11,    47,
      31,    14,    15,    16,    20,    44,    45,   204,   205,    48,
      50,    51,    50,    26,    50,    53,     1,    53,    31,    46,
     204,   205,     7,    22,     9,    10,    11,    49,    50,    14,
      31,    16,    46,    34,    35,    31,    31,    38,    34,    35,
      52,    26,    38,    41,    42,    43,    31,    49,    50,    47,
      47,    52,    31,    54,    46,    53,    52,    55,    56,    41,
      42,    43,    50,    51,    46,    47,    41,    42,    43,    50,
      51,    46,    47,    55,    56,    46,    41,    42,    43,    31,
      55,    56,    47,    89,    90,    91,    92,    93,    94,    34,
      55,    56,    50,    51,    47,    52,    44,    31,    48,    46,
      46,    31,    46,    32,    31,    31,    46,    46,    13,    52,
      46,    34,    31,    46,    46,    46,    51,    45,    25,    34,
      34,    46,    46,   192,    46,    45,   113,   127,    46,    46,
      46,   124,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    61,    62,    31,     0,    20,    63,    64,    65,
      46,    31,    66,    45,     7,    21,    67,    47,    46,     1,
       7,     9,    10,    11,    14,    16,    26,    31,    88,    89,
      93,    94,     1,    31,    68,    69,    22,    72,    34,    54,
      87,    31,    46,    88,    52,    31,    34,    35,    38,    52,
      54,    92,    93,    95,    96,    97,    98,    95,    88,    31,
      46,    46,    52,     8,    89,    44,    45,    48,    46,    47,
      69,     1,    31,    73,    74,    75,    82,    76,    34,    47,
       8,    90,    91,    95,    52,    98,    95,    97,    17,    41,
      42,    43,    47,    55,    56,    37,    54,    57,    36,    39,
      40,    58,    59,    12,    15,    44,    90,    95,    31,    94,
      90,    23,    24,    85,    46,    74,    46,    50,    51,     1,
       4,     5,    77,    78,    79,    80,    87,    50,    53,    90,
      53,    89,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    98,    89,    95,    95,    53,
      46,    49,    48,    73,    86,    31,    32,    84,    46,    31,
      31,    52,    81,    81,    46,    91,    46,    53,    13,    46,
      18,    19,    46,    34,    70,    71,     8,    46,     6,    63,
      22,    82,    83,    46,    51,     6,    63,    89,    95,    95,
      45,    49,    50,    46,    46,    82,    51,    46,    53,     6,
      63,    84,    46,    46,    17,    17,    45,    25,    71,    51,
      84,    22,    82,    46,    46,    89,    89,    34,    84,    84,
      82,    51,    46,    51,    84,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    79,    80,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    90,    91,
      92,    93,    93,    93,    94,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     4,     4,     3,     0,     5,     3,
       2,     0,     2,     1,     2,     5,     9,     3,     1,     4,
       2,     0,     2,     1,     2,     2,     3,     2,     0,     5,
       5,     4,     4,     4,     4,     2,     2,     4,     3,     0,
       3,     1,     6,     5,     4,     3,     1,     1,     2,     1,
       2,     2,     1,     4,     4,     6,     5,     4,     8,     8,
       5,     2,     5,     3,     2,     2,     3,     1,     0,     1,
       4,     3,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     3,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 115 "pascal.y" /* yacc.c:1646  */
    { (yyval.program_node) = new cProgramNode((yyvsp[-2].symbol), (yyvsp[-1].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1572 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "pascal.y" /* yacc.c:1646  */
    {  g_symbolTable.IncreaseScope();
                                   (yyval.symbol) = (yyvsp[-1].symbol); 
                                }
#line 1580 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 127 "pascal.y" /* yacc.c:1646  */
    { (yyval.block_node) = new cBlockNode((yyvsp[-3].decls_node), (yyvsp[-1].stmts_node)); }
#line 1586 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "pascal.y" /* yacc.c:1646  */
    { 
                                    if((yyvsp[-3].ast_node) != nullptr || (yyvsp[-2].ast_node) != nullptr
                                    || (yyvsp[-1].var_decls_node) != nullptr || (yyvsp[0].ast_node) != nullptr)
                                    {
                                        (yyval.decls_node) = new cDeclsNode();
                                        (yyval.decls_node)->AddDecls((yyvsp[-1].var_decls_node));
                                    }
                                }
#line 1599 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "pascal.y" /* yacc.c:1646  */
    { }
#line 1605 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "pascal.y" /* yacc.c:1646  */
    { (yyval.ast_node) = nullptr; }
#line 1611 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "pascal.y" /* yacc.c:1646  */
    { }
#line 1617 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "pascal.y" /* yacc.c:1646  */
    { }
#line 1623 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "pascal.y" /* yacc.c:1646  */
    { }
#line 1629 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 149 "pascal.y" /* yacc.c:1646  */
    { (yyval.ast_node) = nullptr; }
#line 1635 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "pascal.y" /* yacc.c:1646  */
    { }
#line 1641 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "pascal.y" /* yacc.c:1646  */
    { }
#line 1647 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 14:
#line 155 "pascal.y" /* yacc.c:1646  */
    {}
#line 1653 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "pascal.y" /* yacc.c:1646  */
    { }
#line 1659 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "pascal.y" /* yacc.c:1646  */
    { }
#line 1665 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "pascal.y" /* yacc.c:1646  */
    { }
#line 1671 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "pascal.y" /* yacc.c:1646  */
    { }
#line 1677 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "pascal.y" /* yacc.c:1646  */
    { }
#line 1683 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 168 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = (yyvsp[0].var_decls_node); }
#line 1689 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = nullptr; }
#line 1695 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "pascal.y" /* yacc.c:1646  */
    {
                                    (yyval.var_decls_node) = (yyvsp[-1].var_decls_node);
                                    (yyval.var_decls_node)->AddVarDecls((yyvsp[0].var_decls_node));
                                }
#line 1704 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 177 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = (yyvsp[0].var_decls_node); }
#line 1710 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 179 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = (yyvsp[-1].var_decls_node); }
#line 1716 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = nullptr; }
#line 1722 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_decls_node) = new cVarDeclsNode((yyvsp[-2].id_list_node), (yyvsp[0].base_type_node)); }
#line 1728 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "pascal.y" /* yacc.c:1646  */
    { }
#line 1734 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "pascal.y" /* yacc.c:1646  */
    { (yyval.ast_node) = nullptr;  }
#line 1740 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 190 "pascal.y" /* yacc.c:1646  */
    { }
#line 1746 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 192 "pascal.y" /* yacc.c:1646  */
    { }
#line 1752 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 194 "pascal.y" /* yacc.c:1646  */
    { }
#line 1758 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "pascal.y" /* yacc.c:1646  */
    { }
#line 1764 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 198 "pascal.y" /* yacc.c:1646  */
    { }
#line 1770 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 200 "pascal.y" /* yacc.c:1646  */
    { }
#line 1776 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 202 "pascal.y" /* yacc.c:1646  */
    { }
#line 1782 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 204 "pascal.y" /* yacc.c:1646  */
    { }
#line 1788 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 206 "pascal.y" /* yacc.c:1646  */
    { }
#line 1794 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 208 "pascal.y" /* yacc.c:1646  */
    { }
#line 1800 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 210 "pascal.y" /* yacc.c:1646  */
    { }
#line 1806 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 213 "pascal.y" /* yacc.c:1646  */
    { 
                                    (yyval.id_list_node) = (yyvsp[-2].id_list_node); 
                                    (yyval.id_list_node)->AddSymbol((yyvsp[0].symbol));
                                }
#line 1815 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 218 "pascal.y" /* yacc.c:1646  */
    { (yyval.id_list_node) = new cIdListNode((yyvsp[0].symbol)); }
#line 1821 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 221 "pascal.y" /* yacc.c:1646  */
    { }
#line 1827 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 223 "pascal.y" /* yacc.c:1646  */
    { }
#line 1833 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 225 "pascal.y" /* yacc.c:1646  */
    { }
#line 1839 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 227 "pascal.y" /* yacc.c:1646  */
    { }
#line 1845 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 230 "pascal.y" /* yacc.c:1646  */
    { (yyval.base_type_node) = (yyvsp[0].symbol)->GetDecl(); }
#line 1851 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 232 "pascal.y" /* yacc.c:1646  */
    { }
#line 1857 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 234 "pascal.y" /* yacc.c:1646  */
    { }
#line 1863 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 236 "pascal.y" /* yacc.c:1646  */
    { }
#line 1869 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 50:
#line 238 "pascal.y" /* yacc.c:1646  */
    { }
#line 1875 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 241 "pascal.y" /* yacc.c:1646  */
    { 
                                  (yyval.stmts_node) = (yyvsp[-1].stmts_node);
                                  (yyval.stmts_node)->AddStmt((yyvsp[0].stmt_node)); 
                                }
#line 1884 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 246 "pascal.y" /* yacc.c:1646  */
    { (yyval.stmts_node) = new cStmtsNode((yyvsp[0].stmt_node)); }
#line 1890 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 249 "pascal.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = new cAssignNode((yyvsp[-3].var_expr_node), (yyvsp[-1].expr_node)); }
#line 1896 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "pascal.y" /* yacc.c:1646  */
    { }
#line 1902 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 55:
#line 253 "pascal.y" /* yacc.c:1646  */
    { }
#line 1908 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 255 "pascal.y" /* yacc.c:1646  */
    { }
#line 1914 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "pascal.y" /* yacc.c:1646  */
    { }
#line 1920 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 259 "pascal.y" /* yacc.c:1646  */
    {}
#line 1926 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 261 "pascal.y" /* yacc.c:1646  */
    {}
#line 1932 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 263 "pascal.y" /* yacc.c:1646  */
    { }
#line 1938 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 61:
#line 265 "pascal.y" /* yacc.c:1646  */
    { }
#line 1944 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 267 "pascal.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = new cWriteNode((yyvsp[-2].expr_list_node)); }
#line 1950 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 269 "pascal.y" /* yacc.c:1646  */
    { }
#line 1956 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 64:
#line 271 "pascal.y" /* yacc.c:1646  */
    { (yyval.stmt_node) = new cNilNode(); }
#line 1962 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 65:
#line 273 "pascal.y" /* yacc.c:1646  */
    { }
#line 1968 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 66:
#line 276 "pascal.y" /* yacc.c:1646  */
    { 
                                  (yyval.expr_list_node) = (yyvsp[-2].expr_list_node);
                                  (yyval.expr_list_node)->AddExpr((yyvsp[0].expr_node)); 
                                }
#line 1977 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_list_node) = new cExprListNode((yyvsp[0].expr_node)); }
#line 1983 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 283 "pascal.y" /* yacc.c:1646  */
    { }
#line 1989 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 285 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1995 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 288 "pascal.y" /* yacc.c:1646  */
    { }
#line 2001 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 291 "pascal.y" /* yacc.c:1646  */
    { }
#line 2007 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 293 "pascal.y" /* yacc.c:1646  */
    { }
#line 2013 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 295 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_expr_node) = (yyvsp[0].var_expr_node); }
#line 2019 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 298 "pascal.y" /* yacc.c:1646  */
    { (yyval.var_expr_node) = new cVarExprNode((yyvsp[0].symbol)); }
#line 2025 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 301 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('='), (yyvsp[0].expr_node)); }
#line 2031 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 303 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('>'), (yyvsp[0].expr_node)); }
#line 2037 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 305 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('<'), (yyvsp[0].expr_node)); }
#line 2043 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 307 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(LE), (yyvsp[0].expr_node)); }
#line 2049 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 309 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(GE), (yyvsp[0].expr_node)); }
#line 2055 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 311 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(NOT_EQUAL), (yyvsp[0].expr_node)); }
#line 2061 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 313 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 2067 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 316 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('+'), (yyvsp[0].expr_node)); }
#line 2073 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 318 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 2079 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 320 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(OR), (yyvsp[0].expr_node)); }
#line 2085 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 322 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 2091 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 324 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cUnaryExprNode('-', (yyvsp[0].expr_node)); }
#line 2097 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 327 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('*'), (yyvsp[0].expr_node)); }
#line 2103 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 329 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('/'), (yyvsp[0].expr_node)); }
#line 2109 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 331 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(MOD), (yyvsp[0].expr_node)); }
#line 2115 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 333 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(DIV), (yyvsp[0].expr_node)); }
#line 2121 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 335 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(AND), (yyvsp[0].expr_node)); }
#line 2127 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 92:
#line 337 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 2133 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 340 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 2139 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 342 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 2145 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 344 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cRealExprNode((yyvsp[0].real_val)); }
#line 2151 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 346 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = (yyvsp[0].var_expr_node); }
#line 2157 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 348 "pascal.y" /* yacc.c:1646  */
    { }
#line 2163 "pascalparse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 350 "pascal.y" /* yacc.c:1646  */
    { (yyval.expr_node) = new cUnaryExprNode(NOT, (yyvsp[0].expr_node)); }
#line 2169 "pascalparse.c" /* yacc.c:1646  */
    break;


#line 2173 "pascalparse.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 352 "pascal.y" /* yacc.c:1906  */


// Function to format error messages
int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
