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
#line 1 "icg.y" /* yacc.c:339  */
 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "symboltable.c" 
int flag=0; 
int indent=0;
int k;
extern int yylineno;
int fun_indent(int i);
void fun_cond(int i);
int yywrap();
extern int curLn;
extern int curPos;
extern FILE *yyin;
int type_flag=0;
extern FILE *yyout;
extern int line;
extern char ident[30];
extern char val[30];
extern int scope;
FILE *outfile;



	// ------------------------- Used for AST -------------------------
	

typedef struct node{
	char value[50];
	char expr_result[15];
	char reg_name[15];
	struct node *left;
	struct node *right;
}node;
//typedef struct node node;
	node* make_node(char *,node *,node *);
	void print_tree_pre(node *);
	void print_tree_in(node *);
	void print_tree_post(node *);
// ------------------------- Used for ICG --------------------------
	struct quad
	{
		char op[5];
		char arg1[10];
		char arg2[10];
		char result[10];
		int scope;
		char block[10];
		int indi;
		char actual_result[10];
	}QUAD[500];
	struct quad sub_QUAD[500];
	int sub_Index = 0;
	int sub_rIndex=0;
	//char* store=malloc(sizeof(char)*20);
	//char *store=malloc(sizeof(char)*10);
	int folding=0;
	void sub_add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi);
	char * search_in_quad(char* op,char *arg1,char* arg2);
	int number;
	extern int scope_count;
	int Index = 0;
	int rIndex=0; 
	int offset = 0;
	void add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi,char *actual_re);
	char for_k_liye[10];
	// extra implementations
	struct stack 
	{
		char label[10][10];
		int top;
	}stk;
	void push(char *label);	
	void pop();
	char* get_top();
	void eprint(struct quad);
	void eprint2(struct quad);
//--------------------------------------------------------------------------------

Node* head=NULL;
int yylex();
void yyerror(char *s);

#line 152 "y.tab.c" /* yacc.c:339  */

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
    T_ASSIGN = 258,
    T_REL_OP = 259,
    T_LOGIC = 260,
    T_KEY = 261,
    T_ID = 262,
    T_STRING = 263,
    T_DIGIT = 264,
    T_IF = 265,
    T_FOR = 266,
    T_INT = 267,
    T_SPLIT = 268,
    T_LIST = 269,
    T_INPUT = 270,
    T_RANGE = 271,
    T_PRINT = 272,
    T_ELSE = 273,
    T_ELIF = 274,
    T_TRUE = 275,
    T_FALSE = 276,
    T_AND = 277,
    T_OR = 278,
    T_NOT = 279,
    T_LIST_OP = 280,
    T_IN = 281,
    T_star = 282,
    T_minus = 283,
    T_LT = 284,
    T_GT = 285,
    T_GE = 286,
    T_LE = 287,
    T_EEQ = 288,
    T_NEQ = 289,
    NEWLINE = 290,
    T_INDENT = 291,
    T_space = 292
  };
#endif
/* Tokens.  */
#define T_ASSIGN 258
#define T_REL_OP 259
#define T_LOGIC 260
#define T_KEY 261
#define T_ID 262
#define T_STRING 263
#define T_DIGIT 264
#define T_IF 265
#define T_FOR 266
#define T_INT 267
#define T_SPLIT 268
#define T_LIST 269
#define T_INPUT 270
#define T_RANGE 271
#define T_PRINT 272
#define T_ELSE 273
#define T_ELIF 274
#define T_TRUE 275
#define T_FALSE 276
#define T_AND 277
#define T_OR 278
#define T_NOT 279
#define T_LIST_OP 280
#define T_IN 281
#define T_star 282
#define T_minus 283
#define T_LT 284
#define T_GT 285
#define T_GE 286
#define T_LE 287
#define T_EEQ 288
#define T_NEQ 289
#define NEWLINE 290
#define T_INDENT 291
#define T_space 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "icg.y" /* yacc.c:355  */

struct node *np;
	char var[10];

