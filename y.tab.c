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
#line 1 "calc.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "Types.h"
extern int yylex();
int stackPosition = -1 ;
int FloatVariableStackCounter = 0;
int yydebug = 1;    
void yyerror(char *msg);
int elseAllowed = 1;
void actionHandler(int stackTop, int conditionResult, char *condition); 
int firstElseIf = 0;
int functionReturnTypeNumber = -1 ; 
int functionReturnTypeVoid = -1 ; 
int integerVariableEncountered = 0 , floatVariableEncountered = 0 ; 
int printInt = 0 ;
int enteredAssignment = 1; 
int functionReturnsInt = 0 ;

#line 88 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    VOID = 258,
    INT = 259,
    FLOAT = 260,
    IF = 261,
    ELSE = 262,
    ELSEIF = 263,
    INCR = 264,
    DECR = 265,
    VARNAME = 266,
    FNUM = 267,
    LTE = 268,
    GTE = 269,
    EQ = 270,
    NOT = 271,
    NET = 272,
    AND = 273,
    OR = 274,
    DISPLAY = 275,
    RETURN = 276,
    PLUSASSIGN = 277,
    MINUSASSIGN = 278,
    MULASSIGN = 279,
    DIVASSIGN = 280,
    MODASSIGN = 281
  };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FLOAT 260
#define IF 261
#define ELSE 262
#define ELSEIF 263
#define INCR 264
#define DECR 265
#define VARNAME 266
#define FNUM 267
#define LTE 268
#define GTE 269
#define EQ 270
#define NOT 271
#define NET 272
#define AND 273
#define OR 274
#define DISPLAY 275
#define RETURN 276
#define PLUSASSIGN 277
#define MINUSASSIGN 278
#define MULASSIGN 279
#define DIVASSIGN 280
#define MODASSIGN 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "calc.y" /* yacc.c:355  */

   float f;
   int i;
   char* s;
   Number n;

