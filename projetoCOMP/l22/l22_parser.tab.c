/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "l22_parser.y"

//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!

#line 84 "l22_parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_L22_PARSER_TAB_H_INCLUDED
# define YY_YY_L22_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tINTEGER = 258,
    tREAL = 259,
    tID = 260,
    tSTRING = 261,
    tPUBLIC = 262,
    tUSE = 263,
    tFOREIGN = 264,
    tWRITE = 265,
    tWRITELN = 266,
    tPRIVATE = 267,
    tWITH = 268,
    tUPDATE = 269,
    tTO = 270,
    tITERATE = 271,
    tCOUNT = 272,
    tWHILE = 273,
    tPRINT = 274,
    tREAD = 275,
    tBEGIN = 276,
    tEND = 277,
    tNOT = 278,
    tDO = 279,
    tAGAIN = 280,
    tSTOP = 281,
    tRETURN = 282,
    tNULLPTR = 283,
    tINPUT = 284,
    tSIZEOF = 285,
    tSTRING_TYPE = 286,
    tINT_TYPE = 287,
    tREAL_TYPE = 288,
    tVOID = 289,
    tVAR = 290,
    tUNARY = 291,
    tIF = 292,
    tTHEN = 293,
    tELIF = 294,
    tELSE = 295,
    tGE = 296,
    tLE = 297,
    tEQ = 298,
    tNE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "l22_parser.y"

  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;    /* Real Value*/
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  l22::block_node      *block;
  std::vector<std::shared_ptr<cdk::basic_type>> *type_vector;
  

#line 203 "l22_parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::shared_ptr<cdk::compiler> compiler);