#line 271 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      43,    44,    40,    38,    48,    39,    45,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   102,   102,   102,   116,   116,   116,   116,   116,   116,
     116,   116,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   120,   120,   120,   120,   120,   120,   120,   120,   122,
     122,   123,   123,   123,   125,   125,   125,   125,   125,   125,
     126,   127,   128,   128,   129,   129,   131,   131,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   141,   141,   142,
     144,   144,   146,   146,   147,   147,   149,   149,   149,   149,
     149,   150,   150,   153,   153,   155,   155,   157,   157,   159,
     159,   159,   159,   161,   161,   161,   162,   166,   166,   167,
     167,   167,   168,   168,   169,   169,   169,   170,   170,   170,
     170,   170,   170,   172,   172,   172,   173,   173,   173,   173,
     175,   177,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ASSIGN", "T_REL_OP", "T_LOGIC",
  "T_KEY", "T_ID", "T_STRING", "T_DIGIT", "T_IF", "T_FOR", "T_INT",
  "T_SPLIT", "T_LIST", "T_INPUT", "T_RANGE", "T_PRINT", "T_ELSE", "T_ELIF",
  "T_TRUE", "T_FALSE", "T_AND", "T_OR", "T_NOT", "T_LIST_OP", "T_IN",
  "T_star", "T_minus", "T_LT", "T_GT", "T_GE", "T_LE", "T_EEQ", "T_NEQ",
  "NEWLINE", "T_INDENT", "T_space", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'('", "')'", "'.'", "'['", "']'", "','", "':'", "$accept",
  "PHASE_START", "$@1", "START", "$@2", "START_FOR_INDENT", "$@3", "$@4",
  "$@5", "$@6", "INTERMEDIATE", "$@7", "$@8", "$@9", "$@10",
  "INDENT_GRAMMER", "$@11", "GOP", "$@12", "SIMPLE_STMT", "A", "B", "UI",
  "GI", "ASSIGN", "E", "T", "F", "Q", "VAR", "L", "M", "REL_OP", "LIST_OP",
  "COND", "AND_STMT", "NOT_STMT", "N", "REL_EXP", "INNER_SUITE", "$@13",
  "INNER_IF", "$@14", "$@15", "SUITE", "$@16", "IF_STMT", "$@17", "$@18",
  "ELIF_STMT", "$@19", "$@20", "$@21", "FOR_STMT", "$@22", "$@23",
  "TARGET", "C", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    43,    45,
      42,    47,    37,    40,    41,    46,    91,    93,    44,    58
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -12

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -183,    10,    82,  -183,  -183,    26,  -183,  -183,    13,    66,
      75,    87,  -183,  -183,    80,  -183,  -183,   108,    82,    82,
      30,   111,   148,   141,   146,   154,    62,    82,    82,    82,
    -183,  -183,  -183,  -183,  -183,    62,     7,  -183,    72,     0,
    -183,   136,  -183,  -183,    12,   138,   122,   123,   124,   125,
    -183,   126,   128,   118,  -183,  -183,  -183,  -183,    91,  -183,
     129,    62,    62,    62,    62,    62,  -183,  -183,    12,    12,
     116,   -11,   -16,   149,  -183,  -183,  -183,    41,   154,  -183,
    -183,  -183,   130,  -183,    62,  -183,  -183,     0,     0,  -183,
    -183,  -183,  -183,   -10,  -183,  -183,  -183,  -183,  -183,  -183,
     144,   131,    70,    12,   132,    12,  -183,   135,  -183,  -183,
     139,   160,  -183,  -183,  -183,  -183,  -183,  -183,   149,   145,
    -183,    97,   133,  -183,   142,  -183,  -183,  -183,  -183,    59,
     145,   140,   143,    56,  -183,    97,  -183,  -183,  -183,  -183,
     127,  -183,  -183,  -183,    92,   150,  -183,   152,   153,   155,
     156,   147,   151,  -183,    97,  -183,  -183,   157,  -183,  -183,
    -183,  -183,   145,    12,   158,   150,    12,   143,   143,   143,
     143,  -183,    57,  -183,  -183,    58,  -183,   127,  -183,  -183,
    -183,   159,   161,   162,   163,   164,   166,   145,   168,  -183,
    -183,  -183,  -183,  -183,  -183,   143,   143,   143,   143,    56,
    -183,   143,  -183,  -183,  -183,  -183,  -183,    56,  -183,  -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     8,     0,    94,   103,     0,     0,
       0,     0,     9,     3,     0,    38,    39,     0,     0,     0,
       0,     0,     0,     0,     0,    45,    43,     0,     0,     0,
       6,     5,    59,    61,    60,     0,     0,    47,    46,    50,
      53,    55,    58,    56,     0,     0,     0,     0,     0,     0,
      44,     0,     0,    65,    42,    10,     7,     4,     0,    63,
       0,     0,     0,     0,     0,     0,    81,    82,     0,     0,
       0,     0,     0,    74,    76,    78,    80,     0,    45,    34,
      36,    35,    40,    37,     0,    57,    62,    49,    48,    51,
      52,    54,    77,     0,    66,    67,    68,    69,    71,    72,
       0,    70,     0,     0,     0,     0,   109,     0,   110,   104,
       0,     0,    64,    79,    83,    85,    86,    84,    73,     0,
      75,     0,     0,    40,     0,    92,    95,   111,   112,     0,
       0,     0,     0,   102,   106,     0,   105,    41,    29,    93,
       0,   100,    97,    96,     0,    33,    89,     0,     0,     0,
       0,     0,     0,   107,     0,    31,    30,     0,    27,    21,
      25,    23,     0,     0,     0,    33,     0,    20,    20,    20,
      20,   101,     0,   108,    32,     0,    28,     0,    22,    26,
      24,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      12,    16,    14,    98,    87,    20,    20,    20,    20,   102,
      90,     0,    19,    13,    17,    15,    99,   102,    88,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,   104,  -183,   -84,  -183,  -183,  -183,  -183,
     -27,  -183,  -183,  -183,  -183,  -129,  -183,    24,  -183,   -20,
      67,   169,  -183,   114,  -131,   170,    65,    95,   -18,   -38,
     -42,   -32,  -183,   165,   -68,   101,   -56,  -183,  -183,  -183,
    -183,    18,  -183,  -183,  -119,  -183,  -183,  -183,  -183,  -182,
    -183,  -183,  -183,   -89,  -183,  -183,  -183,  -130
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,    27,   176,   196,   198,   197,   195,
     139,   168,   170,   169,   167,   177,   145,   156,   165,    14,
      15,    16,    52,    51,    17,    38,    39,    40,    41,    42,
      43,    54,   100,   101,    72,    73,    74,    75,    76,   200,
     201,   149,   157,   207,   126,   132,    18,    21,   133,   143,
     152,   199,   151,    19,    22,   122,   109,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    93,    71,   140,    60,   144,    70,   103,    53,   148,
       3,   136,    92,   103,    32,    33,    34,   206,    53,    32,
      33,    34,    98,    99,   164,   209,    71,    71,   104,    20,
      70,    70,    66,    67,   113,   108,    68,    32,    33,    34,
      63,    64,     8,   171,     9,    10,   184,    11,   106,   120,
      35,   150,   112,    36,    59,    69,    23,   107,    36,   115,
     117,    71,   114,    71,   116,    70,    53,    70,   193,    32,
      33,    34,   140,    35,   141,   142,    36,    32,    33,    34,
     103,   103,   -11,     4,   178,   179,   180,    36,   186,     5,
      47,    48,     6,     7,     8,   172,     9,    10,   175,    11,
      61,   181,   182,   134,   127,    35,   128,   135,    36,    24,
      62,   202,   203,   204,   205,    28,    36,    12,    25,    61,
     147,    71,    30,    31,    71,    70,    87,    88,    70,    62,
      26,    55,    56,    57,     5,    85,   153,   146,     7,     8,
     154,     9,    10,    29,    11,    94,    95,    96,    97,    98,
      99,    32,    33,    34,    44,    45,    46,   183,    89,    90,
      91,    10,    50,    65,    77,    78,    84,    79,    80,    81,
      82,   105,    83,   124,   208,   111,    86,    36,   121,   138,
     125,   119,   130,   123,   137,   131,   155,   158,   159,   174,
     160,   161,   110,    49,   163,   185,   162,   189,   190,   191,
     166,   192,   173,   194,   118,    58,     0,     0,   187,     0,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      20,    69,    44,   132,    36,   135,    44,    23,    26,   140,
       0,   130,    68,    23,     7,     8,     9,   199,    36,     7,
       8,     9,    33,    34,   154,   207,    68,    69,    44,     3,
      68,    69,    20,    21,    44,    77,    24,     7,     8,     9,
      40,    41,    12,   162,    14,    15,   177,    17,     7,   105,
      43,   140,    84,    46,    47,    43,    43,    16,    46,   101,
     102,   103,   100,   105,   102,   103,    84,   105,   187,     7,
       8,     9,   201,    43,    18,    19,    46,     7,     8,     9,
      23,    23,     0,     1,   168,   169,   170,    46,   177,     7,
      23,    24,    10,    11,    12,   163,    14,    15,   166,    17,
      28,    44,    44,    44,     7,    43,     9,    48,    46,    43,
      38,   195,   196,   197,   198,    35,    46,    35,    43,    28,
     140,   163,    18,    19,   166,   163,    61,    62,   166,    38,
      43,    27,    28,    29,     7,    44,    44,    10,    11,    12,
      48,    14,    15,    35,    17,    29,    30,    31,    32,    33,
      34,     7,     8,     9,    43,     7,    15,   177,    63,    64,
      65,    15,     8,    27,    26,    43,    48,    44,    44,    44,
      44,    22,    44,    13,   201,    45,    47,    46,    43,    36,
      35,    49,    49,    44,    44,    43,    36,    35,    35,   165,
      35,    35,    78,    24,    43,   177,    49,    35,    35,    35,
      43,    35,    44,    35,   103,    35,    -1,    -1,    49,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,     1,     7,    10,    11,    12,    14,
      15,    17,    35,    53,    69,    70,    71,    74,    96,   103,
       3,    97,   104,    43,    43,    43,    43,    54,    35,    35,
      53,    53,     7,     8,     9,    43,    46,    69,    75,    76,
      77,    78,    79,    80,    43,     7,    15,    70,    70,    71,
       8,    73,    72,    78,    81,    53,    53,    53,    75,    47,
      81,    28,    38,    40,    41,    27,    20,    21,    24,    43,
      79,    80,    84,    85,    86,    87,    88,    26,    43,    44,
      44,    44,    44,    44,    48,    44,    47,    76,    76,    77,
      77,    77,    86,    84,    29,    30,    31,    32,    33,    34,
      82,    83,    83,    23,    44,    22,     7,    16,    80,   106,
      73,    45,    81,    44,    79,    80,    79,    80,    85,    49,
      86,    43,   105,    44,    13,    35,    94,     7,     9,   107,
      49,    43,    95,    98,    44,    48,    94,    44,    36,    60,
      65,    18,    19,    99,   107,    66,    10,    69,    74,    91,
     103,   102,   100,    44,    48,    36,    67,    92,    35,    35,
      35,    35,    49,    43,   107,    68,    43,    64,    61,    63,
      62,    94,    84,    44,    67,    84,    55,    65,    55,    55,
      55,    44,    44,    69,    74,    91,   103,    49,    49,    35,
      35,    35,    35,    94,    35,    59,    56,    58,    57,   101,
      89,    90,    55,    55,    55,    55,    99,    93,    60,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    53,    53,    53,    53,    53,    54,
      53,    53,    56,    55,    57,    55,    58,    55,    59,    55,
      55,    61,    60,    62,    60,    63,    60,    64,    60,    66,
      65,    68,    67,    67,    69,    69,    69,    69,    69,    69,
      70,    71,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    88,    88,    88,    88,    90,    89,    92,
      93,    91,    95,    94,    97,    98,    96,   100,   101,    99,
     102,    99,    99,   104,   105,   103,   106,   106,   106,   106,
     106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     2,     3,     1,     0,
       3,     0,     0,     5,     0,     5,     0,     5,     0,     5,
       0,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       3,     0,     3,     0,     4,     4,     4,     4,     1,     1,
       4,     8,     1,     0,     1,     0,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     3,     3,     3,     3,     0,     2,     0,
       0,    10,     0,     3,     0,     0,     9,     0,     0,     9,
       0,     4,     0,     0,     0,     8,     4,     6,     8,     1,
       1,     1,     1
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
        case 2:
#line 102 "icg.y" /* yacc.c:1646  */
    {push("main");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "icg.y" /* yacc.c:1646  */
    {	//printf("asdf");
						
						printf("\n %s \n",get_top());
						(yyval.np) = make_node("PROGRAM", (yyvsp[0].np), NULL);
						printf("\nPreorder Traversal \n"); 
						print_tree_pre((yyval.np));
						printf("\nInorder Traversal \n"); 
						print_tree_in((yyval.np)); 
						printf("\nPostorder Traversal \n");
						print_tree_post((yyval.np));
						pop();
					 }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-2].np), (yyvsp[0].np));}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-1].np), (yyvsp[0].np));}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-1].np), (yyvsp[0].np));}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-2].np), (yyvsp[0].np));}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[0].np), NULL);}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 118 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 118 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 118 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 118 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 118 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 120 "icg.y" /* yacc.c:1646  */
    {k=0;printf("ay a %s\n",get_top());}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("FOR_STATEMENT", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 120 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("IF_STATEMENT", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 120 "icg.y" /* yacc.c:1646  */
    {k=0;}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 120 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("", (yyvsp[-3].np), (yyvsp[0].np));}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 122 "icg.y" /* yacc.c:1646  */
    {fun_cond(fun_indent(0));}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 122 "icg.y" /* yacc.c:1646  */
    {int uy=indent-k;printf("art %d %d\n",indent,k);while(uy>0){pop();uy-=1;}indent=k;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 123 "icg.y" /* yacc.c:1646  */
    {fun_cond(fun_indent(0));}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("INT", (yyvsp[-1].np), NULL);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("LIST", (yyvsp[-1].np), NULL);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("LIST", (yyvsp[-1].np), NULL);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("PRINT", (yyvsp[-1].np), NULL);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 125 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 126 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("INPUT", (yyvsp[-1].np), NULL);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 127 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("INPUT_SPLIT", (yyvsp[-5].np), NULL);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 128 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var), NULL, NULL);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 129 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "icg.y" /* yacc.c:1646  */
    {head=pushIntoTable(head,line,(char*)(yyvsp[-2].var),(char*)(yyvsp[0].np)->expr_result,scope,type_flag);strcpy(val,"-");strcpy(ident,"-");	(yyval.np)=make_node("=", make_node((yyvsp[-2].var),NULL,NULL), (yyvsp[0].np));add_quadruple("=",(yyvsp[0].np)->reg_name,"",(yyvsp[-2].var),0,0,(yyvsp[0].np)->expr_result);sub_add_quadruple("=",(yyvsp[0].np)->reg_name,"",(yyvsp[-2].var),0,0);}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "icg.y" /* yacc.c:1646  */
    {head=pushIntoTable(head,line,(char*)(yyvsp[-2].var),(char*)(yyvsp[0].np)->expr_result,scope,type_flag);strcpy(val,"-");strcpy(ident,"-");(yyval.np)=make_node("=", make_node((yyvsp[-2].var),NULL,NULL), (yyvsp[0].np));	}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 133 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("+",(yyvsp[-2].np),(yyvsp[0].np));
     			sprintf((yyval.np)->expr_result, "%d",(atoi((yyvsp[-2].np)->expr_result) + atoi((yyvsp[0].np)->expr_result)));char store[100];strcpy(store,search_in_quad("+",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",(yyval.np)->reg_name,1,0);}else{sub_add_quadruple("+",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0);}add_quadruple("+",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0,(yyval.np)->expr_result);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 134 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("-",(yyvsp[-2].np),(yyvsp[0].np));
     			sprintf((yyval.np)->expr_result, "%d",(atoi((yyvsp[-2].np)->expr_result) - atoi((yyvsp[0].np)->expr_result)));char store[100];strcpy(store,search_in_quad("-",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",(yyval.np)->reg_name,1,0);}else{sub_add_quadruple("-",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0);}add_quadruple("-",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0,(yyval.np)->expr_result);}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 135 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 136 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("*",(yyvsp[-2].np),(yyvsp[0].np));
     			sprintf((yyval.np)->expr_result, "%d",(atoi((yyvsp[-2].np)->expr_result) * atoi((yyvsp[0].np)->expr_result)));char store[100];strcpy(store,search_in_quad("*",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",(yyval.np)->reg_name,1,0);}else{sub_add_quadruple("*",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0);}add_quadruple("*",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0,(yyval.np)->expr_result);}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 137 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("/",(yyvsp[-2].np),(yyvsp[0].np));
     			sprintf((yyval.np)->expr_result, "%d",(atoi((yyvsp[-2].np)->expr_result) / atoi((yyvsp[0].np)->expr_result)));char store[100];strcpy(store,search_in_quad("/",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",(yyval.np)->reg_name,1,0);}else{sub_add_quadruple("/",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0);}add_quadruple("/",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0,(yyval.np)->expr_result);}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 138 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 139 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("**",(yyvsp[-2].np),(yyvsp[0].np));
     			sprintf((yyval.np)->expr_result, "%d",(atoi((yyvsp[-2].np)->expr_result) ^ atoi((yyvsp[0].np)->expr_result)));char store[100];strcpy(store,search_in_quad("**",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name));if(strcmp(store,"0")!=0){sub_add_quadruple("=",store,"",(yyval.np)->reg_name,1,0);}else{sub_add_quadruple("**",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0);}add_quadruple("**",(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,0,(yyval.np)->expr_result);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 141 "icg.y" /* yacc.c:1646  */
    {type_flag=2;(yyval.np)=(yyvsp[0].np);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 141 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[-1].np);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 141 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 142 "icg.y" /* yacc.c:1646  */
    {type_flag=-1;(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);sprintf((yyval.np)->expr_result,"%d",	(atoi(search_symbol_table(head,(yyvsp[0].var)))));
     			
     			strcpy((yyval.np)->reg_name,(yyvsp[0].var));}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 144 "icg.y" /* yacc.c:1646  */
    {type_flag=0;(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);strcpy((yyval.np)->expr_result,(yyvsp[0].var));strcpy((yyval.np)->reg_name,(yyvsp[0].var));}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 144 "icg.y" /* yacc.c:1646  */
    {type_flag=1;(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);strcpy((yyval.np)->expr_result,(yyvsp[0].var));strcpy((yyval.np)->reg_name,(yyvsp[0].var));}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 146 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("LIST",(yyvsp[-1].np),NULL);}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 146 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("LIST_EMPTY",NULL,NULL);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 147 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("",(yyvsp[-2].np),(yyvsp[0].np));}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 147 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 149 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 149 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 149 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 149 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 149 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 150 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 150 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 153 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].var),(yyvsp[-2].np),(yyvsp[0].np));sprintf((yyval.np)->expr_result,"%d",(atoi((yyvsp[-2].np)->expr_result) || atoi((yyvsp[0].np)->expr_result)));sub_add_quadruple((yyvsp[-1].var),(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[-1].var),(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1,"");}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 153 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 155 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].var),(yyvsp[-2].np),(yyvsp[0].np)); sprintf((yyval.np)->expr_result,"%d",(atoi((yyvsp[-2].np)->expr_result) && atoi((yyvsp[0].np)->expr_result)));sub_add_quadruple((yyvsp[-1].var),(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[-1].var),(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1,"");}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 155 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 157 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].var),(yyvsp[0].np),NULL); sprintf((yyval.np)->expr_result,"%d",(!atoi((yyvsp[0].np)->expr_result)));sub_add_quadruple((yyvsp[-1].var),(yyvsp[0].np)->reg_name,"",(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[-1].var),(yyvsp[0].np)->reg_name,"",(yyval.np)->reg_name,1,1,"");}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 157 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 159 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[-1].np);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 159 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 159 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[0].var),NULL,NULL); sprintf((yyval.np)->expr_result,"%d",(1));strcpy((yyval.np)->reg_name,"1");sub_add_quadruple((yyvsp[0].var),"","",(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[0].var),"","",(yyval.np)->reg_name,1,1,"");}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 159 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[0].var),NULL,NULL); sprintf((yyval.np)->expr_result,"%d",(0));strcpy((yyval.np)->reg_name,"0");sub_add_quadruple((yyvsp[0].var),"","",(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[0].var),"","",(yyval.np)->reg_name,1,1,"");}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 161 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].np)->value,(yyvsp[-2].np),(yyvsp[0].np)); sprintf((yyval.np)->expr_result,"%d",(getValue(atoi((yyvsp[-2].np)->expr_result),atoi((yyvsp[0].np)->expr_result),(yyvsp[-1].np)->value)));strcpy((yyval.np)->reg_name,(yyval.np)->expr_result);sub_add_quadruple((yyvsp[-1].np)->value,(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1);add_quadruple((yyvsp[-1].np)->value,(yyvsp[-2].np)->reg_name,(yyvsp[0].np)->reg_name,(yyval.np)->reg_name,1,1,"");}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 161 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].np)->value,(yyvsp[-2].np),(yyvsp[0].np)); sprintf((yyval.np)->expr_result,"%d",(0));strcpy((yyval.np)->reg_name,(yyval.np)->expr_result);sub_add_quadruple((yyvsp[-1].np)->value,"LIST","LIST","",0,1);add_quadruple((yyvsp[-1].np)->value,"LIST","LIST","",0,1,"");}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 161 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].np)->value,(yyvsp[-2].np),(yyvsp[0].np));sprintf((yyval.np)->expr_result,"%d",(0));strcpy((yyval.np)->reg_name,(yyval.np)->expr_result);sub_add_quadruple((yyvsp[-1].np)->value,(yyvsp[-2].np)->reg_name,"LIST","",0,1);add_quadruple((yyvsp[-1].np)->value,(yyvsp[-2].np)->reg_name,"LIST","",0,1,"");}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 162 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node((yyvsp[-1].np)->value,(yyvsp[-2].np),(yyvsp[0].np));sprintf((yyval.np)->expr_result,"%d",(0));strcpy((yyval.np)->reg_name,(yyval.np)->expr_result);sub_add_quadruple((yyvsp[-1].np)->value,"LIST",(yyvsp[0].np)->reg_name,"",0,1);add_quadruple((yyvsp[-1].np)->value,"LIST",(yyvsp[0].np)->reg_name,"",0,1,"");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 166 "icg.y" /* yacc.c:1646  */
    {k=0;indent++;}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 166 "icg.y" /* yacc.c:1646  */
    {fun_cond(fun_indent(1));(yyval.np) = (yyvsp[0].np);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 167 "icg.y" /* yacc.c:1646  */
    { push("if"); offset++; }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 167 "icg.y" /* yacc.c:1646  */
    {offset--; }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 167 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("IF",(yyvsp[-6].np),make_node("",(yyvsp[-2].np),(yyvsp[0].np)));}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 168 "icg.y" /* yacc.c:1646  */
    {k=0;indent++;}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 168 "icg.y" /* yacc.c:1646  */
    {fun_cond(fun_indent(1));(yyval.np) = (yyvsp[0].np);}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 169 "icg.y" /* yacc.c:1646  */
    { push("if"); offset++; }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 169 "icg.y" /* yacc.c:1646  */
    {offset--;}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 169 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("IF",(yyvsp[-5].np),make_node("",(yyvsp[-2].np),(yyvsp[0].np)));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 170 "icg.y" /* yacc.c:1646  */
    { push("elif"); offset++; }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 170 "icg.y" /* yacc.c:1646  */
    {offset--; }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 170 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("ELIF",(yyvsp[-5].np),make_node("",(yyvsp[-2].np),(yyvsp[0].np)));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 170 "icg.y" /* yacc.c:1646  */
    { push("else"); }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 170 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("ELSE",NULL,(yyvsp[0].np));}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 170 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=NULL;}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 172 "icg.y" /* yacc.c:1646  */
    { push("for"); offset++; }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 172 "icg.y" /* yacc.c:1646  */
    {if((yyvsp[0].np)->right==NULL){sub_add_quadruple("=","0","",(yyvsp[-2].var),0,0);add_quadruple("=","0","",(yyvsp[-2].var),0,0,"");sub_add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->left->value,(yyvsp[0].np)->reg_name,1,1);add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->left->value,(yyvsp[0].np)->reg_name,1,1,"");strcpy(for_k_liye,"1");}else if((yyvsp[0].np)->right->left==NULL){sub_add_quadruple("=",(yyvsp[0].np)->left->value,"",(yyvsp[-2].var),0,0);add_quadruple("=",(yyvsp[0].np)->left->value,"",(yyvsp[-2].var),0,0,"");sub_add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->right->value,(yyvsp[0].np)->reg_name,1,1);add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->right->value,(yyvsp[0].np)->reg_name,1,1,"");strcpy(for_k_liye,"1");}else{sub_add_quadruple("=",(yyvsp[0].np)->left->value,"",(yyvsp[-2].var),0,0);add_quadruple("=",(yyvsp[0].np)->left->value,"",(yyvsp[-2].var),0,0,"");sub_add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->right->left->value,(yyvsp[0].np)->reg_name,1,1);add_quadruple("<",(yyvsp[-2].var),(yyvsp[0].np)->right->left->value,(yyvsp[0].np)->reg_name,1,1,"");strcpy(for_k_liye,(yyvsp[0].np)->right->right->value);}}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 172 "icg.y" /* yacc.c:1646  */
    {(yyval.np) = make_node("FOR",make_node("COND",make_node((yyvsp[-5].var),NULL,NULL),(yyvsp[-3].np)),(yyvsp[0].np));push("for");offset++;sub_add_quadruple("+",(yyvsp[-5].var),for_k_liye,(yyvsp[-5].var),0,2);add_quadruple("+",(yyvsp[-5].var),for_k_liye,(yyvsp[-5].var),0,2,"");pop(); offset-=2;}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 173 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("range",(yyvsp[-1].np),NULL);}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 173 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("range",(yyvsp[-3].np),(yyvsp[-1].np));}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 173 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node("range",(yyvsp[-5].np),make_node("",(yyvsp[-3].np),(yyvsp[-1].np)));}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 173 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);sprintf((yyval.np)->expr_result,"%d",(atoi(search_symbol_table(head,(yyvsp[0].var)))));
     			
     			strcpy((yyval.np)->reg_name,(yyvsp[0].var)); }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 175 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=(yyvsp[0].np);}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 177 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);sprintf((yyval.np)->expr_result,"%d",	(atoi(search_symbol_table(head,(yyvsp[0].var)))));
     			
     			strcpy((yyval.np)->reg_name,(yyvsp[0].var));}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 179 "icg.y" /* yacc.c:1646  */
    {(yyval.np)=make_node((yyvsp[0].var),NULL,NULL);strcpy((yyval.np)->expr_result,(yyvsp[0].var));strcpy((yyval.np)->reg_name,(yyvsp[0].var));}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2197 "y.tab.c" /* yacc.c:1646  */
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
#line 180 "icg.y" /* yacc.c:1906  */
 
