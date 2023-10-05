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
#line 12 "syntaxique.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TS.h"
#include "RS.h"
#include "Quad.h"
#include "CodeMachine.h"

    
int yylex();
int yyerror(char *);

extern FILE* yyin;
extern int line,colo;

char msg[100];//message d'erreur en générale
//variable pour les quad--------------------------------
int nTemp=1; char tempC[12]="";
int sauv_BNE,sauv_BR,sauv_BE,sauv_BLE,sauv_BL,sauv_BGE,sauv_BG,sauv_BNZ,sauv_BZ,sauv_res,sauv_pos;
char *quadNum;
char *tempStr;
char position[12]="";

#line 95 "syntaxique.tab.c"

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
#ifndef YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
# define YY_YY_SYNTAXIQUE_TAB_H_INCLUDED
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
    VAR = 258,
    CODE = 259,
    INTEGER = 260,
    FLOAT = 261,
    STRUCT = 262,
    IF = 263,
    CONST = 264,
    ELSE = 265,
    FOR = 266,
    WHILE = 267,
    IDF = 268,
    REEL = 269,
    ENTIER = 270,
    REEL_SGN = 271,
    ENTIER_SGN = 272,
    AFF = 273,
    ADD = 274,
    SUB = 275,
    MUL = 276,
    DIV = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    G = 281,
    GE = 282,
    L = 283,
    LE = 284,
    E = 285,
    NE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "syntaxique.y"
char* nom; 
			struct {char* name; int type; char* res; int nbr; int pos; int debut;}NT; 
			struct {char* nom; int val;}DECT;
			struct {char* nomIndice; char* etape; int debutCond; int sauv_BZ; int sauv_BNZ;}boucle;
			struct {int sauv_BZ; int sauv_BR;}Cond;
			struct{int indexStr;}structure;
		