#endif /* !YY_YY_L22_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 71 "l22_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 223 "l22_parser.tab.c"


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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   769

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    55,    43,     2,
      41,    60,    53,    51,    57,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    56,
      50,    42,    49,    65,    64,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    44,    59,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    45,    46,    47,    48,
      61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    77,    78,    79,    82,    85,    86,    87,
      88,    97,    98,   101,   102,   103,   104,   105,   106,   107,
     113,   114,   117,   118,   125,   126,   127,   131,   132,   133,
     136,   137,   138,   139,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   160,   161,   164,
     165,   166,   167,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     189,   190,   191,   192,   193,   195,   196,   197,   200,   201,
     206,   207,   210,   211,   216,   217,   220,   221,   222,   223,
     224,   225,   226,   230,   231,   232,   233
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINTEGER", "tREAL", "tID", "tSTRING",
  "tPUBLIC", "tUSE", "tFOREIGN", "tWRITE", "tWRITELN", "tPRIVATE", "tWITH",
  "tUPDATE", "tTO", "tITERATE", "tCOUNT", "tWHILE", "tPRINT", "tREAD",
  "tBEGIN", "tEND", "tNOT", "tDO", "tAGAIN", "tSTOP", "tRETURN",
  "tNULLPTR", "tINPUT", "tSIZEOF", "tSTRING_TYPE", "tINT_TYPE",
  "tREAL_TYPE", "tVOID", "tVAR", "tUNARY", "tIF", "tTHEN", "tELIF",
  "tELSE", "'('", "'='", "'&'", "'|'", "tGE", "tLE", "tEQ", "tNE", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','", "'{'", "'}'",
  "')'", "\":\"", "'['", "']'", "'@'", "'?'", "':'", "$accept", "file",
  "program", "declarations", "opt_initializer", "vardecl", "variable",
  "variables", "block", "elif", "instructions", "instruction", "lval",
  "expr", "exprs", "opt_exprs", "function_type", "data_type", "integer",
  "real", "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    40,    61,    38,   124,   296,   297,   298,   299,    62,
      60,    43,    45,    42,    47,    37,    59,    44,   123,   125,
      41,   300,    91,    93,    64,    63,    58
};
# endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      98,    11,    52,    52,   -36,   -55,   -55,   -55,   -55,    29,
      52,    40,   -55,    98,     6,    -1,    13,    82,     2,     7,
       8,   256,    87,    68,   -42,   -55,   -55,    65,   -55,    80,
     -14,   429,    83,    80,   -55,   -55,   -55,   -55,   -55,   -55,
     429,   429,   429,   429,    86,   429,   -55,   -55,   429,   -55,
     -55,    93,   106,   389,   429,   429,   112,   107,   194,   -55,
     299,    72,   -33,   690,   -55,   -55,   118,   -55,   429,   -55,
     -55,   429,   -55,   -55,   -16,    99,   429,   703,   429,   -55,
     690,    94,    94,   468,   507,   429,   690,   690,   429,   429,
     145,   100,   -55,    63,   583,    10,   690,   690,   522,   429,
     -55,   349,   -55,   103,   -55,   429,   429,   -55,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   -55,   703,   703,   -55,    52,   703,   429,   429,
     429,   601,   619,   637,   -55,   105,    46,   104,   -55,   -55,
     -55,    94,    95,   -55,   -55,   703,   543,   101,   714,   714,
      12,    12,    12,    12,    12,    12,    84,    84,   -55,   -55,
     -55,    99,   690,   564,   451,   138,   -55,   127,    52,   -55,
     117,   -55,   -55,   -55,   429,   429,   -36,   -36,   -39,    52,
     492,   675,   -55,    30,   -36,    24,   429,   429,   126,   -36,
     -55,   -55,   -36,   690,   690,   429,   -55,   -55,   655,   133,
     -36,    30,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     0,    86,    87,    88,    89,     0,
       0,     0,     4,     3,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     5,     9,     7,    11,
       0,     0,     0,    11,    16,    17,    93,    94,    47,    95,
       0,     0,     0,     0,     0,     0,    37,    38,    39,    52,
      70,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    30,    75,    34,    49,    50,    51,     6,     0,    90,
      10,     0,    19,    91,     0,    84,     0,    13,     0,    14,
      80,    35,    36,     0,     0,     0,    62,    40,     0,     0,
       0,     0,    22,     0,     0,     0,    54,    53,     0,    82,
      26,     0,    25,    32,    31,     0,     0,    77,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    18,    12,    92,     0,    15,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    69,    21,
      73,    83,     0,    24,    33,    76,     0,     0,    67,    68,
      63,    64,    66,    65,    61,    60,    55,    56,    57,    58,
      59,    85,    81,     0,     0,     0,    74,     0,     0,    23,
       0,    72,    48,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    41,     0,     0,     0,     0,     0,     0,
      42,    79,     0,    45,    46,     0,    27,    78,     0,     0,
       0,    28,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   162,   156,   148,    -8,    47,   -55,    -4,   -19,
     128,   -54,   -55,   -17,    35,    76,   -55,     0,   -55,   -55,
     -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    72,    14,    92,    93,    59,   190,
      60,    61,    62,    63,   141,   142,    74,    15,    64,    65,
      66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    18,    19,    20,    29,    27,   103,    33,    30,   105,
      24,    30,    34,    35,    77,   139,    16,     5,     6,     7,
       8,    69,    21,    80,    80,    83,    84,   184,    86,   106,
      75,    87,   107,   125,    23,    73,    94,    96,    97,    98,
      25,   126,     5,     6,     7,     8,    17,   103,    10,    30,
      27,   123,    30,    95,   124,    31,    24,    30,    30,    98,
      30,   127,    28,   117,   118,   119,   120,   121,   131,   188,
     189,   132,   133,    10,    30,    81,    82,     5,     6,     7,
       8,    90,    80,     5,     6,     7,     8,    32,   145,   146,
     192,    80,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     1,     2,     3,    10,    67,
      68,   162,   163,   164,    10,    36,    37,    38,    39,     4,
     136,    70,    71,   137,   122,    78,   161,    85,   104,     5,
       6,     7,     8,     9,    88,    45,    95,   119,   120,   121,
      49,    50,    51,     5,     6,     7,     8,    89,    99,    30,
     134,   128,   135,    53,   168,   171,   170,   180,   181,   144,
      10,   173,   176,    54,    55,   177,   179,   195,   178,   193,
     194,   200,   182,   183,    56,    26,    57,    58,   198,   185,
     191,    79,   202,   169,   147,   196,   101,     0,   197,     0,
       0,     0,     0,     0,     0,     0,   201,    36,    37,    38,
      39,     1,     2,     3,    40,    41,     0,    42,     0,     0,
      43,     0,    44,     0,     0,     0,     0,    45,     0,    46,
      47,    48,    49,    50,    51,     5,     6,     7,     8,     9,
       0,    52,     0,     0,     0,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    55,     0,     0,     0,
       0,     0,    21,   100,     0,     0,    56,     0,    57,    36,
      37,    38,    39,     1,     2,     3,    40,    41,     0,    42,
       0,     0,    43,     0,    44,     0,     0,     0,     0,    45,
       0,    46,    47,    48,    49,    50,    51,     5,     6,     7,
       8,     9,     0,    52,     0,     0,     0,    53,     0,     0,
       0,     0,    36,    37,    38,    39,     0,    54,    55,    40,
      41,     0,    42,     0,    21,    43,     0,    44,    56,     0,
      57,     0,    45,     0,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,    36,    37,    38,    39,     0,    21,   102,    40,
      41,    76,    42,    57,     0,    43,     0,    44,     0,     0,
       0,     0,    45,     0,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      53,     0,    36,    37,    38,    39,     0,     0,     0,     0,
      54,    55,     0,     0,     0,     0,     0,    21,   143,     0,
       0,    76,    45,    57,     0,     0,     0,    49,    50,    51,
       5,     6,     7,     8,    90,     0,     0,     0,     0,     0,
      53,     0,    36,    37,    38,    39,     0,     0,     0,     0,
      54,    55,     0,     0,     0,     0,     0,     0,     0,    91,
       0,    56,    45,    57,     0,     0,     0,    49,    50,    51,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    55,   129,     0,     0,     0,     0,     0,     0,     0,
       0,    76,   108,    57,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   186,     0,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   130,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   108,     0,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   108,     0,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,   108,   140,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,     0,     0,     0,   108,   172,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,     0,   108,   174,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     0,
       0,     0,   108,   138,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
     108,   165,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,   108,   166,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,   108,   167,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,   187,     0,     0,   199,   108,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   108,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
       4,     1,     2,     3,     5,    13,    60,     5,    50,    42,
      10,    50,     5,     5,    31,     5,     5,    31,    32,    33,
      34,    63,    58,    40,    41,    42,    43,    66,    45,    62,
      30,    48,    65,    49,     5,    49,    53,    54,    55,    56,
       0,    57,    31,    32,    33,    34,    35,   101,    62,    50,
      58,    68,    50,    53,    71,    42,    56,    50,    50,    76,
      50,    78,    56,    51,    52,    53,    54,    55,    85,    39,
      40,    88,    89,    62,    50,    40,    41,    31,    32,    33,
      34,    35,    99,    31,    32,    33,    34,     5,   105,   106,
      66,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     7,     8,     9,    62,    22,
      42,   128,   129,   130,    62,     3,     4,     5,     6,    21,
      57,    56,    42,    60,     6,    42,   126,    41,    56,    31,
      32,    33,    34,    35,    41,    23,   136,    53,    54,    55,
      28,    29,    30,    31,    32,    33,    34,    41,    41,    50,
       5,    57,    52,    41,    49,    60,    52,   174,   175,    56,
      62,    60,    24,    51,    52,    38,    49,    41,   168,   186,
     187,    38,   176,   177,    62,    13,    64,    21,   195,   179,
     184,    33,   201,   136,   108,   189,    58,    -1,   192,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   200,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      16,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    -1,    64,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    13,
      -1,    -1,    16,    -1,    18,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,    51,    52,    10,
      11,    -1,    13,    -1,    58,    16,    -1,    18,    62,    -1,
      64,    -1,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,     3,     4,     5,     6,    -1,    58,    59,    10,
      11,    62,    13,    64,    -1,    16,    -1,    18,    -1,    -1,
      -1,    -1,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    59,    -1,
      -1,    62,    23,    64,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      41,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    23,    64,    -1,    -1,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    41,    64,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    15,    -1,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    63,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    63,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    41,    61,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    41,    60,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      41,    60,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    41,    60,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    41,    60,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    37,    -1,    -1,    60,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    21,    31,    32,    33,    34,    35,
      62,    68,    69,    70,    72,    84,     5,    35,    84,    84,
      84,    58,    75,     5,    84,     0,    69,    72,    56,     5,
      50,    42,     5,     5,     5,     5,     3,     4,     5,     6,
      10,    11,    13,    16,    18,    23,    25,    26,    27,    28,
      29,    30,    37,    41,    51,    52,    62,    64,    70,    75,
      77,    78,    79,    80,    85,    86,    87,    22,    42,    63,
      56,    42,    71,    49,    83,    84,    62,    80,    42,    71,
      80,    81,    81,    80,    80,    41,    80,    80,    41,    41,
      35,    60,    73,    74,    80,    84,    80,    80,    80,    41,
      59,    77,    59,    78,    56,    42,    62,    65,    41,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     6,    80,    80,    49,    57,    80,    57,    14,
      17,    80,    80,    80,     5,    52,    57,    60,    60,     5,
      63,    81,    82,    59,    56,    80,    80,    82,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    84,    80,    80,    80,    60,    60,    60,    49,    73,
      52,    60,    63,    60,    61,    13,    24,    38,    84,    49,
      80,    80,    75,    75,    66,    84,    15,    37,    39,    40,
      76,    75,    66,    80,    80,    41,    75,    75,    80,    60,
      38,    75,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    69,    70,    70,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     3,     2,     1,     2,
       3,     0,     2,     4,     4,     5,     3,     3,     4,     3,
       2,     2,     1,     3,     4,     3,     3,     2,     6,     7,
       1,     2,     2,     3,     1,     2,     2,     1,     1,     1,
       2,     6,     7,     6,     1,     8,     8,     1,     4,     1,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       1,     4,     4,     3,     4,     1,     3,     2,     8,     7,
       1,     3,     0,     1,     1,     3,     1,     1,     1,     1,
       3,     3,     4,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (compiler);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, compiler);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::shared_ptr<cdk::compiler> compiler)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYUSE (yyvaluep);
  YYUSE (compiler);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 76 "l22_parser.y"
                                    { compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1638 "l22_parser.tab.c"
    break;

  case 3:
#line 77 "l22_parser.y"
                                    { compiler->ast((yyvsp[0].sequence)); }
#line 1644 "l22_parser.tab.c"
    break;

  case 4:
#line 78 "l22_parser.y"
                                    { compiler->ast((yyvsp[0].node)); }
#line 1650 "l22_parser.tab.c"
    break;

  case 5:
#line 79 "l22_parser.y"
                                    { compiler->ast(new cdk::sequence_node(LINE,(yyvsp[0].node),(yyvsp[-1].sequence)));}
#line 1656 "l22_parser.tab.c"
    break;

  case 6:
#line 82 "l22_parser.y"
                            { (yyval.node) = new l22::program_node(LINE, (yyvsp[-1].block)); }
#line 1662 "l22_parser.tab.c"
    break;

  case 7:
#line 85 "l22_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1668 "l22_parser.tab.c"
    break;

  case 8:
#line 86 "l22_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1674 "l22_parser.tab.c"
    break;

  case 9:
#line 87 "l22_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1680 "l22_parser.tab.c"
    break;

  case 10:
#line 88 "l22_parser.y"
                                           { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1686 "l22_parser.tab.c"
    break;

  case 11:
#line 97 "l22_parser.y"
                                       { (yyval.expression) = nullptr; /* must be nullptr, not NIL */ }
#line 1692 "l22_parser.tab.c"
    break;

  case 12:
#line 98 "l22_parser.y"
                                       { (yyval.expression) = (yyvsp[0].expression); }
#line 1698 "l22_parser.tab.c"
    break;

  case 13:
#line 101 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s); }
#line 1704 "l22_parser.tab.c"
    break;

  case 14:
#line 102 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC,  (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); delete (yyvsp[-1].s);}
#line 1710 "l22_parser.tab.c"
    break;

  case 15:
#line 103 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tPUBLIC,  cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s); }
#line 1716 "l22_parser.tab.c"
    break;

  case 16:
#line 104 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tUSE,  (yyvsp[-1].type), *(yyvsp[0].s),nullptr); delete (yyvsp[0].s);}
#line 1722 "l22_parser.tab.c"
    break;

  case 17:
#line 105 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tFOREIGN,  (yyvsp[-1].type), *(yyvsp[0].s),nullptr);delete (yyvsp[0].s); }
#line 1728 "l22_parser.tab.c"
    break;

  case 18:
#line 106 "l22_parser.y"
                                                            { (yyval.node) =  new l22::variable_declaration_node(LINE, tPRIVATE, cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *(yyvsp[-2].s), (yyvsp[0].expression)); delete (yyvsp[-2].s);}
#line 1734 "l22_parser.tab.c"
    break;

  case 19:
#line 107 "l22_parser.y"
                                                            { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression));delete (yyvsp[-1].s); }