#line 187 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   281

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      34,    35,    31,    29,    40,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      13,    39,    14,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    57,    57,    58,    58,    59,    59,    62,
      63,    66,    67,    68,    69,    70,    71,    74,    75,    76,
      77,    78,    79,    80,    81,    84,    85,    88,    89,    92,
      93,    96,    97,    98,   101,   102,   103,   106,   107,   111,
     111,   114,   117,   126,   127,   128,   129,   132,   133,   134,
     135,   136,   137,   138,   142,   143,   144,   147,   148,   149,
     150,   153,   154,   155,   158,   159,   160,   161,   162,   163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FLOAT", "IF", "ELSE",
  "ELSEIF", "INCR", "DECR", "VARNAME", "FNUM", "'<'", "'>'", "LTE", "GTE",
  "EQ", "NOT", "NET", "AND", "OR", "DISPLAY", "RETURN", "PLUSASSIGN",
  "MINUSASSIGN", "MULASSIGN", "DIVASSIGN", "MODASSIGN", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'('", "')'", "'{'", "'}'", "';'", "'='", "','",
  "$accept", "Start", "$@1", "$@2", "$@3", "BODY", "BLOCK", "LINE",
  "ASSIGNMENT", "ASSIGN", "FINALVAR", "PRINTER", "CONTROL", "EXTRA",
  "EEXP", "$@4", "EXP", "CONDITIONALEXPRESSION", "CONDITION", "G", "E",
  "F", "D", "L", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    60,    62,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    43,
      45,    42,    47,    37,    40,    41,   123,   125,    59,    61,
      44
};
# endif

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    -2,     7,    32,    18,    74,    85,    77,  -121,    46,
      15,    15,    15,    46,    63,   228,  -121,  -121,    55,  -121,
      21,   172,     1,   108,  -121,  -121,    66,    60,    83,  -121,
     113,   115,    46,  -121,  -121,  -121,  -121,    15,    15,    15,
      15,    15,    15,    68,  -121,     1,     1,  -121,    33,  -121,
      99,    99,  -121,  -121,    54,  -121,    46,    46,  -121,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
    -121,  -121,    15,  -121,    99,  -121,  -121,    92,    86,    52,
      59,    82,    88,   104,   116,  -121,   120,  -121,  -121,   123,
    -121,  -121,  -121,  -121,  -121,  -121,   108,   108,  -121,  -121,
    -121,   138,   139,     1,  -121,   140,   141,  -121,  -121,  -121,
    -121,  -121,  -121,   144,   144,   144,   228,   143,    61,  -121,
    -121,  -121,   126,  -121,   142,   150,  -121,  -121,   160,  -121,
     145,    46,   158,  -121,  -121,   228,   149,    46,   194,   141,
     161,  -121,  -121,   141,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    65,    64,     0,
       0,    33,     0,     0,     0,     2,    11,    17,     0,    13,
       0,    46,    53,    56,    60,    63,     0,    30,     0,    28,
      30,     0,     0,    68,    69,    66,    67,     0,     0,     0,
       0,     0,     0,    65,    45,    31,    32,    62,     0,     1,
       0,     0,    12,    14,     0,    24,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     5,     0,    26,     0,     3,    25,     0,    42,     0,
       0,     0,     0,     0,     0,    61,    30,    16,    44,    43,
      47,    48,    50,    49,    52,    51,    54,    55,    57,    58,
      59,     0,     0,    29,    27,     0,     0,    19,    20,    21,
      22,    23,    18,     0,     0,     0,     0,    34,     0,     8,
       6,     4,     0,    39,     0,     0,    36,    10,     0,    41,
       0,     0,     0,    35,     9,     0,     0,     0,     0,     0,
       0,    40,    38,     0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,  -121,    47,  -106,   -14,  -121,     0,
     105,  -121,   -13,  -121,    70,  -121,   -93,  -120,    -9,   159,
      -3,   102,    -7,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,   105,   102,   101,   119,    15,    16,    17,    28,
      29,    18,    19,   125,   126,   130,   117,    77,    20,    21,
      22,    23,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    52,    53,    31,    48,    47,    54,    45,    46,    26,
     122,   136,   128,     1,     2,     3,     4,   140,    27,     5,
       6,     7,     8,    78,     5,     6,    43,     8,     9,   138,
      65,    66,    10,    11,    79,    80,    81,    82,    83,    84,
      12,    56,    57,    30,    13,    12,   142,    88,    89,    13,
     144,    31,    32,    56,    57,     5,     6,    43,     8,    58,
      98,    99,   100,    49,     9,    50,    51,     4,    85,   103,
       5,     6,     7,     8,    56,    57,    12,    35,    36,     9,
      13,    65,    66,    10,    11,    33,    35,    36,    65,    66,
     107,    12,    87,    55,    71,    13,    34,   108,   127,    72,
      70,    37,    38,    39,    40,    41,    56,    57,    52,    53,
      86,    65,    66,    54,    52,    53,    42,    65,    66,    54,
     109,    73,    78,    74,    52,    53,   110,   106,    78,    54,
      50,    51,     4,    65,    66,     5,     6,     7,     8,    67,
      68,    69,   111,    56,     9,    65,    66,    75,    10,    11,
     123,   124,    72,    76,   112,    74,    12,   123,   132,    72,
      13,   120,   121,   129,    50,    51,     4,    96,    97,     5,
       6,     7,     8,   113,   114,   115,   131,   116,     9,   104,
     118,   135,    10,    11,   139,    59,    60,    61,    62,    63,
      12,    64,   137,     0,    13,   133,   143,   134,    50,    51,
       4,     0,     0,     5,     6,     7,     8,     0,     0,     0,
       0,     0,     9,     0,     0,     0,    10,    11,    90,    91,
      92,    93,    94,    95,    12,     0,     0,     0,    13,     0,
       0,   141,    50,    51,     4,     0,     0,     5,     6,     7,
       8,     0,     0,     0,     0,     0,     9,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    13
};