#line 188 "syntaxique.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAXIQUE_TAB_H_INCLUDED  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,     2,     2,    31,     2,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    27,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    71,    73,    75,    76,    78,    82,    86,
      90,    94,    98,   100,   103,   106,   109,   112,   117,   118,
     121,   122,   125,   126,   129,   135,   136,   137,   141,   149,
     151,   153,   155,   157,   159,   161,   163,   167,   173,   182,
     190,   200,   205,   212,   218,   228,   234,   239,   247,   253,
     259,   274,   287,   299,   311,   323,   335,   347,   359,   371,
     382,   387,   392,   397,   402,   407,   412,   413,   419,   426,
     433,   434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "CODE", "INTEGER", "FLOAT",
  "STRUCT", "IF", "CONST", "ELSE", "FOR", "WHILE", "IDF", "REEL", "ENTIER",
  "REEL_SGN", "ENTIER_SGN", "AFF", "ADD", "SUB", "MUL", "DIV", "'('",
  "')'", "'{'", "'}'", "';'", "':'", "'['", "']'", "','", "'.'", "OR",
  "AND", "NOT", "G", "GE", "L", "LE", "E", "NE", "$accept", "S",
  "declaration", "INTEGERdecPartie1", "FLOATdecPartie1", "STRusePartie2",
  "STRdec", "CHAMPS", "listIDF", "CHAMP", "STRuse", "NUMBER",
  "instruction", "INSTaff", "INSTaff2", "INSTaff3", "INSTaff4",
  "IFpartie3", "IFpartie2", "IFpartie1", "FORpartie4", "FORpartie3",
  "FORpartie2", "FORpartie1", "WHILEpartie2", "WHILEpartie1", "condition",
  "exp", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    40,    41,   123,   125,    59,    58,    91,
      93,    44,    46,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    17,    53,    66,   -90,    49,   107,    65,    82,    -4,
     108,   101,   107,   107,   107,   102,   115,    88,   -90,    91,
     -90,   -90,    24,   112,   127,   -90,   -90,   -90,   107,   -20,
     -90,   -90,   117,   115,   118,   121,   122,   110,   111,   109,
     114,   -90,   113,   -90,   116,   -90,   -90,   124,    24,   120,
     123,   125,   126,    69,   128,   129,   -90,   -90,   107,   107,
     107,   107,   119,   131,   134,   -16,   132,   133,   135,   136,
     137,   139,   140,   143,   142,   145,   144,   146,   147,   151,
     107,   107,   -90,   -90,   -90,   -90,    73,   138,    73,    31,
       5,   148,   150,    69,    69,    69,    69,    69,   130,   152,
      69,   153,   155,   156,    69,   154,   -90,   -90,   -17,   -90,
     -90,   -90,   -90,    31,   157,    -7,     7,    64,    34,   -90,
     -90,     7,   -90,    72,   158,   159,   141,   -90,   -90,   -90,
     -90,   -90,   -90,   160,    69,   -90,    69,   162,   -90,   -90,
      69,    10,   168,    87,    73,    73,    73,    31,    31,    31,
      31,    31,    31,    31,    31,    31,    31,   164,   165,    31,
      69,   -90,   -90,    73,   -90,   161,   163,   -90,   -90,     4,
     166,   -90,    34,    34,    72,    72,    72,    72,    72,    72,
     -90,   -90,    31,    31,    72,   -90,     7,   -90,   -90,   -90,
      72,    72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    13,     0,     0,     0,
       0,     0,    13,    13,    13,     0,     0,     0,    14,     0,
      15,    24,    19,     0,     0,     3,     5,     7,    13,     0,
      16,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,    21,     0,    22,    23,     0,    19,     0,
       0,     0,     0,    36,     0,     0,    17,    18,    13,    13,
      13,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    13,    10,     8,    11,     9,     0,     0,     0,     0,
       0,     0,     0,    36,    36,    36,    36,    36,     0,     0,
      36,     0,     0,     0,    36,     0,     4,     6,    66,    26,
      25,    28,    27,     0,     0,    70,    43,     0,    62,    65,
      47,    49,    70,    37,     0,     0,     0,     2,    29,    30,
      31,    32,    33,     0,    36,    34,    36,     0,    46,    35,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    42,    44,     0,    48,     0,     0,    69,    71,     0,
      50,    51,    61,    60,    53,    54,    55,    56,    57,    58,
      63,    64,     0,     0,    38,    41,    45,    68,    67,    52,
      40,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,    -9,   -90,   -90,   -90,   -90,    93,    -2,   -90,
     -90,   -78,   -61,   -90,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,   -90,   -87,   -89,   -50,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    13,    14,    15,    37,    18,    38,
      16,   122,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   116,   117,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   121,    89,    25,    26,    27,    20,    31,   115,    21,
     115,    33,   141,    90,    30,   142,    91,   -59,   124,    41,
     125,    22,     1,   165,   143,   166,   -59,   -59,   189,    35,
      36,    43,   128,   129,   130,   131,   132,   145,   146,   135,
     145,   146,     3,   139,   108,   109,   110,   111,   112,    82,
      83,    84,    85,     4,   113,   155,   156,   169,   170,   171,
     174,   175,   176,   177,   178,   179,   115,   115,   115,     5,
     184,   106,   107,   161,     6,   162,   186,    62,    17,   164,
      63,    64,    65,   147,   148,   115,   108,   109,   110,   111,
     112,   147,   148,   190,   191,    19,   113,   172,   173,   185,
     149,   150,   151,   152,   153,   154,   147,   148,   114,   180,
     181,   168,     7,     8,     9,    31,    10,    32,    31,    33,
      34,    23,    33,    49,    50,    51,    52,    24,    29,    28,
      39,    40,    42,    44,    45,    46,    47,    56,    48,    53,
     133,    57,    86,    54,     0,     0,    55,    58,     0,     0,
      59,   120,    60,    61,    87,    80,    81,    88,    92,   159,
      93,   126,    94,    95,    96,    97,    98,    99,   100,   101,
     137,   138,   102,   104,   103,   105,   127,   134,   136,   140,
     144,   167,   182,   183,     0,   160,     0,     0,   157,   158,
     163,   187,     0,   188,     0,     0,     0,     0,     0,     0,
     146
};