#line 1740 "l22_parser.tab.c"
    break;

  case 20:
#line 113 "l22_parser.y"
                              { (yyval.node) =  new l22::variable_declaration_node(LINE, tPRIVATE, cdk::primitive_type::create(4, cdk::TYPE_UNSPEC), *(yyvsp[0].s), nullptr);delete (yyvsp[0].s);}
#line 1746 "l22_parser.tab.c"
    break;

  case 21:
#line 114 "l22_parser.y"
                              { (yyval.node) = new l22::variable_declaration_node(LINE, tPRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); delete (yyvsp[0].s); }
#line 1752 "l22_parser.tab.c"
    break;

  case 22:
#line 117 "l22_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));}
#line 1758 "l22_parser.tab.c"
    break;

  case 23:
#line 118 "l22_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1764 "l22_parser.tab.c"
    break;

  case 24:
#line 125 "l22_parser.y"
                                               { (yyval.block) = new l22::block_node(LINE, (yyvsp[-2].sequence), (yyvsp[-1].sequence)); }
#line 1770 "l22_parser.tab.c"
    break;

  case 25:
#line 126 "l22_parser.y"
                                              { (yyval.block) = new l22::block_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1776 "l22_parser.tab.c"
    break;

  case 26:
#line 127 "l22_parser.y"
                                              { (yyval.block) = new l22::block_node(LINE, (yyvsp[-1].sequence), nullptr); }
#line 1782 "l22_parser.tab.c"
    break;

  case 27:
#line 131 "l22_parser.y"
                                                 { (yyval.node) = (yyvsp[0].block); }
#line 1788 "l22_parser.tab.c"
    break;

  case 28:
#line 132 "l22_parser.y"
                                                 { (yyval.node) = new l22::if_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1794 "l22_parser.tab.c"
    break;

  case 29:
#line 133 "l22_parser.y"
                                                 { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block),(yyvsp[0].node)); }