static const yytype_int16 yycheck[] =
{
       9,    15,    15,     3,    13,    12,    15,    10,    11,    11,
     116,   131,   118,     3,     4,     5,     6,   137,    11,     9,
      10,    11,    12,    32,     9,    10,    11,    12,    18,   135,
      29,    30,    22,    23,    37,    38,    39,    40,    41,    42,
      30,    20,    21,    11,    34,    30,   139,    56,    57,    34,
     143,    51,    34,    20,    21,     9,    10,    11,    12,    38,
      67,    68,    69,     0,    18,     4,     5,     6,    35,    72,
       9,    10,    11,    12,    20,    21,    30,     9,    10,    18,
      34,    29,    30,    22,    23,    11,     9,    10,    29,    30,
      38,    30,    38,    38,    34,    34,    11,    38,    37,    39,
      34,    24,    25,    26,    27,    28,    20,    21,   122,   122,
      11,    29,    30,   122,   128,   128,    39,    29,    30,   128,
      38,    38,   131,    40,   138,   138,    38,    35,   137,   138,
       4,     5,     6,    29,    30,     9,    10,    11,    12,    31,
      32,    33,    38,    20,    18,    29,    30,    34,    22,    23,
       7,     8,    39,    38,    38,    40,    30,     7,     8,    39,
      34,   114,   115,    37,     4,     5,     6,    65,    66,     9,
      10,    11,    12,    35,    35,    35,    34,    36,    18,    74,
      36,    36,    22,    23,    35,    13,    14,    15,    16,    17,
      30,    19,    34,    -1,    34,   125,    35,    37,     4,     5,
       6,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    59,    60,
      61,    62,    63,    64,    30,    -1,    -1,    -1,    34,    -1,
      -1,    37,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     9,    10,    11,    12,    18,
      22,    23,    30,    34,    42,    47,    48,    49,    52,    53,
      59,    60,    61,    62,    63,    64,    11,    11,    50,    51,
      11,    50,    34,    11,    11,     9,    10,    24,    25,    26,
      27,    28,    39,    11,    59,    61,    61,    63,    59,     0,
       4,     5,    48,    53,    59,    38,    20,    21,    38,    13,
      14,    15,    16,    17,    19,    29,    30,    31,    32,    33,
      34,    34,    39,    38,    40,    34,    38,    58,    59,    61,
      61,    61,    61,    61,    61,    35,    11,    38,    59,    59,
      60,    60,    60,    60,    60,    60,    62,    62,    63,    63,
      63,    45,    44,    61,    51,    43,    35,    38,    38,    38,
      38,    38,    38,    35,    35,    35,    36,    57,    36,    46,
      46,    46,    47,     7,     8,    54,    55,    37,    47,    37,
      56,    34,     8,    55,    37,    36,    58,    34,    47,    35,
      58,    37,    57,    35,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    42,    44,    42,    45,    42,    46,
      46,    47,    47,    47,    47,    47,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    53,    53,    53,    54,    54,    56,
      55,    57,    58,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     6,     0,     6,     0,     6,     3,
       2,     1,     2,     1,     2,     2,     3,     1,     4,     4,
       4,     4,     4,     4,     2,     3,     3,     3,     1,     3,
       1,     2,     2,     1,     5,     7,     6,     6,     5,     0,
       5,     3,     1,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     2,     1,     1,     1,     2,     2,     2,     2
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 57 "calc.y" /* yacc.c:1646  */
    { functionReturnTypeNumber = 1 ; }
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "calc.y" /* yacc.c:1646  */
    { if(functionReturnTypeNumber != 0 ){ printf("\n Error Function does not return any value \n")  ; exit(0); };  functionReturnTypeNumber = -1 ; }
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "calc.y" /* yacc.c:1646  */
    { functionReturnTypeNumber = 1 ; functionReturnsInt = 1 ; }
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "calc.y" /* yacc.c:1646  */
    { if(functionReturnTypeNumber != 0 ){ printf("\n Error Function does not return any value \n")  ; exit(0); };  functionReturnTypeNumber = -1 ; }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "calc.y" /* yacc.c:1646  */
    { functionReturnTypeVoid = 1 ;  }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 59 "calc.y" /* yacc.c:1646  */
    { functionReturnTypeVoid = -1 ; }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "calc.y" /* yacc.c:1646  */
    {;}
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "calc.y" /* yacc.c:1646  */
    {;}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "calc.y" /* yacc.c:1646  */
    {;}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "calc.y" /* yacc.c:1646  */
    {;}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "calc.y" /* yacc.c:1646  */
    {;}
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "calc.y" /* yacc.c:1646  */
    {;}
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { updateFloatVariable((yyvsp[-3].s),(yyvsp[-1].f)); } }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) {  Number v = getFloatVariableValue((yyvsp[-3].s)); updateFloatVariable((yyvsp[-3].s) , v.value+(yyvsp[-1].f)); } }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 77 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-3].s)); updateFloatVariable((yyvsp[-3].s) , v.value-(yyvsp[-1].f)); }}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-3].s)); updateFloatVariable((yyvsp[-3].s) , v.value*(yyvsp[-1].f)); }}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-3].s)); updateFloatVariable((yyvsp[-3].s) , v.value/(yyvsp[-1].f)); }}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 80 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-3].s)); updateFloatVariable((yyvsp[-3].s) , (int)(v.value)%(int)((yyvsp[-1].f))); }}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "calc.y" /* yacc.c:1646  */
    {;}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { integerVariableEncountered = 0; }  }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 85 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { integerVariableEncountered = 1 ; } }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { (yyval.n)=(yyvsp[0].n); addFloatVariable((yyvsp[0].n));} }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 89 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { (yyval.n)=(yyvsp[0].n); addFloatVariable((yyvsp[0].n)); }  }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v ; v.isInteger = integerVariableEncountered ; v.Name = (yyvsp[-2].s); v.value = (yyvsp[0].f)  ;  v.isIntitialized = 1 ; (yyval.n) = v; }}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v ; v.Name = (yyvsp[0].s); v.isIntitialized = 0; v.isInteger = integerVariableEncountered   ; v.value=-1; (yyval.n) = v; }}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 96 "calc.y" /* yacc.c:1646  */
    {   if(top()==1 || top()==-1 ) { printf(" \n printed  : %f \n",((yyvsp[0].f)));} }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "calc.y" /* yacc.c:1646  */
    {   if(functionReturnTypeVoid == 1){  printf("\n Function type void cannot return any value \n")  ; exit(0); };  if(top()==1 || top()==-1 ) { functionReturnTypeNumber = 0 ; functionReturnsInt == 1 ? printf(" \n returned : %d \n",(int)((yyvsp[0].f))) : printf(" \n returned : %f \n",(yyvsp[0].f)); functionReturnsInt = 0; exit(0);  } }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 98 "calc.y" /* yacc.c:1646  */
    {  if(top()==1 || top()==-1) { if(functionReturnTypeNumber == 1){ printf("\n Error Function type does not return a value \n")  ; exit(0); }; printf(" \n returned \n "); exit(0); } }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "calc.y" /* yacc.c:1646  */
    {  pop();  }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "calc.y" /* yacc.c:1646  */
    { pop(); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 103 "calc.y" /* yacc.c:1646  */
    { pop(); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 106 "calc.y" /* yacc.c:1646  */
    { ; }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 107 "calc.y" /* yacc.c:1646  */
    {  ; }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 111 "calc.y" /* yacc.c:1646  */
    {  if(top()==0 && parentAllowed()==1 ){  push(1); } else { push(0); }}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "calc.y" /* yacc.c:1646  */
    { pop(); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "calc.y" /* yacc.c:1646  */
    {  pop();  }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "calc.y" /* yacc.c:1646  */
    { 
                                         
                                        int topval = top(); 
                                        int result = (int)((yyvsp[0].f));  
                                        char * condition = (yyvsp[(-1) - (1)].s);
                                        actionHandler(topval, result , condition); 
                                      }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 126 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) || (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) || (yyvsp[0].f); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 127 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) && (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) && (yyvsp[0].f); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 128 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[0].f) == 0 ? 1 : 0 ; (yyval.f) = ((yyvsp[0].f) == 0 ? 1 : 0) ; }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 132 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) < (yyvsp[0].f) ;  (yyval.f) = (int)((yyvsp[-2].f) < (yyvsp[0].f)); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) > (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) > (yyvsp[0].f); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) >= (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) >= (yyvsp[0].f); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 135 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) <= (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) <= (yyvsp[0].f); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 136 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) != (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) != (yyvsp[0].f); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 137 "calc.y" /* yacc.c:1646  */
    {  int result = (yyvsp[-2].f) == (yyvsp[0].f) ;  (yyval.f) = (yyvsp[-2].f) == (yyvsp[0].f); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 138 "calc.y" /* yacc.c:1646  */
    {  (yyval.f) = (yyvsp[0].f); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[-2].f) + (yyvsp[0].f); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 143 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[-2].f) - (yyvsp[0].f); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 144 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[0].f); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 147 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[-2].f) * (yyvsp[0].f); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 148 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[-2].f)/(yyvsp[0].f); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 149 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (int)((yyvsp[-2].f))%(int)((yyvsp[0].f)); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 150 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[0].f); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 153 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = ((yyvsp[-1].f)); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 154 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = -1*(yyvsp[0].f); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 155 "calc.y" /* yacc.c:1646  */
    { (yyval.f) = (yyvsp[0].f); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 158 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) {(yyval.f) = (yyvsp[0].f);} }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 159 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[0].s)); printInt = !v.isInteger; (yyval.f) = v.value; }}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 160 "calc.y" /* yacc.c:1646  */
    {if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-1].s)); updateFloatVariable(v.Name,v.value+1); printInt = !v.isInteger; (yyval.f) = v.value; }}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 161 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[-1].s)); updateFloatVariable(v.Name,v.value-1); printInt = !v.isInteger; (yyval.f) = v.value; }}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 162 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[0].s)); updateFloatVariable(v.Name,v.value+1); printInt = !v.isInteger; (yyval.f) = v.value+1; }}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 163 "calc.y" /* yacc.c:1646  */
    { if(top()==1 || top()==-1 ) { Number v = getFloatVariableValue((yyvsp[0].s)); updateFloatVariable(v.Name,v.value-1); printInt = !v.isInteger; (yyval.f) = v.value-1; }}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1781 "y.tab.c" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 165 "calc.y" /* yacc.c:1906  */