static const yytype_int16 yycheck[] =
{
      89,    88,    18,    12,    13,    14,     8,    27,    86,    13,
      88,    31,    29,    29,    16,    32,    32,    24,    13,    28,
      15,    25,    13,    13,   113,    15,    33,    34,    24,     5,
       6,    33,    93,    94,    95,    96,    97,    33,    34,   100,
      33,    34,    25,   104,    13,    14,    15,    16,    17,    58,
      59,    60,    61,     0,    23,    21,    22,   144,   145,   146,
     149,   150,   151,   152,   153,   154,   144,   145,   146,     3,
     159,    80,    81,   134,    25,   136,   163,     8,    13,   140,
      11,    12,    13,    19,    20,   163,    13,    14,    15,    16,
      17,    19,    20,   182,   183,    13,    23,   147,   148,   160,
      36,    37,    38,    39,    40,    41,    19,    20,    35,   155,
     156,    24,     5,     6,     7,    27,     9,    29,    27,    31,
      29,    13,    31,    14,    15,    16,    17,    26,    13,    27,
      18,     4,    15,    15,    13,    13,    26,    13,    27,    25,
      10,    48,    23,    30,    -1,    -1,    30,    27,    -1,    -1,
      27,    13,    27,    27,    23,    27,    27,    23,    26,    18,
      27,    13,    27,    27,    27,    26,    26,    24,    26,    24,
      15,    15,    28,    26,    28,    24,    26,    25,    25,    25,
      23,    13,    18,    18,    -1,    25,    -1,    -1,    30,    30,
      28,    30,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    43,    25,     0,     3,    25,     5,     6,     7,
       9,    44,    45,    46,    47,    48,    52,    13,    50,    13,
      50,    13,    25,    13,    26,    44,    44,    44,    27,    13,
      50,    27,    29,    31,    29,     5,     6,    49,    51,    18,
       4,    44,    15,    50,    15,    13,    13,    26,    27,    14,
      15,    16,    17,    25,    30,    30,    13,    49,    27,    27,
      27,    27,     8,    11,    12,    13,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      27,    27,    44,    44,    44,    44,    23,    23,    23,    18,
      29,    32,    26,    27,    27,    27,    27,    26,    26,    24,
      26,    24,    28,    28,    26,    24,    44,    44,    13,    14,
      15,    16,    17,    23,    35,    53,    68,    69,    70,    71,
      13,    68,    53,    69,    13,    15,    13,    26,    54,    54,
      54,    54,    54,    10,    25,    54,    25,    15,    15,    54,
      25,    29,    32,    69,    23,    33,    34,    19,    20,    36,
      37,    38,    39,    40,    41,    21,    22,    30,    30,    18,
      25,    54,    54,    28,    54,    13,    15,    13,    24,    68,
      68,    68,    70,    70,    69,    69,    69,    69,    69,    69,
      71,    71,    18,    18,    69,    54,    68,    30,    30,    24,
      69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    46,    47,    48,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    71,
      71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     2,     7,     2,     7,     2,     6,     6,
       6,     6,     3,     0,     2,     2,     2,     5,     3,     0,
       2,     3,     2,     2,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     0,     3,     5,     6,
       6,     5,     4,     3,     4,     5,     3,     3,     4,     3,
       3,     3,     4,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     1,     4,     4,     3,
       1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
yyparse (void)
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
  case 3:
#line 71 "syntaxique.y"
                                                                                {}
#line 1488 "syntaxique.tab.c"
    break;

  case 4:
#line 73 "syntaxique.y"
                                                                                {rsDoubleDec((yyvsp[-5].nom)); inserer((yyvsp[-5].nom),4,atoi((yyvsp[-3].nom)),-1);}
#line 1494 "syntaxique.tab.c"
    break;

  case 5:
#line 75 "syntaxique.y"
                                                                                        {}
#line 1500 "syntaxique.tab.c"
    break;

  case 6:
#line 76 "syntaxique.y"
                                                                                        {rsDoubleDec((yyvsp[-5].nom));  inserer((yyvsp[-5].nom),5,atoi((yyvsp[-3].nom)),-1);}
#line 1506 "syntaxique.tab.c"
    break;

  case 7:
#line 78 "syntaxique.y"
                                                                                                {}
#line 1512 "syntaxique.tab.c"
    break;

  case 8:
#line 82 "syntaxique.y"
                                                                                                {if(rechercher((yyvsp[-4].nom))==-1){EntierOverflow(atoi((yyvsp[-2].nom))); insererCst((yyvsp[-4].nom),1,(yyvsp[-2].nom));}
																			else{printf("constante %s deja declare. ",(yyvsp[-4].nom)); yyerror("");}
																		}
#line 1520 "syntaxique.tab.c"
    break;

  case 9:
#line 86 "syntaxique.y"
                                                                                                        {if(rechercher((yyvsp[-4].nom))==-1){EntierOverflow(atoi(SupPar((yyvsp[-2].nom)))); insererCst((yyvsp[-4].nom),1,(yyvsp[-2].nom));}
																			else{printf("constante %s deja declare. ",(yyvsp[-4].nom)); yyerror("");}
																		}
#line 1528 "syntaxique.tab.c"
    break;

  case 10:
#line 90 "syntaxique.y"
                                                                        {if(rechercher((yyvsp[-4].nom))==-1){insererCst((yyvsp[-4].nom),2,(yyvsp[-2].nom));}
																			else{printf("constante %s deja declare. ",(yyvsp[-4].nom)); yyerror("");}
																		}
#line 1536 "syntaxique.tab.c"
    break;

  case 11:
#line 94 "syntaxique.y"
                                                                                    {if(rechercher((yyvsp[-4].nom))==-1){insererCst((yyvsp[-4].nom),2,(yyvsp[-2].nom));}
																			else{printf("constante %s deja declare. ",(yyvsp[-4].nom)); yyerror("");}
																		}
#line 1544 "syntaxique.tab.c"
    break;

  case 12:
#line 98 "syntaxique.y"
                                                                                        {}
#line 1550 "syntaxique.tab.c"
    break;

  case 14:
#line 103 "syntaxique.y"
                                                                                        {MAJtype(1,-1);}
#line 1556 "syntaxique.tab.c"
    break;

  case 15:
#line 106 "syntaxique.y"
                                                                                                {MAJtype(2,-1);}
#line 1562 "syntaxique.tab.c"
    break;

  case 16:
#line 109 "syntaxique.y"
                                                                                                {MAJtype(3,(yyvsp[-1].structure).indexStr);}
#line 1568 "syntaxique.tab.c"
    break;

  case 17:
#line 112 "syntaxique.y"
                                                                {if(getIndexStruct((yyvsp[0].nom))!=-1){printf("erreur sémantique double déclaration de structure. "); yyerror("");}
													ajouterStructure((yyvsp[0].nom));
												}
#line 1576 "syntaxique.tab.c"
    break;

  case 18:
#line 117 "syntaxique.y"
                                                                        {}
#line 1582 "syntaxique.tab.c"
    break;

  case 19:
#line 118 "syntaxique.y"
                                                                                                {}
#line 1588 "syntaxique.tab.c"
    break;

  case 20:
#line 121 "syntaxique.y"
                                        {rsDoubleDec((yyvsp[-1].nom)); inserer((yyvsp[-1].nom),0,-1,-1); insererTab((yyvsp[-1].nom)); }
#line 1594 "syntaxique.tab.c"
    break;

  case 21:
#line 122 "syntaxique.y"
                                        {rsDoubleDec((yyvsp[-2].nom)); inserer((yyvsp[-2].nom),0,-1,-1); insererTab((yyvsp[-2].nom)); }
#line 1600 "syntaxique.tab.c"
    break;

  case 22:
#line 125 "syntaxique.y"
                                                                        {if(ajouterChamps((yyvsp[0].nom),1)!=-1){printf("erreur semantique; double déclaration de champs. "); yyerror("");}}
#line 1606 "syntaxique.tab.c"
    break;

  case 23:
#line 126 "syntaxique.y"
                                                                                        {if(ajouterChamps((yyvsp[0].nom),2)!=-1){printf("erreur semantique; double déclaration de champs. "); yyerror("");}}
#line 1612 "syntaxique.tab.c"
    break;

  case 24:
#line 129 "syntaxique.y"
                                                                                {if(getIndexStruct((yyvsp[0].nom))==-1){printf("erreur semantique; structure nest pas declare."); yyerror("");}
													(yyval.structure).indexStr = getIndexStruct((yyvsp[0].nom));
												}
#line 1620 "syntaxique.tab.c"
    break;

  case 25:
#line 135 "syntaxique.y"
                        {(yyval.NT).res = strdup((yyvsp[0].nom)); (yyval.NT).type = 1;}
#line 1626 "syntaxique.tab.c"
    break;

  case 26:
#line 136 "syntaxique.y"
                        {(yyval.NT).res = strdup((yyvsp[0].nom)); (yyval.NT).type = 2;}
#line 1632 "syntaxique.tab.c"
    break;

  case 27:
#line 137 "syntaxique.y"
                    {(yyval.NT).type = 1; tempStr=strdup(SupPar((yyvsp[0].nom)));
						if(checkSign(tempStr)){sprintf(tempC,"T%d",nTemp); nTemp++; quad("-",strdup(SupSign(tempStr)),"",strdup(tempC)); (yyval.NT).res=strdup(tempC);}
						else{(yyval.NT).res=strdup(SupSign(tempStr));}
					}
#line 1641 "syntaxique.tab.c"
    break;

  case 28:
#line 141 "syntaxique.y"
                        {(yyval.NT).type = 2; tempStr=strdup(SupPar((yyvsp[0].nom)));
						if(checkSign(tempStr)){sprintf(tempC,"T%d",nTemp); nTemp++; quad("-",strdup(SupSign(tempStr)),"",strdup(tempC)); (yyval.NT).res=strdup(tempC);}
						else{(yyval.NT).res=strdup(SupSign(tempStr));}
					}
#line 1650 "syntaxique.tab.c"
    break;

  case 29:
#line 149 "syntaxique.y"
                                                                        {}
#line 1656 "syntaxique.tab.c"
    break;

  case 30:
#line 151 "syntaxique.y"
                                                                        {}
#line 1662 "syntaxique.tab.c"
    break;

  case 31:
#line 153 "syntaxique.y"
                                                                        {}
#line 1668 "syntaxique.tab.c"
    break;

  case 32:
#line 155 "syntaxique.y"
                                                                        {}
#line 1674 "syntaxique.tab.c"
    break;

  case 33:
#line 157 "syntaxique.y"
                                                                        {}
#line 1680 "syntaxique.tab.c"
    break;

  case 34:
#line 159 "syntaxique.y"
                                                                        {}
#line 1686 "syntaxique.tab.c"
    break;

  case 35:
#line 161 "syntaxique.y"
                                                                        {}
#line 1692 "syntaxique.tab.c"
    break;

  case 36:
#line 163 "syntaxique.y"
                                                                                                {}
#line 1698 "syntaxique.tab.c"
    break;

  case 37:
#line 167 "syntaxique.y"
                                                                                                {rsVerifierDec((yyvsp[-2].nom)); rsMAJconst((yyvsp[-2].nom)); 
																if(TypeIDF((yyvsp[-2].nom))!=(yyvsp[0].NT).type){yyerror("Affectation impossible, types incompatible. ");}
																quad(":=",(yyvsp[0].NT).res,"",(yyvsp[-2].nom));
															}
#line 1707 "syntaxique.tab.c"
    break;

  case 38:
#line 173 "syntaxique.y"
                                                                                        {rsVerifierDec((yyvsp[-4].nom));
																if(TypeIDF((yyvsp[-4].nom))!=3){sprintf(msg,"%s n\'est pas une structure. ",(yyvsp[-4].nom)); yyerror(msg);}
																rsVerifierDecChamp((yyvsp[-4].nom),(yyvsp[-2].nom));
																if(TypeChamp((yyvsp[-4].nom),(yyvsp[-2].nom)) != (yyvsp[0].NT).type){yyerror("Affectation impossible, types incompatible. ");}
																sprintf(tempC,"%s.%s",(yyvsp[-4].nom),(yyvsp[-2].nom));
																quad(":=",(yyvsp[0].NT).res,"",strdup(tempC));
															}
#line 1719 "syntaxique.tab.c"
    break;

  case 39:
#line 182 "syntaxique.y"
                                                                                {rsVerifierDec((yyvsp[-5].nom));
																if(TypeIDF((yyvsp[-5].nom))!=4 && TypeIDF((yyvsp[-5].nom))!=5){sprintf(msg,"%s n\'est pas un tableau. ",(yyvsp[-5].nom)); yyerror(msg);}
																if((TypeIDF((yyvsp[-5].nom)) - (yyvsp[0].NT).type)!=3){yyerror("types incompatible. ");}
																sprintf(tempC,"%s[%s]",(yyvsp[-5].nom),(yyvsp[-3].nom));
																quad(":=",(yyvsp[0].NT).res,"",strdup(tempC));
															}
#line 1730 "syntaxique.tab.c"
    break;

  case 40:
#line 190 "syntaxique.y"
                                                                                        {rsVerifierDec((yyvsp[-5].nom)); 
																if(TypeIDF((yyvsp[-5].nom))!=4 && TypeIDF((yyvsp[-5].nom))!=5){sprintf(msg,"%s n\'est pas un tableau. ",(yyvsp[-5].nom)); yyerror(msg);}
																if(TypeIDF((yyvsp[-3].nom))!=1){yyerror("l\'indice utilise pour acceder aux elements du tableau doit etre entier. ");}
																if((TypeIDF((yyvsp[-5].nom)) - (yyvsp[0].NT).type)!=3){yyerror("types incompatible. ");}
																sprintf(tempC,"%s[%s]",(yyvsp[-5].nom),(yyvsp[-3].nom));
																quad(":=",(yyvsp[0].NT).res,"",strdup(tempC));
															}
#line 1742 "syntaxique.tab.c"
    break;

  case 41:
#line 200 "syntaxique.y"
                                                                                                { sprintf(position,"%d",getIndq());
																			MajQaud((yyvsp[-4].Cond).sauv_BR,strdup(position));
																		}
#line 1750 "syntaxique.tab.c"
    break;

  case 42:
#line 205 "syntaxique.y"
                                                                                                        {(yyval.Cond).sauv_BR = quad("BR","","","");
																			sprintf(position,"%d",(yyval.Cond).sauv_BR+1);
																			MajQaud((yyvsp[-3].Cond).sauv_BZ,strdup(position));
																			
																		}
#line 1760 "syntaxique.tab.c"
    break;

  case 43:
#line 212 "syntaxique.y"
                                                                                                                {(yyval.Cond).sauv_BZ = quad("BZ","",(yyvsp[0].NT).res,"");
																			
																		}
#line 1768 "syntaxique.tab.c"
    break;

  case 44:
#line 218 "syntaxique.y"
                                                                                                        {sprintf(tempC,"T%d",nTemp); nTemp++;
																			quad("+",(yyvsp[-3].boucle).nomIndice,(yyvsp[-3].boucle).etape,strdup(tempC));
																			quad(":=",strdup(tempC),"",(yyvsp[-3].boucle).nomIndice);
																			sprintf(position,"%d",(yyvsp[-3].boucle).debutCond);
																			quad("BR",strdup(position),"","");
																			sprintf(position,"%d",getIndq());
																			MajQaud((yyvsp[-3].boucle).sauv_BNZ,strdup(position));
																		}
#line 1781 "syntaxique.tab.c"
    break;

  case 45:
#line 228 "syntaxique.y"
                                                                                                {(yyval.boucle).debutCond = getIndq() - (yyvsp[0].NT).nbr;
																			(yyval.boucle).sauv_BNZ = quad("BNZ","",(yyvsp[0].NT).res,"");
																			(yyval.boucle).etape = strdup((yyvsp[-2].nom));
																		}
#line 1790 "syntaxique.tab.c"
    break;

  case 46:
#line 234 "syntaxique.y"
                                                                                                                {quad(":=",(yyvsp[0].nom),"",(yyvsp[-2].boucle).nomIndice); 
																			
																		}
#line 1798 "syntaxique.tab.c"
    break;

  case 47:
#line 239 "syntaxique.y"
                                                                                                                        {rsVerifierDec((yyvsp[0].nom));
																			if(TypeIDF((yyvsp[0].nom))!=1){ printf("erreur sémantique; %s n\'nest pas entier. ",(yyvsp[0].nom)); yyerror("");}
																			(yyval.boucle).nomIndice = strdup((yyvsp[0].nom));
																		}
#line 1807 "syntaxique.tab.c"
    break;

  case 48:
#line 247 "syntaxique.y"
                                                                                                {sprintf(position,"%d",(yyvsp[-3].boucle).debutCond);
																			quad("BR",strdup(position),"","");
																			sprintf(position,"%d",getIndq());
																			MajQaud((yyvsp[-3].boucle).sauv_BZ,strdup(position));
																		}
#line 1817 "syntaxique.tab.c"
    break;

  case 49:
#line 253 "syntaxique.y"
                                                                                                                {(yyval.boucle).debutCond = getIndq() - (yyvsp[0].NT).nbr;
																			(yyval.boucle).sauv_BZ = quad("BZ","",(yyvsp[0].NT).res,"");
																		}
#line 1825 "syntaxique.tab.c"
    break;

  case 50:
#line 259 "syntaxique.y"
                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BZ = quad("BZ","",(yyvsp[-2].NT).res,"");
										sprintf(tempC,"T%d",nTemp); nTemp++;
										sauv_res = quad(":=","1","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sauv_BNZ = quad("BNZ","",(yyvsp[0].NT).res,"");
										sprintf(position,"%d",sauv_BNZ);
										MajQaud(sauv_BZ,strdup(position));
										sprintf(position,"%d",sauv_res);
										MajQaud(sauv_BNZ,strdup(position));
										quad(":=","0","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[0].NT).nbr+5;
									}
#line 1845 "syntaxique.tab.c"
    break;

  case 51:
#line 274 "syntaxique.y"
                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										push(quad("BZ","",(yyvsp[-2].NT).res,""));
										push(quad("BZ","",(yyvsp[0].NT).res,""));
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","1","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaudPile(strdup(position));
										quad(":=","0","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[0].NT).nbr+5;
									}
#line 1863 "syntaxique.tab.c"
    break;

  case 52:
#line 287 "syntaxique.y"
                                        {(yyval.NT).type = (yyvsp[-1].NT).type;
										sauv_BNZ = quad("BNZ","",(yyvsp[-1].NT).res,"");
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BNZ,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-1].NT).nbr+4;
									}