#line 1800 "l22_parser.tab.c"
    break;

  case 30:
#line 136 "l22_parser.y"
                                         { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node));     }
#line 1806 "l22_parser.tab.c"
    break;

  case 31:
#line 137 "l22_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node));     }
#line 1812 "l22_parser.tab.c"
    break;

  case 32:
#line 138 "l22_parser.y"
                                            { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence));}
#line 1818 "l22_parser.tab.c"
    break;

  case 33:
#line 139 "l22_parser.y"
                                               { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence));}
#line 1824 "l22_parser.tab.c"
    break;

  case 34:
#line 144 "l22_parser.y"
                                                       { (yyval.node) = new l22::evaluation_node(LINE, (yyvsp[0].expression)); }
#line 1830 "l22_parser.tab.c"
    break;

  case 35:
#line 145 "l22_parser.y"
                                                       { (yyval.node) = new l22::print_node(LINE, (yyvsp[0].sequence), false); }
#line 1836 "l22_parser.tab.c"
    break;

  case 36:
#line 146 "l22_parser.y"
                                                       { (yyval.node) = new l22::print_node(LINE, (yyvsp[0].sequence), true); }
#line 1842 "l22_parser.tab.c"
    break;

  case 37:
#line 147 "l22_parser.y"
                                                       { (yyval.node) = new l22::again_node(LINE); }