void yyerror(char *msg){
    fprintf(stderr,"%s on the line\n",msg);
    exit(1);
}

int main(){
    for(int x=0 ; x< MAX_SLOT ; x++){
      FloatVariableTable[x].Name = "";
      FloatVariableTable[x].Type = "Float";
      FloatVariableTable[x].value = 0.0;
      stack[x] = -1;
    };

    yyparse();
    return 0;
}


void actionHandler(int stackTop, int conditionResult, char *condition)
{
    int absoluteTop = stack[0];
    
    if (absoluteTop == -1)
    {
        push(conditionResult);
        push(conditionResult);
    }
    else
    {
        if (stackTop == 0)
        {
            if (isIF(condition) == 1)
            {
                push(0);
                push(0);
                elseAllowed = 0;
            }
            else if (top() == 0 && isELSEIF(condition) == 1 && parentAllowed() == 1)
            {   
                pop();
                push(conditionResult);
                push(conditionResult);
                elseAllowed = (int)(conditionResult == 1 ? 0 : 1);
                
            }
            else
            {
                push(0);
                // 
                elseAllowed == 1;
            }
        }
        else
        {
            if (isIF(condition) == 1)
            {
                push(conditionResult);
                push(conditionResult);
                elseAllowed = !conditionResult;
            }
            else
            {
                push(0);
                elseAllowed = 1;
            }
        }
    }
}