#line 1880 "syntaxique.tab.c"
    break;

  case 53:
#line 299 "syntaxique.y"
                                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BG = quad("BG","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BG,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1897 "syntaxique.tab.c"
    break;

  case 54:
#line 311 "syntaxique.y"
                                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BGE = quad("BGE","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BGE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1914 "syntaxique.tab.c"
    break;

  case 55:
#line 323 "syntaxique.y"
                                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BL = quad("BL","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BL,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1931 "syntaxique.tab.c"
    break;

  case 56:
#line 335 "syntaxique.y"
                                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BLE = quad("BLE","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BLE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1948 "syntaxique.tab.c"
    break;

  case 57:
#line 347 "syntaxique.y"
                                                        {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BE = quad("BE","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1965 "syntaxique.tab.c"
    break;

  case 58:
#line 359 "syntaxique.y"
                                                {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("expressions de types incompatible. ");}else{(yyval.NT).type = (yyvsp[-2].NT).type;}
										sauv_BNE = quad("BNE","",(yyvsp[-2].NT).res,(yyvsp[0].NT).res);
										sprintf(tempC,"T%d",nTemp); nTemp++;
										quad(":=","0","",strdup(tempC));
										sauv_BR = quad("BR","","","");
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BNE,strdup(position));
										quad(":=","1","",strdup(tempC));
										sprintf(position,"%d",getIndq());
										MajQaud(sauv_BR,strdup(position));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+4;
									}
#line 1982 "syntaxique.tab.c"
    break;

  case 59:
#line 371 "syntaxique.y"
                                                        {(yyval.NT).type = (yyvsp[0].NT).type; (yyval.NT).res=(yyvsp[0].NT).res;
										sprintf(tempC,"T%d",nTemp); nTemp++;
										if(atoi((yyvsp[0].NT).res)!=0){
											quad(":=","1","",strdup(tempC));
										}
										else quad(":=","0","",strdup(tempC));
										(yyval.NT).res=strdup(tempC); tempC[0]='\0'; (yyval.NT).nbr=1;
									}
#line 1995 "syntaxique.tab.c"
    break;

  case 60:
#line 382 "syntaxique.y"
                                {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type)	{yyerror("types incompatible. ");} else{(yyval.NT).type = (yyvsp[-2].NT).type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; (yyval.NT).res=strdup(tempC); tempC[0]='\0';
								quad("-",(yyvsp[-2].NT).res,(yyvsp[0].NT).res,(yyval.NT).res);
								(yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+1;
							}
#line 2005 "syntaxique.tab.c"
    break;

  case 61:
#line 387 "syntaxique.y"
                                {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type)	{yyerror("types incompatible. ");} else{(yyval.NT).type = (yyvsp[-2].NT).type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; (yyval.NT).res=strdup(tempC); tempC[0]='\0';
								quad("+",(yyvsp[-2].NT).res,(yyvsp[0].NT).res,(yyval.NT).res);
								(yyval.NT).nbr=(yyvsp[-2].NT).nbr+(yyvsp[0].NT).nbr+1;
							}
#line 2015 "syntaxique.tab.c"
    break;

  case 62:
#line 392 "syntaxique.y"
                                        {(yyval.NT).res=(yyvsp[0].NT).res; (yyval.NT).type = (yyvsp[0].NT).type;
								(yyval.NT).nbr=(yyvsp[0].NT).nbr;
							}
#line 2023 "syntaxique.tab.c"
    break;

  case 63:
#line 397 "syntaxique.y"
                                {if((yyvsp[-2].NT).type != (yyvsp[0].NT).type){yyerror("types incompatible. ");} else{(yyval.NT).type = (yyvsp[-2].NT).type;}
								sprintf(tempC,"T%d",nTemp); nTemp++; (yyval.NT).res=strdup(tempC); tempC[0]='\0';
								quad("*",(yyvsp[-2].NT).res,(yyvsp[0].NT).res,(yyval.NT).res);
								(yyval.NT).nbr=(yyvsp[-2].NT).nbr+1;
							}
#line 2033 "syntaxique.tab.c"
    break;

  case 64:
#line 402 "syntaxique.y"
                                {if(!strcmp((yyvsp[0].NT).res,"0")){yyerror("division par zero.");} 
								sprintf(tempC,"T%d",nTemp); nTemp++; (yyval.NT).res=strdup(tempC); tempC[0]='\0';
								quad("/",(yyvsp[-2].NT).res,(yyvsp[0].NT).res,(yyval.NT).res);
								(yyval.NT).nbr=(yyvsp[-2].NT).nbr+1;
							}
#line 2043 "syntaxique.tab.c"
    break;

  case 65:
#line 407 "syntaxique.y"
                                        {	(yyval.NT).res =strdup((yyvsp[0].NT).res); (yyval.NT).type = (yyvsp[0].NT).type; 
								(yyval.NT).nbr=0;
							}
#line 2051 "syntaxique.tab.c"
    break;

  case 66:
#line 412 "syntaxique.y"
                                        {rsVerifierDec((yyvsp[0].nom)); (yyval.NT).res=strdup((yyvsp[0].nom)); (yyval.NT).type = TypeIDF((yyvsp[0].nom));}
#line 2057 "syntaxique.tab.c"
    break;

  case 67:
#line 413 "syntaxique.y"
                                    {rsVerifierDec((yyvsp[-3].nom));
								if(TypeIDF((yyvsp[-3].nom))!=4 && TypeIDF((yyvsp[-3].nom))!=5){sprintf(msg,"%s n\'est pas un tableau. ",(yyvsp[-3].nom)); yyerror(msg);}
								(yyval.NT).type = TypeIDF((yyvsp[-3].nom))-3;
								sprintf(msg,"%s[%d]",(yyvsp[-3].nom),atoi((yyvsp[-1].nom)));
								(yyval.NT).res = strdup(msg);
							}
#line 2068 "syntaxique.tab.c"
    break;

  case 68:
#line 419 "syntaxique.y"
                                        {rsVerifierDec((yyvsp[-3].nom)); 
								if(TypeIDF((yyvsp[-3].nom))!=4 && TypeIDF((yyvsp[-3].nom))!=5){sprintf(msg,"%s n\'est pas un tableau. ",(yyvsp[-3].nom)); yyerror(msg);}
								if(TypeIDF((yyvsp[-1].nom))!=1){yyerror("l\'indice utilise pour acceder aux elements du tableau doit etre entier. ");}
								(yyval.NT).type = TypeIDF((yyvsp[-3].nom))-3;
								sprintf(msg,"%s[%s]",(yyvsp[-3].nom),(yyvsp[-1].nom));
								(yyval.NT).res = strdup(msg);
							}
#line 2080 "syntaxique.tab.c"
    break;

  case 69:
#line 426 "syntaxique.y"
                                        {rsVerifierDec((yyvsp[-2].nom));
								if(TypeIDF((yyvsp[-2].nom))!=3){sprintf(msg,"%s n\'est pas une structure. ",(yyvsp[-2].nom)); yyerror(msg);}
								rsVerifierDecChamp((yyvsp[-2].nom),(yyvsp[0].nom));
								(yyval.NT).type = TypeChamp((yyvsp[-2].nom),(yyvsp[0].nom));
								sprintf(msg,"%s.%s",(yyvsp[-2].nom),(yyvsp[0].nom));
								(yyval.NT).res = strdup(msg);
							}
#line 2092 "syntaxique.tab.c"
    break;

  case 70:
#line 433 "syntaxique.y"
                                        {(yyval.NT).res = (yyvsp[0].NT).res; (yyval.NT).type = (yyvsp[0].NT).type;}
#line 2098 "syntaxique.tab.c"
    break;

  case 71:
#line 434 "syntaxique.y"
                                {(yyval.NT).res = (yyvsp[-1].NT).res; (yyval.NT).type = (yyvsp[-1].NT).type;}
#line 2104 "syntaxique.tab.c"
    break;


#line 2108 "syntaxique.tab.c"

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
        yyerror (yymsgp);
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
                  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 439 "syntaxique.y"


int yyerror(char* msg){
    printf (" %s ligne %d colonne %d \n",msg,line,colo); exit (0);return 1;
}

int main (){ 
    yyin = fopen("test.txt", "r");
    yyparse ();
    fclose (yyin);
    afficherTS();
    //afficherStrTable();
	//afficherChamps();
	afficherQuad();
	createTextQuad();
	createCodeAssembleur();
}