#line 1848 "l22_parser.tab.c"
    break;

  case 38:
#line 148 "l22_parser.y"
                                                       { (yyval.node) = new l22::stop_node(LINE);  }
#line 1854 "l22_parser.tab.c"
    break;

  case 39:
#line 149 "l22_parser.y"
                                                       { (yyval.node) = new l22::return_node(LINE, nullptr); }
#line 1860 "l22_parser.tab.c"
    break;

  case 40:
#line 150 "l22_parser.y"
                                                       { (yyval.node) = new l22::return_node(LINE, (yyvsp[0].expression));}
#line 1866 "l22_parser.tab.c"
    break;

  case 41:
#line 151 "l22_parser.y"
                                                       { (yyval.node) = new l22::if_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1872 "l22_parser.tab.c"
    break;

  case 42:
#line 152 "l22_parser.y"
                                                        { (yyval.node) = new l22::if_else_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].block),(yyvsp[0].node)); }
#line 1878 "l22_parser.tab.c"
    break;

  case 43:
#line 153 "l22_parser.y"
                                                        { (yyval.node) = new l22::while_node(LINE, (yyvsp[-3].expression), (yyvsp[0].block)); }
#line 1884 "l22_parser.tab.c"
    break;

  case 44:
#line 154 "l22_parser.y"
                                                        { (yyval.node) = (yyvsp[0].block);}