node *make_node(char *value, node *left, node *right) 
{
	node *new_node = malloc(sizeof(node));
	strcpy(new_node->value, value);	
	new_node -> left = left;
	new_node -> right = right;
	return new_node;
}

void print_tree_pre(node *root)
{
	if (root == NULL)
		return;
	printf("%s ", root->value);
	print_tree_pre(root->left);	
	print_tree_pre(root->right);	
}

void print_tree_in(node *root)
{
	if (root == NULL)
		return;
	print_tree_in(root->left);
	printf("%s ", root->value);
	print_tree_in(root->right);
}

void print_tree_post(node *root)
{
	if (root == NULL)
		return;
	print_tree_post(root->left);	
	print_tree_post(root->right);
	printf("%s ", root->value);
}
//--------------------sub_expression--------------------------------------
void sub_add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi)
{	 
	strcpy(sub_QUAD[sub_Index].op,op);
	
	strcpy(sub_QUAD[sub_Index].arg1,arg1);
	strcpy(sub_QUAD[sub_Index].arg2,arg2);
	sub_QUAD[sub_Index].indi=indi;
	if(option == 0)
	{
		strcpy(sub_QUAD[sub_Index].result,result);
	}
	else
	{
		sprintf(sub_QUAD[sub_Index].result,"r%d",sub_rIndex++);
		strcpy(result,sub_QUAD[sub_Index].result); 
	}	
	//printf("aer %s\n",get_top());	
	strcpy(sub_QUAD[sub_Index].block,get_top());
	//QUAD[Index++].scope = scope_count + offset;
	//if(strcmp(QUAD[Index].block,"for")==0)
	//printf("asdf %d %d %s %s\n",indent,offset,QUAD[Index].arg1,QUAD[Index].op);
	sub_QUAD[sub_Index++].scope =indent+offset;//done by me
}