#line 1890 "l22_parser.tab.c"
    break;

  case 45:
#line 155 "l22_parser.y"
                                                           { (yyval.node) = new l22::with_vector_update_node(LINE, (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1896 "l22_parser.tab.c"
    break;

  case 46:
#line 156 "l22_parser.y"
                                                               {(yyval.node) = new l22::iterate_node(LINE, (yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression));}
#line 1902 "l22_parser.tab.c"
    break;

  case 47:
#line 160 "l22_parser.y"
                          { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1908 "l22_parser.tab.c"
    break;

  case 48:
#line 161 "l22_parser.y"
                          { (yyval.lvalue) = new l22::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 1914 "l22_parser.tab.c"
    break;

  case 49:
#line 164 "l22_parser.y"
                                     { (yyval.expression) = (yyvsp[0].expression); }
#line 1920 "l22_parser.tab.c"
    break;

  case 50:
#line 165 "l22_parser.y"
                                     { (yyval.expression) = (yyvsp[0].expression); }
#line 1926 "l22_parser.tab.c"
    break;

  case 51:
#line 166 "l22_parser.y"
                                     { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1932 "l22_parser.tab.c"
    break;

  case 52:
#line 167 "l22_parser.y"
                                     { (yyval.expression) = new l22::nullptr_node(LINE); }
#line 1938 "l22_parser.tab.c"
    break;

  case 53:
#line 170 "l22_parser.y"
                                  { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1944 "l22_parser.tab.c"
    break;

  case 54:
#line 171 "l22_parser.y"
                                  { (yyval.expression) = new l22::identity_node(LINE,(yyvsp[0].expression)); }
#line 1950 "l22_parser.tab.c"
    break;

  case 55:
#line 172 "l22_parser.y"
                                 { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1956 "l22_parser.tab.c"
    break;

  case 56:
#line 173 "l22_parser.y"
                                 { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1962 "l22_parser.tab.c"
    break;

  case 57:
#line 174 "l22_parser.y"
                                 { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1968 "l22_parser.tab.c"
    break;

  case 58:
#line 175 "l22_parser.y"
                                 { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1974 "l22_parser.tab.c"
    break;

  case 59:
#line 176 "l22_parser.y"
                                 { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1980 "l22_parser.tab.c"
    break;

  case 60:
#line 177 "l22_parser.y"
                                 { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1986 "l22_parser.tab.c"
    break;

  case 61:
#line 178 "l22_parser.y"
                                 { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1992 "l22_parser.tab.c"
    break;

  case 62:
#line 179 "l22_parser.y"
                                  { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression));     }
#line 1998 "l22_parser.tab.c"
    break;

  case 63:
#line 180 "l22_parser.y"
                                 { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2004 "l22_parser.tab.c"
    break;

  case 64:
#line 181 "l22_parser.y"
                                  { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2010 "l22_parser.tab.c"
    break;

  case 65:
#line 182 "l22_parser.y"
                                 { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2016 "l22_parser.tab.c"
    break;

  case 66:
#line 183 "l22_parser.y"
                                 { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2022 "l22_parser.tab.c"
    break;

  case 67:
#line 184 "l22_parser.y"
                                  { (yyval.expression) = new cdk::and_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2028 "l22_parser.tab.c"
    break;

  case 68:
#line 185 "l22_parser.y"
                                  { (yyval.expression) = new cdk::or_node (LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2034 "l22_parser.tab.c"
    break;

  case 69:
#line 186 "l22_parser.y"
                                  { (yyval.expression) = (yyvsp[-1].expression); }
#line 2040 "l22_parser.tab.c"
    break;

  case 70:
#line 189 "l22_parser.y"
                                     { (yyval.expression) = new l22::read_node(LINE); }
#line 2046 "l22_parser.tab.c"
    break;

  case 71:
#line 190 "l22_parser.y"
                                      { (yyval.expression) = new l22::function_call_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].sequence));}
#line 2052 "l22_parser.tab.c"
    break;

  case 72:
#line 191 "l22_parser.y"
                                      { (yyval.expression) = new l22::function_call_node(LINE, nullptr, (yyvsp[-1].sequence));}
#line 2058 "l22_parser.tab.c"
    break;

  case 73:
#line 192 "l22_parser.y"
                               { (yyval.expression) = new l22::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 2064 "l22_parser.tab.c"
    break;

  case 74:
#line 193 "l22_parser.y"
                              { (yyval.expression) = new l22::sizeof_node(LINE,(yyvsp[-1].expression)); }
#line 2070 "l22_parser.tab.c"
    break;

  case 75:
#line 195 "l22_parser.y"
                               { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 2076 "l22_parser.tab.c"
    break;

  case 76:
#line 196 "l22_parser.y"
                               { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 2082 "l22_parser.tab.c"
    break;

  case 77:
#line 197 "l22_parser.y"
                               { (yyval.expression) = new l22::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 2088 "l22_parser.tab.c"
    break;

  case 78:
#line 200 "l22_parser.y"
                                                       { (yyval.expression) = new l22::function_definition_node(LINE,(yyvsp[-2].type),(yyvsp[-6].sequence),(yyvsp[0].block)); }
#line 2094 "l22_parser.tab.c"
    break;

  case 79:
#line 201 "l22_parser.y"
                                                           { (yyval.expression) = new l22::function_definition_node(LINE,(yyvsp[-2].type),nullptr,(yyvsp[0].block)); }
#line 2100 "l22_parser.tab.c"
    break;

  case 80:
#line 206 "l22_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression));}
#line 2106 "l22_parser.tab.c"
    break;

  case 81:
#line 207 "l22_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 2112 "l22_parser.tab.c"
    break;

  case 82:
#line 210 "l22_parser.y"
                                { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 2118 "l22_parser.tab.c"
    break;

  case 83:
#line 211 "l22_parser.y"
                                { (yyval.sequence) = (yyvsp[0].sequence); }
#line 2124 "l22_parser.tab.c"
    break;

  case 84:
#line 216 "l22_parser.y"
                                                         { (yyval.type_vector) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.type_vector)->push_back((yyvsp[0].type));}
#line 2130 "l22_parser.tab.c"
    break;

  case 85:
#line 217 "l22_parser.y"
                                                            { (yyval.type_vector) = (yyvsp[-2].type_vector); (yyval.type_vector)->push_back((yyvsp[0].type)); }
#line 2136 "l22_parser.tab.c"
    break;

  case 86:
#line 220 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING);  }
#line 2142 "l22_parser.tab.c"
    break;

  case 87:
#line 221 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT );     }
#line 2148 "l22_parser.tab.c"
    break;

  case 88:
#line 222 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE);  }
#line 2154 "l22_parser.tab.c"
    break;

  case 89:
#line 223 "l22_parser.y"
                                                { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_VOID);  }
#line 2160 "l22_parser.tab.c"
    break;

  case 90:
#line 224 "l22_parser.y"
                                                { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 2166 "l22_parser.tab.c"
    break;

  case 91:
#line 225 "l22_parser.y"
                                                { std::vector<std::shared_ptr<cdk::basic_type>> ola; ola.push_back((yyvsp[-2].type)); (yyval.type) =  cdk::functional_type::create(ola); }
#line 2172 "l22_parser.tab.c"
    break;

  case 92:
#line 226 "l22_parser.y"
                                                { std::vector<std::shared_ptr<cdk::basic_type>> ola; ola.push_back((yyvsp[-3].type)); (yyval.type) =  cdk::functional_type::create(ola,*(yyvsp[-1].type_vector)); delete (yyvsp[-1].type_vector); }
#line 2178 "l22_parser.tab.c"
    break;

  case 93:
#line 230 "l22_parser.y"
                                                { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 2184 "l22_parser.tab.c"
    break;

  case 94:
#line 231 "l22_parser.y"
                                                { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 2190 "l22_parser.tab.c"
    break;

  case 95:
#line 232 "l22_parser.y"
                                                { (yyval.s) = (yyvsp[0].s); }
#line 2196 "l22_parser.tab.c"
    break;

  case 96:
#line 233 "l22_parser.y"
                                                { (yyval.s) = (yyvsp[-1].s); (yyval.s)->append(*(yyvsp[0].s)); delete (yyvsp[0].s); }
#line 2202 "l22_parser.tab.c"
    break;


#line 2206 "l22_parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (compiler, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (compiler, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, compiler);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, compiler);
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
#line 236 "l22_parser.y"