// ----------------------------- ICG -------------------------------------
void add_quadruple(char *op,char *arg1,char *arg2,char *result,int option,int indi,char *actual_re)
{	 
	strcpy(QUAD[Index].op,op);
	
	strcpy(QUAD[Index].arg1,arg1);
	strcpy(QUAD[Index].arg2,arg2);
	QUAD[Index].indi=indi;
	if(option == 0)
	{
		strcpy(QUAD[Index].result,result);
	}
	else
	{
		sprintf(QUAD[Index].result,"r%d",rIndex++);
		strcpy(result,QUAD[Index].result); 
	}	
	strcpy(QUAD[Index].actual_result,actual_re);
	//printf("aer %s\n",get_top());	
	strcpy(QUAD[Index].block,get_top());
	//QUAD[Index++].scope = scope_count + offset;
	//if(strcmp(QUAD[Index].block,"for")==0)
	//printf("asdf %d %d %s %s\n",indent,offset,QUAD[Index].arg1,QUAD[Index].op);
	QUAD[Index++].scope =indent+offset;//done by me
}

void print_3addr_code()
{
	printf("\t\t\t\t Quadruples \t\t\t\t\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t","pos","op","arg1","arg2","result");
	printf("\n\t------------------------------------------------------------------------");
	for(int i=0;i<Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t", i,QUAD[i].op, QUAD[i].arg1,QUAD[i].arg2,QUAD[i].result);
	}
	printf("\n\n\n\n");
	
	// printing in proper 3 address code
	int label_no = 1;
	int add_label = 0;
	int label_stk[20];
	int ltop = -1;

	char gotos[20][10];
	int fstates = 0;
	struct fsteps{
		int start_index;
		int step;
	}fsteps[1000];
	int ftop = -1;
	int estart = 1;
	int infor = 0;
	int for_k[1000];
	int for_k_value=0;
	int for_go[1000];
	int for_go_value=0;
	for(int i=0; i<Index; i++)
	{	//printf("inner %s %d %d %s \n",QUAD[i].block,QUAD[i].scope,QUAD[i-1].scope,QUAD[i].op);
		// statements in same scope or within blocks
		if(i != 0 && QUAD[i].scope >= QUAD[i-1].scope){
			
			//if(QUAD[i-1].scope != QUAD[i].scope)
			//if( strcmp(QUAD[i].block,"elif") != 0 && (strcmp(QUAD[i-1].block,"while") == 0 || (strcmp(QUAD[i-1].block,"for") == 0) || (strcmp(QUAD[i-1].block,"if") == 0)))
			//{
			//printf("L%d:\n",label_stk[ltop]);
			//}

			if(strcmp(QUAD[i].block,"main") == 0)
			{
				eprint2(QUAD[i]);
			}
			if(strcmp(QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",QUAD[i].result);
				//if(QUAD[i-1].scope != QUAD[i].scope)
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
				else
				{	
					eprint2(QUAD[i]);	
				}
			}
			else if(strcmp(QUAD[i].block,"elif") == 0)
			{	/*
				if(estart == 1 && QUAD[i-1].scope != QUAD[i].scope)
				{
					fprintf(outfile,"goto L%d qwe \n",label_stk[ltop]+1);
					fprintf(outfile,"L%d: qwee\n",label_stk[ltop]);
					
					label_stk[ltop]++;
					
					estart = 0;
				}*/
				eprint2(QUAD[i]);
				//printf("as %d %d \n",QUAD[i+1].indi,QUAD[i].indi);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					//eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
			}
			if(strcmp(QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					fprintf(outfile,"goto L%d\n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					label_stk[ltop]++;
					estart = 0;
				//}
				eprint2(QUAD[i]);
			}
			if(strcmp(QUAD[i].block,"while") == 0)
			{
				if(QUAD[i-1].scope != QUAD[i].scope)
				{
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_no++,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
					label_stk[++ltop] = label_no;
					label_no++;
				}
				else
				{
					eprint2(QUAD[i]);
				}
			}
			if(strcmp(QUAD[i].block,"for") == 0)
			{//printf("%d %d %d \n ",QUAD[i].indi, QUAD[i-1].scope ,QUAD[i].scope);	
			if(QUAD[i].indi==1 )
				//if(QUAD[i-1].scope != QUAD[i].scope )
				{//printf("er %d %d \n",QUAD[i-2].scope , QUAD[i].scope);	
				if((i>=2 && QUAD[i-2].scope < QUAD[i].scope))
					{

					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_stk[ltop]+1,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no+1);
						for_k[for_k_value++]=label_stk[ltop]+1;
						for_go[for_go_value++]=label_no+1;
						label_stk[++ltop] = label_no+1;
						label_no+=2;
						
					}
				
					else //if(QUAD[i].indi==1 && i>=2 && QUAD[i-2].scope < QUAD[i].scope)
					{
						
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_stk[ltop--],QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
					for_k[for_k_value++]=label_stk[ltop+1];
					for_go[for_go_value++]=label_no;
					label_stk[++ltop] = label_no;
					label_no++;

					}
				}
				else
				{
					eprint2(QUAD[i]);
					if(QUAD[i].indi==2 )
				{
					fprintf(outfile,"goto L%d\n",for_k[--for_k_value]);
					fprintf(outfile,"L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
					
					
				}
				//printf("%d %d asd\n",i+1,Index);
				
			}
		} // if they come out of block
		else
		{	//printf("\n %s %s %d asd\n",QUAD[i].result,QUAD[i].block,QUAD[i].scope >= QUAD[i-1].scope);
			if(i == 0) 
			{ 
				fprintf(outfile,"%s:\n",QUAD[i].block);
				//in_block[++top] = 0;
				eprint2(QUAD[i]);

			}
			else
			{
			//printf("\n %s %s %d %d %d asd\n",QUAD[i].result,QUAD[i].block,QUAD[i].scope >= QUAD[i-1].scope,QUAD[i].scope , QUAD[i-1].scope);



				if(strcmp(QUAD[i-1].block,"while") == 0){ fprintf(outfile,"goto L%d\n",label_stk[ltop]-1);fprintf(outfile,"L%d:\n",label_stk[ltop--]);}
				else if(strcmp(QUAD[i].block,"for") == 0)
				{
					if(QUAD[i].indi==1)
				//if(QUAD[i-1].scope != QUAD[i].scope )
				{
					fprintf(outfile,"L%d:\nifFalse %s%s%s goto L%d\n",label_no++,QUAD[i].arg1,QUAD[i].op,QUAD[i].arg2,label_no);
				}
				else
				{
					eprint2(QUAD[i]);
						if(QUAD[i].indi==2 )
				{
					fprintf(outfile,"goto L%d\n",for_k[--for_k_value]);
					fprintf(outfile,"L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
				}
				}
				else if(strcmp(QUAD[i].block,"if") == 0)
			{	//fprintf(outfile,"\n%s \n",QUAD[i].result);
				//if(QUAD[i-1].scope != QUAD[i].scope)
				fprintf(outfile,"L%d:\n",label_stk[ltop--]);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
				else
				{	
					eprint2(QUAD[i]);	
				}
			}
				else if(strcmp(QUAD[i].block,"elif") == 0  && QUAD[i].indi==1)
				{	//fprintf(outfile,"asr %d %d \n",QUAD[i].scope,QUAD[i-1].scope);
					fprintf(outfile,"goto L%d \n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					
					label_stk[ltop]++;
					eprint2(QUAD[i]);
				//printf("as %d %d \n",QUAD[i+1].indi,QUAD[i].indi);
				if((i+1)<Index && QUAD[i+1].indi!=1 && QUAD[i].indi==1)
				{	
					//eprint2(QUAD[i]);
					label_stk[++ltop] = label_no;

					fprintf(outfile,"ifFalse %s goto L%d\n",QUAD[i].result,label_no++);
				}
					
				}
				else if(strcmp(QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					fprintf(outfile,"goto L%d\n",label_stk[ltop]+1);
					fprintf(outfile,"L%d:\n",label_stk[ltop--]);
					label_stk[++ltop]=label_no;
					label_no++;
					estart = 0;
				//}
				eprint2(QUAD[i]);
			}
				else{
				//printf("L%d: erter\n",label_stk[ltop--]);
				eprint2(QUAD[i]);
				}

				
			}
			//eprint2(QUAD[i]);
			estart = 1;
		}
		
	}
	
	fprintf(outfile,"L%d:\n",label_stk[ltop--]);
	fprintf(outfile,"\n\n");	

}

void sub_print_3addr_code()
{
	printf("\t\t\t\t sub_QUADruples \t\t\t\t\n");
	printf("\n\t%s\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t","pos","op","arg1","arg2","result");
	printf("\n\t------------------------------------------------------------------------");
	for(int i=0;i<sub_Index;i++)
	{
		printf("\n\t%d\t|\t%s\t|\t%s\t|\t%s\t|\t%s\t", i,sub_QUAD[i].op, sub_QUAD[i].arg1,sub_QUAD[i].arg2,sub_QUAD[i].result);
	}
	printf("\n\n\n\n");
	
	// printing in proper 3 address code
	int label_no = 1;
	int add_label = 0;
	int label_stk[20];
	int ltop = -1;

	char gotos[20][10];
	int fstates = 0;
	struct fsteps{
		int start_sub_Index;
		int step;
	}fsteps[1000];
	int ftop = -1;
	int estart = 1;
	int infor = 0;
	int for_k[1000];
	int for_k_value=0;
	int for_go[1000];
	int for_go_value=0;
	for(int i=0; i<sub_Index; i++)
	{	//printf("inner %s %d %d %s \n",sub_QUAD[i].block,sub_QUAD[i].scope,sub_QUAD[i-1].scope,sub_QUAD[i].op);
		// statements in same scope or within blocks
		if(i != 0 && sub_QUAD[i].scope >= sub_QUAD[i-1].scope){
			
			//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
			//if( strcmp(sub_QUAD[i].block,"elif") != 0 && (strcmp(sub_QUAD[i-1].block,"while") == 0 || (strcmp(sub_QUAD[i-1].block,"for") == 0) || (strcmp(sub_QUAD[i-1].block,"if") == 0)))
			//{
			//printf("L%d:\n",label_stk[ltop]);
			//}

			if(strcmp(sub_QUAD[i].block,"main") == 0)
			{
				eprint(sub_QUAD[i]);
			}
			if(strcmp(sub_QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",sub_QUAD[i].result);
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("ifFalse %s goto L%d\n",sub_QUAD[i].result,label_no++);
				}
				else
				{	
					eprint(sub_QUAD[i]);	
				}
			}
			else if(strcmp(sub_QUAD[i].block,"elif") == 0)
			{	/*
				if(estart == 1 && sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				{
					printf("goto L%d qwe \n",label_stk[ltop]+1);
					printf("L%d: qwee\n",label_stk[ltop]);
					
					label_stk[ltop]++;
					
					estart = 0;
				}*/
				eprint(sub_QUAD[i]);
				//printf("as %d %d \n",sub_QUAD[i+1].indi,sub_QUAD[i].indi);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					//eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("ifFalse %s goto L%d\n",sub_QUAD[i].result,label_no++);
				}
			}
			if(strcmp(sub_QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					printf("goto L%d\n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					label_stk[ltop]++;
					estart = 0;
				//}
				eprint(sub_QUAD[i]);
			}
			if(strcmp(sub_QUAD[i].block,"while") == 0)
			{
				if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				{
					printf("L%d:\nifFalse %s%s%s goto L%d\n",label_no++,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
					label_stk[++ltop] = label_no;
					label_no++;
				}
				else
				{
					eprint(sub_QUAD[i]);
				}
			}
			if(strcmp(sub_QUAD[i].block,"for") == 0)
			{//printf("%d %d %d \n ",sub_QUAD[i].indi, sub_QUAD[i-1].scope ,sub_QUAD[i].scope);	
			if(sub_QUAD[i].indi==1 )
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope )
				{//printf("er %d %d \n",sub_QUAD[i-2].scope , sub_QUAD[i].scope);	
				if((i>=2 && sub_QUAD[i-2].scope < sub_QUAD[i].scope))
					{

					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_stk[ltop]+1,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no+1);
						for_k[for_k_value++]=label_stk[ltop]+1;
						for_go[for_go_value++]=label_no+1;
						label_stk[++ltop] = label_no+1;
						label_no+=2;
						
					}
				
					else //if(sub_QUAD[i].indi==1 && i>=2 && sub_QUAD[i-2].scope < sub_QUAD[i].scope)
					{
						
					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_stk[ltop--],sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
					for_k[for_k_value++]=label_stk[ltop+1];
					for_go[for_go_value++]=label_no;
					label_stk[++ltop] = label_no;
					label_no++;

					}
				}
				else
				{
					eprint(sub_QUAD[i]);
					if(sub_QUAD[i].indi==2 )
				{
					printf("goto L%d\n",for_k[--for_k_value]);
					printf("L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
					
					
				}
				//printf("%d %d asd\n",i+1,sub_Index);
				
			}
		} // if they come out of block
		else
		{	//printf("\n %s %s %d asd\n",sub_QUAD[i].result,sub_QUAD[i].block,sub_QUAD[i].scope >= sub_QUAD[i-1].scope);
			if(i == 0) 
			{ 
				printf("%s:\n",sub_QUAD[i].block);
				//in_block[++top] = 0;
				eprint(sub_QUAD[i]);

			}
			else
			{
			//printf("\n %s %s %d %d %d asd\n",sub_QUAD[i].result,sub_QUAD[i].block,sub_QUAD[i].scope >= sub_QUAD[i-1].scope,sub_QUAD[i].scope , sub_QUAD[i-1].scope);



				if(strcmp(sub_QUAD[i-1].block,"while") == 0){ printf("goto L%d\n",label_stk[ltop]-1);printf("L%d:\n",label_stk[ltop--]);}
				else if(strcmp(sub_QUAD[i].block,"for") == 0)
				{
					if(sub_QUAD[i].indi==1)
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope )
				{
					printf("L%d: if(!(%s%s%s)) goto L%d\n",label_no++,sub_QUAD[i].arg1,sub_QUAD[i].op,sub_QUAD[i].arg2,label_no);
				}
				else
				{
					eprint(sub_QUAD[i]);
						if(sub_QUAD[i].indi==2 )
				{
					printf("goto L%d\n",for_k[--for_k_value]);
					printf("L%d:\n",for_go[--for_go_value]);
					label_stk[ltop]+=1;	
					label_no+=1;
				}
				
				}
				}
				else if(strcmp(sub_QUAD[i].block,"if") == 0)
			{	//printf("\n%s \n",sub_QUAD[i].result);
				//if(sub_QUAD[i-1].scope != sub_QUAD[i].scope)
				printf("L%d:\n",label_stk[ltop--]);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("if(!(%s)) goto L%d\n",sub_QUAD[i].result,label_no++);
				}
				else
				{	
					eprint(sub_QUAD[i]);	
				}
			}
				else if(strcmp(sub_QUAD[i].block,"elif") == 0  && sub_QUAD[i].indi==1)
				{	//printf("asr %d %d \n",sub_QUAD[i].scope,sub_QUAD[i-1].scope);
					printf("goto L%d \n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					
					label_stk[ltop]++;
					eprint(sub_QUAD[i]);
				//printf("as %d %d \n",sub_QUAD[i+1].indi,sub_QUAD[i].indi);
				if((i+1)<sub_Index && sub_QUAD[i+1].indi!=1 && sub_QUAD[i].indi==1)
				{	
					//eprint(sub_QUAD[i]);
					label_stk[++ltop] = label_no;

					printf("if(!(%s)) goto L%d\n",sub_QUAD[i].result,label_no++);
				}
					
				}
				else if(strcmp(sub_QUAD[i].block,"else") == 0)
			{
				//if(estart == 1)
				//{
					printf("goto L%d\n",label_stk[ltop]+1);
					printf("L%d:\n",label_stk[ltop--]);
					label_stk[++ltop]=label_no;
					label_no++;
					estart = 0;
				//}
				eprint(sub_QUAD[i]);
			}
				else{
				//printf("L%d: erter\n",label_stk[ltop--]);
				eprint(sub_QUAD[i]);
				}

				
			}
			//eprint(sub_QUAD[i]);
			estart = 1;
		}
		
	}
	
	printf("L%d:\n",label_stk[ltop--]);
	printf("\n\n");	

}
char * search_in_quad(char* op,char *arg1,char* arg2)
{ char *a=malloc(sizeof(char)*10);
	//static char *a="";
	for(int i=0; i<Index; i++)
	{
		if(strcmp(QUAD[i].op,op)==0 && strcmp(QUAD[i].arg1,arg1)==0 && strcmp(QUAD[i].arg2,arg2)==0)
		{
			strcpy(a,(char*)QUAD[i].result);
			return a;
		}
	}
	a="0\0";
    return a;
	
}
void eprint(struct quad quad)
{
	if(folding==1 && strcmp(quad.actual_result,"")!=0 && strcmp(quad.block,"main")==0)
	{
		printf("%s = %s\n", quad.result,quad.actual_result);
		return;
	}

	if(strcmp(quad.op,"=") == 0)
	{
		printf("%s %s %s\n", quad.result,quad.op,quad.arg1);
		return;
	}
	//if(strcmp(quad.block,"if") == 0 || strcmp(quad.block,"elif") == 0)
	//{
		//printf("%s %s %s A ", quad.arg1, quad.op, quad.arg2);
	//	printf("%s %s %s %s %s %s %d\n",quad.result, "=", quad.arg1, quad.op, quad.arg2,quad.block,quad.scope);
	//	return;
	//}
	printf("%s %s %s %s %s \n",quad.result, "=", quad.arg1, quad.op, quad.arg2);
}

void eprint2(struct quad quad)
{
	if(folding==1 && strcmp(quad.actual_result,"")!=0 && strcmp(quad.block,"main")==0)
	{	//printf(" %s in\n",quad.result);
		if(quad.result[0]=='r' && quad.result[1]>='0' && quad.result[1]<='9')
		{
			//printf("fdf \n");
		}
		else
		fprintf(outfile,"%s = %s\n", quad.result,quad.actual_result);
		return;
	}

	if(strcmp(quad.op,"=") == 0)
	{
		fprintf(outfile,"%s %s %s\n", quad.result,quad.op,quad.arg1);
		return;
	}
	//if(strcmp(quad.block,"if") == 0 || strcmp(quad.block,"elif") == 0)
	//{
		//printf("%s %s %s A ", quad.arg1, quad.op, quad.arg2);
	//	printf("%s %s %s %s %s %s %d\n",quad.result, "=", quad.arg1, quad.op, quad.arg2,quad.block,quad.scope);
	//	return;
	//}
	fprintf(outfile,"%s %s %s %s %s \n",quad.result, "=", quad.arg1, quad.op, quad.arg2);
}

void push(char *label)
{
	strcpy(stk.label[++stk.top],label);
}

void pop()
{
	stk.top--;
}

char* get_top()
{
	return stk.label[stk.top];
}

void main(int argc,char *argv[]) 
{ 
FILE *fp2=fopen("input1.py","r");
outfile = fopen("output_file.txt", "w");
if(!fp2)
{
	printf("unable to open");
	exit(0);
}
yyin=fp2;

FILE *fp1=fopen("out.py","w");
if(!fp1)
{
	printf("unable to open");
	exit(0);
}
yyout=fp1;
yyparse(); 
if(flag==0) {
printf("Valid\n\n"); 
}
printf("SYMBOL TABLE\n");
	printf("\tLINE\t\tID\t\tVALUE\t\tType\n");

	printTable(head);
	// print_3addr_code();
	sub_print_3addr_code();
	folding=1;
	print_3addr_code();
}

void yyerror(char *s) 
{ 
//printf("\n Invalid\n\n"); 
fprintf(stderr, " line : %s  %d\n", s,line);

flag=1; 
} 

int fun_indent(int i)
{
	if(i==0){
	k++;

	if(k>indent){
	
	return 0;
	}
	}
	else{
	int uy=indent-k;
	while(uy>0){pop();uy-=1;}
	indent=k;
	}
	return 1;
}
 
void fun_cond(int i)
{
	if(i==0)
	{
	yyerror("invalid indentation"); 
	}
}


int yywrap()

{

return 1;

}
