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
#line 1 "parser.y"


#include <iostream>
#include <vector>
#include "parser.h"
#include <cstring>
#include <cstdio>

using namespace std;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();

vector<Parametru> globalParams; //vector pentru stocarea parametrilor globali
class IdList ids; //clasa pentru gestionarea identificatorilor
string context = "global"; //contextul curent, initial global
string altcontext; //context alternativ pentru situatii specifice
vector<int> intValvec; //vector pentru stocarea valorilor intregi
vector<float> floatValvec; 
vector<char> charValvec; 
vector<bool> boolValvec; 
vector<Valoare> parametri;

void yyerror(const char * s);

#line 99 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VARS = 3,                       /* VARS  */
  YYSYMBOL_FUNCS = 4,                      /* FUNCS  */
  YYSYMBOL_CONSTRUCTS = 5,                 /* CONSTRUCTS  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_NEQ = 8,                        /* NEQ  */
  YYSYMBOL_GT = 9,                         /* GT  */
  YYSYMBOL_GEQ = 10,                       /* GEQ  */
  YYSYMBOL_LT = 11,                        /* LT  */
  YYSYMBOL_LEQ = 12,                       /* LEQ  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_SWITCH = 20,                    /* SWITCH  */
  YYSYMBOL_CASE = 21,                      /* CASE  */
  YYSYMBOL_ENTRY = 22,                     /* ENTRY  */
  YYSYMBOL_EXIT = 23,                      /* EXIT  */
  YYSYMBOL_MAIN = 24,                      /* MAIN  */
  YYSYMBOL_FNENTRY = 25,                   /* FNENTRY  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_USRDEF = 28,                    /* USRDEF  */
  YYSYMBOL_GLOBALVAR = 29,                 /* GLOBALVAR  */
  YYSYMBOL_GLOBALFUNC = 30,                /* GLOBALFUNC  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_PRINT = 32,                     /* PRINT  */
  YYSYMBOL_ID = 33,                        /* ID  */
  YYSYMBOL_TYPE = 34,                      /* TYPE  */
  YYSYMBOL_EVAL = 35,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 36,                    /* TYPEOF  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_CHAR = 39,                      /* CHAR  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_EQ = 42,                        /* EQ  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* ','  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '.'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_user_defined_types = 62,        /* user_defined_types  */
  YYSYMBOL_user_defined_type = 63,         /* user_defined_type  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_field_variables = 65,           /* field_variables  */
  YYSYMBOL_field_functions = 66,           /* field_functions  */
  YYSYMBOL_function_declaration = 67,      /* function_declaration  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_field_constructors = 69,        /* field_constructors  */
  YYSYMBOL_constructor_declaration = 70,   /* constructor_declaration  */
  YYSYMBOL_71_4 = 71,                      /* $@4  */
  YYSYMBOL_constructor_block = 72,         /* constructor_block  */
  YYSYMBOL_global_variables = 73,          /* global_variables  */
  YYSYMBOL_global_functions = 74,          /* global_functions  */
  YYSYMBOL_parameter_list = 75,            /* parameter_list  */
  YYSYMBOL_parameter = 76,                 /* parameter  */
  YYSYMBOL_variable_declaration = 77,      /* variable_declaration  */
  YYSYMBOL_class_var_declaration = 78,     /* class_var_declaration  */
  YYSYMBOL_array_declaration = 79,         /* array_declaration  */
  YYSYMBOL_int_valori = 80,                /* int_valori  */
  YYSYMBOL_float_valori = 81,              /* float_valori  */
  YYSYMBOL_bool_valori = 82,               /* bool_valori  */
  YYSYMBOL_char_valori = 83,               /* char_valori  */
  YYSYMBOL_block = 84,                     /* block  */
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_assignment_statement = 86,      /* assignment_statement  */
  YYSYMBOL_control_statement = 87,         /* control_statement  */
  YYSYMBOL_if_statement = 88,              /* if_statement  */
  YYSYMBOL_case_block = 89,                /* case_block  */
  YYSYMBOL_valoare = 90,                   /* valoare  */
  YYSYMBOL_expression = 91,                /* expression  */
  YYSYMBOL_arithm_expr = 92,               /* arithm_expr  */
  YYSYMBOL_bool_expr = 93,                 /* bool_expr  */
  YYSYMBOL_fn_call = 94,                   /* fn_call  */
  YYSYMBOL_argument_list = 95              /* argument_list  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   593

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
       2,     2,     2,     2,     2,     2,     2,    47,     2,     2,
      48,    49,    45,    43,    53,    44,    57,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    52,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    68,    71,    72,    75,    75,    83,    84,
      85,    89,    90,    93,    93,   123,   124,   127,   127,   146,
     147,   150,   151,   152,   153,   156,   157,   160,   161,   162,
     166,   177,   192,   218,   251,   283,   326,   353,   400,   436,
     476,   508,   553,   578,   613,   647,   677,   711,   712,   715,
     716,   719,   720,   723,   724,   727,   728,   731,   732,   733,
     734,   735,   736,   737,   752,   765,   778,   781,   799,   832,
     858,   882,   902,   926,   948,   974,  1005,  1027,  1051,  1052,
    1053,  1054,  1055,  1056,  1060,  1061,  1065,  1066,  1069,  1070,
    1071,  1072,  1073,  1077,  1078,  1083,  1101,  1117,  1133,  1149,
    1166,  1169,  1172,  1176,  1180,  1185,  1201,  1228,  1254,  1272,
    1285,  1302,  1305,  1308,  1311,  1314,  1318,  1326,  1334,  1342,
    1351,  1359,  1370,  1419,  1420,  1421
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
  "\"end of file\"", "error", "\"invalid token\"", "VARS", "FUNCS",
  "CONSTRUCTS", "CLASS", "CONST", "NEQ", "GT", "GEQ", "LT", "LEQ", "AND",
  "OR", "NOT", "IF", "ELSE", "WHILE", "FOR", "SWITCH", "CASE", "ENTRY",
  "EXIT", "MAIN", "FNENTRY", "BREAK", "DEFAULT", "USRDEF", "GLOBALVAR",
  "GLOBALFUNC", "RETURN", "PRINT", "ID", "TYPE", "EVAL", "TYPEOF",
  "STRING", "INT", "CHAR", "FLOAT", "BOOL", "EQ", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'('", "')'", "'{'", "'}'", "';'", "','", "'='", "'['",
  "']'", "'.'", "':'", "$accept", "program", "$@1", "user_defined_types",
  "user_defined_type", "$@2", "field_variables", "field_functions",
  "function_declaration", "$@3", "field_constructors",
  "constructor_declaration", "$@4", "constructor_block",
  "global_variables", "global_functions", "parameter_list", "parameter",
  "variable_declaration", "class_var_declaration", "array_declaration",
  "int_valori", "float_valori", "bool_valori", "char_valori", "block",
  "statement", "assignment_statement", "control_statement", "if_statement",
  "case_block", "valoare", "expression", "arithm_expr", "bool_expr",
  "fn_call", "argument_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,     5,    85,  -138,  -138,    -2,    81,  -138,  -138,  -138,
      10,    55,    95,    89,  -138,   109,  -138,  -138,  -138,   179,
     139,   142,   136,   172,  -138,   141,   213,  -138,   120,  -138,
    -138,   357,    40,    75,  -138,   150,  -138,   392,   153,   161,
     479,    96,   173,  -138,   180,  -138,  -138,    77,   479,   184,
     377,   154,  -138,   157,   191,  -138,  -138,  -138,   202,   208,
     214,   218,   557,  -138,   377,  -138,   479,   105,   238,  -138,
    -138,    77,   -21,    90,    25,  -138,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,   479,   479,   220,
     221,     4,  -138,  -138,  -138,  -138,   479,   479,   229,   411,
     423,    32,   235,   237,  -138,  -138,  -138,    57,  -138,  -138,
    -138,  -138,   239,   241,  -138,   106,   -35,   234,   236,   246,
    -138,   365,  -138,  -138,   493,   493,   493,   493,   493,   493,
     -21,   -21,  -138,  -138,  -138,  -138,   287,  -138,   169,  -138,
    -138,    -3,    17,   272,   256,   257,   260,   259,   264,   265,
     439,   119,   279,   479,   479,   300,  -138,  -138,     8,  -138,
     479,  -138,  -138,  -138,  -138,  -138,  -138,  -138,    28,    41,
     159,   196,   -10,   557,   557,   144,   479,   304,   304,   304,
    -138,  -138,  -138,   277,   278,   280,   275,   284,   291,   285,
     297,  -138,   313,   317,   121,  -138,  -138,   314,   299,   316,
     305,   322,   318,   326,   319,  -138,   328,  -138,   222,   228,
      -6,   151,     7,    86,    97,  -138,  -138,  -138,   315,   320,
     451,   339,   340,   367,  -138,   352,     8,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,   355,  -138,   387,  -138,    77,
     246,  -138,  -138,  -138,  -138,   358,  -138,   151,   359,   360,
     369,   125,   467,   354,   361,   363,  -138,  -138,  -138,   557,
    -138,     8,   -15,   535,   557,   370,   557,   557,   557,   382,
     383,   385,   389,  -138,  -138,  -138,   262,   128,   557,  -138,
     393,   515,   557,   268,   302,   308,  -138,  -138,  -138,  -138,
    -138,   395,   342,   557,   390,   536,  -138,  -138,  -138,   557,
    -138,   348,  -138,   394,   388,   557,  -138,  -138,  -138
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,    21,     5,     6,
       0,     0,     0,     0,    25,     0,    22,    24,    23,     0,
       0,     0,     0,     0,     8,     0,     0,     2,     0,    26,
      32,     0,     0,     0,    40,     0,    36,     0,     0,     0,
       0,   105,     0,   102,     0,   103,   115,     0,     0,     0,
      93,    94,   104,     0,     0,    11,     9,    10,     0,     0,
       0,     0,     0,    13,     0,   113,   123,     0,     0,    34,
      33,     0,   100,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    39,    38,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    59,    58,     0,    55,    60,
      61,    78,     0,     0,   124,     0,     0,     0,     0,   106,
     107,     0,   101,   114,   121,   116,   118,   117,   119,   120,
      95,    96,    98,    97,    99,   111,   112,    42,     0,    15,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    62,    27,   122,
       0,   108,   109,   110,    48,    54,    50,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    65,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,    28,   125,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    16,     0,     0,
       0,     0,     0,     0,     0,    70,    69,    68,     0,     0,
       0,     0,     0,     0,    30,     0,     0,    47,    43,    49,
      44,    51,    46,    53,    45,     0,     7,     0,    82,     0,
       0,    92,    88,    89,    90,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    66,    31,     0,
      29,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    76,    75,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,    74,    73,    72,    71,
      14,     0,     0,     0,     0,     0,    80,    81,    79,    20,
      84,     0,    86,     0,     0,    19,    83,    87,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   356,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,   192,   231,    62,   448,
      73,  -138,  -138,  -138,  -138,  -137,  -105,   325,  -138,   203,
      72,   223,   -34,   -28,   -26,   -62,  -138
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,    38,     5,     8,    11,    33,    91,    29,   113,
     172,   207,   235,   304,    10,    22,   194,   195,   104,   105,
     106,   168,   169,   170,   171,   107,   108,   109,   110,   111,
     212,   245,    49,    50,    51,    52,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     112,    96,   156,    61,     6,   118,   120,    87,    88,   139,
      87,    88,    64,    66,    65,   192,    12,    13,     1,    72,
      73,   161,    74,   205,    84,    85,    86,     7,   247,    28,
      87,    88,   114,     3,   248,   278,   208,   209,    87,    88,
      14,   206,   193,   121,    15,   112,   239,   173,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,    64,
      64,   135,   136,    12,    13,   146,   149,   174,    64,    64,
     141,   142,    16,    96,   123,    97,    98,    99,    53,    55,
      66,   197,    13,    18,   198,     4,   150,   151,   100,   152,
     101,    15,   102,   103,   199,    56,    54,   200,    76,    77,
      78,    79,    80,   156,   156,    19,    57,   247,   155,    15,
      41,   112,   112,   249,     9,    43,   185,    45,   247,   189,
     190,    47,   276,    21,   250,    71,   196,   281,    20,   283,
     284,   285,    81,    82,    83,    84,    85,    86,   116,   122,
      40,   292,    23,   117,    66,   295,   112,   112,    64,   246,
     210,    67,   186,    68,    39,   159,   301,   187,    41,   160,
      27,    28,   305,    43,   269,    45,    46,    87,    88,    47,
     225,   156,    25,    48,   226,    26,   156,   291,   156,   156,
     156,   226,    24,    58,   240,   246,   255,   156,   241,   242,
     156,   243,   244,    34,    63,    35,   156,   112,   150,   151,
     156,   152,   112,    62,   112,   112,   112,   164,   165,   166,
     167,   263,   201,    89,   112,   202,   112,   270,   272,   112,
     112,   112,   112,   112,    30,    69,    31,    32,    12,    13,
     112,   112,    70,   112,    12,    13,    75,   112,    96,   112,
      97,    98,    99,   112,    96,    90,    97,    98,    99,   203,
     213,   214,   204,   100,    92,   101,    15,   102,   103,   100,
      93,   101,    15,   102,   103,    36,    94,    37,    12,    13,
      95,   119,   137,   237,    12,    13,   138,   143,    96,   238,
      97,    98,    99,   153,    96,   154,    97,    98,    99,   158,
     162,   157,   163,   100,    66,   101,    15,   102,   103,   100,
      87,   101,    15,   102,   103,   175,   177,   178,    12,    13,
     179,   180,   188,   290,    12,    13,   181,   182,    96,   296,
      97,    98,    99,   191,    96,   211,    97,    98,    99,   215,
     216,   218,   217,   100,   221,   101,    15,   102,   103,   100,
     219,   101,    15,   102,   103,   220,   222,   223,    12,    13,
     224,   228,   227,   297,    12,    13,   229,   230,    96,   298,
      97,    98,    99,   231,    96,   233,    97,    98,    99,   251,
     232,   234,    40,   100,   252,   101,    15,   102,   103,   100,
     236,   101,    15,   102,   103,    76,    77,    78,    79,    80,
      41,   256,   257,   300,    42,    43,    44,    45,    46,   306,
     258,    47,   259,   261,   262,    48,   273,    40,    82,    83,
      84,    85,    86,   274,   122,   275,   264,   266,   267,    81,
      82,    83,    84,    85,    86,    41,    40,   268,   282,    59,
      43,    60,    45,    46,   286,   287,    47,   288,    40,   308,
      48,   289,   302,   293,    41,   299,   307,   140,   144,    43,
     145,    45,    46,   277,    40,    47,    41,   260,    17,    48,
     147,    43,   148,    45,    46,   279,    40,    47,   176,     0,
     265,    48,    41,     0,     0,     0,   183,    43,   184,    45,
      46,     0,    40,    47,    41,     0,     0,    48,   253,    43,
     254,    45,    46,     0,    40,    47,     0,     0,     0,    48,
      41,     0,     0,     0,     0,    43,   271,    45,    46,     0,
       0,    47,    41,     0,     0,    48,     0,    43,     0,    45,
      46,    12,    13,    47,     0,     0,     0,    48,     0,     0,
       0,    96,     0,    97,    98,    99,    82,    83,    84,    85,
      86,   294,    12,    13,     0,     0,   100,     0,   101,    15,
     102,   103,    96,     0,    97,    98,    99,     0,     0,     0,
       0,     0,   303,    12,    13,     0,     0,   100,     0,   101,
      15,   102,   103,    96,     0,    97,    98,    99,    82,    83,
      84,    85,    86,     0,   280,     0,     0,     0,   100,     0,
     101,    15,   102,   103
};

static const yytype_int16 yycheck[] =
{
      62,    16,   107,    37,     6,    67,    68,    13,    14,     5,
      13,    14,    40,    48,    40,     7,     6,     7,    22,    47,
      48,    56,    48,    33,    45,    46,    47,    29,    21,    25,
      13,    14,    66,    28,    27,    50,   173,   174,    13,    14,
      30,    51,    34,    71,    34,   107,    52,    50,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    87,    88,     6,     7,    99,   100,    50,    96,    97,
      96,    97,    10,    16,    49,    18,    19,    20,    38,     4,
      48,    53,     7,    10,    56,     0,    54,    55,    31,    57,
      33,    34,    35,    36,    53,    33,    56,    56,     8,     9,
      10,    11,    12,   208,   209,    50,    33,    21,    51,    34,
      33,   173,   174,    27,    33,    38,   150,    40,    21,   153,
     154,    44,   259,    34,    27,    48,   160,   264,    33,   266,
     267,   268,    42,    43,    44,    45,    46,    47,    33,    49,
      15,   278,    33,    38,    48,   282,   208,   209,   176,   211,
     176,    55,    33,    57,    34,    49,   293,    38,    33,    53,
      24,    25,   299,    38,    39,    40,    41,    13,    14,    44,
      49,   276,    33,    48,    53,    33,   281,    49,   283,   284,
     285,    53,     3,    33,    33,   247,   220,   292,    37,    38,
     295,    40,    41,    52,    33,    54,   301,   259,    54,    55,
     305,    57,   264,    50,   266,   267,   268,    38,    39,    40,
      41,   239,    53,    56,   276,    56,   278,   251,   252,   281,
     282,   283,   284,   285,    52,    52,    54,    55,     6,     7,
     292,   293,    52,   295,     6,     7,    52,   299,    16,   301,
      18,    19,    20,   305,    16,    54,    18,    19,    20,    53,
     178,   179,    56,    31,    52,    33,    34,    35,    36,    31,
      52,    33,    34,    35,    36,    52,    52,    54,     6,     7,
      52,    33,    52,    51,     6,     7,    55,    48,    16,    51,
      18,    19,    20,    48,    16,    48,    18,    19,    20,    48,
      56,    52,    56,    31,    48,    33,    34,    35,    36,    31,
      13,    33,    34,    35,    36,    33,    50,    50,     6,     7,
      50,    52,    33,    51,     6,     7,    52,    52,    16,    51,
      18,    19,    20,    23,    16,    21,    18,    19,    20,    52,
      52,    56,    52,    31,    49,    33,    34,    35,    36,    31,
      56,    33,    34,    35,    36,    54,    49,    34,     6,     7,
      33,    52,    38,    51,     6,     7,    40,    52,    16,    51,
      18,    19,    20,    41,    16,    39,    18,    19,    20,    54,
      52,    52,    15,    31,    54,    33,    34,    35,    36,    31,
      52,    33,    34,    35,    36,     8,     9,    10,    11,    12,
      33,    52,    52,    51,    37,    38,    39,    40,    41,    51,
      33,    44,    50,    48,    17,    48,    52,    15,    43,    44,
      45,    46,    47,    52,    49,    52,    58,    58,    58,    42,
      43,    44,    45,    46,    47,    33,    15,    58,    58,    37,
      38,    39,    40,    41,    52,    52,    44,    52,    15,    51,
      48,    52,    52,    50,    33,    50,    52,    91,    37,    38,
      39,    40,    41,   261,    15,    44,    33,   226,    10,    48,
      37,    38,    39,    40,    41,   262,    15,    44,   143,    -1,
     247,    48,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    -1,    15,    44,    33,    -1,    -1,    48,    37,    38,
      39,    40,    41,    -1,    15,    44,    -1,    -1,    -1,    48,
      33,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    44,    33,    -1,    -1,    48,    -1,    38,    -1,    40,
      41,     6,     7,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    43,    44,    45,    46,
      47,    26,     6,     7,    -1,    -1,    31,    -1,    33,    34,
      35,    36,    16,    -1,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    26,     6,     7,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    16,    -1,    18,    19,    20,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    31,    -1,
      33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    60,    28,     0,    62,     6,    29,    63,    33,
      73,    64,     6,     7,    30,    34,    77,    78,    79,    50,
      33,    34,    74,    33,     3,    33,    33,    24,    25,    67,
      52,    54,    55,    65,    52,    54,    52,    54,    61,    34,
      15,    33,    37,    38,    39,    40,    41,    44,    48,    91,
      92,    93,    94,    38,    56,     4,    77,    79,    33,    37,
      39,    91,    50,    33,    92,    93,    48,    55,    57,    52,
      52,    48,    92,    92,    93,    52,     8,     9,    10,    11,
      12,    42,    43,    44,    45,    46,    47,    13,    14,    56,
      54,    66,    52,    52,    52,    52,    16,    18,    19,    20,
      31,    33,    35,    36,    77,    78,    79,    84,    85,    86,
      87,    88,    94,    68,    91,    95,    33,    38,    94,    33,
      94,    92,    49,    49,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    52,    55,     5,
      67,    93,    93,    48,    37,    39,    91,    37,    39,    91,
      54,    55,    57,    48,    48,    51,    85,    52,    48,    49,
      53,    56,    56,    56,    38,    39,    40,    41,    80,    81,
      82,    83,    69,    50,    50,    33,    86,    50,    50,    50,
      52,    52,    52,    37,    39,    91,    33,    38,    33,    91,
      91,    23,     7,    34,    75,    76,    91,    53,    56,    53,
      56,    53,    56,    53,    56,    33,    51,    70,    84,    84,
      93,    21,    89,    89,    89,    52,    52,    52,    56,    56,
      54,    49,    49,    34,    33,    49,    53,    38,    52,    40,
      52,    41,    52,    39,    52,    71,    52,    51,    51,    52,
      33,    37,    38,    40,    41,    90,    94,    21,    27,    27,
      27,    54,    54,    37,    39,    91,    52,    52,    33,    50,
      76,    48,    17,    92,    58,    90,    58,    58,    58,    39,
      91,    39,    91,    52,    52,    52,    84,    75,    50,    88,
      49,    84,    58,    84,    84,    84,    52,    52,    52,    52,
      51,    49,    84,    50,    26,    84,    51,    51,    51,    50,
      51,    84,    52,    26,    72,    84,    51,    52,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    62,    62,    64,    63,    65,    65,
      65,    66,    66,    68,    67,    69,    69,    71,    70,    72,
      72,    73,    73,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    79,    79,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,    13,     0,     2,     0,    12,     0,     2,
       2,     0,     2,     0,    10,     0,     2,     0,     8,     1,
       0,     0,     2,     2,     2,     0,     2,     0,     1,     3,
       2,     3,     3,     5,     5,     5,     4,     6,     6,     6,
       4,     6,     6,     9,     9,     9,     9,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     3,     3,     3,     5,     5,     4,     4,
       4,     7,     7,     7,     7,     6,     6,     6,     1,     8,
       8,     8,     5,    10,     9,     7,     6,     7,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1,     3,     3,     4,     4,
       4,     3,     3,     2,     3,     1,     3,     3,     3,     3,
       3,     3,     4,     0,     1,     3
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
  case 2: /* $@1: %empty  */
#line 68 "parser.y"
                                                                                                     { context = "main"; }
#line 1436 "parser.tab.c"
    break;

  case 3: /* program: ENTRY USRDEF user_defined_types GLOBALVAR global_variables GLOBALFUNC global_functions MAIN $@1 '{' block '}' EXIT  */
#line 68 "parser.y"
                                                                                                                                              {printf("Totul a decurs bine!\n");}
#line 1442 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 75 "parser.y"
                            { if(ids.existaClasa((yyvsp[0].string))) {printf("Error at line %d: the class \"%s\" is already defined.\n", yylineno, (yyvsp[0].string)); return 1;} context = (yyvsp[0].string); 
                        UserDefinedType type((yyvsp[0].string));
                        ids.adaugaUsrDef(type);}
#line 1450 "parser.tab.c"
    break;

  case 7: /* user_defined_type: CLASS ID $@2 '{' VARS field_variables FUNCS field_functions CONSTRUCTS field_constructors '}' ';'  */
#line 78 "parser.y"
                                                                                                            {
                        context = "global";
}
#line 1458 "parser.tab.c"
    break;

  case 8: /* field_variables: %empty  */
#line 83 "parser.y"
                  {}
#line 1464 "parser.tab.c"
    break;

  case 9: /* field_variables: field_variables variable_declaration  */
#line 84 "parser.y"
                                                      {  }
#line 1470 "parser.tab.c"
    break;

  case 10: /* field_variables: field_variables array_declaration  */
#line 85 "parser.y"
                                                   { }
#line 1476 "parser.tab.c"
    break;

  case 11: /* field_functions: %empty  */
#line 89 "parser.y"
                  { }
#line 1482 "parser.tab.c"
    break;

  case 12: /* field_functions: field_functions function_declaration  */
#line 90 "parser.y"
                                                      { }
#line 1488 "parser.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 93 "parser.y"
                                       {    altcontext=context;
                                            int result=ids.existaFunctia((yyvsp[0].string), altcontext);
                                            if(result==1) 
                                            {
                                                printf("Error at line %d: the function \"%s\" is already defined inside this scope: %s.\n", yylineno, (yyvsp[0].string), altcontext.c_str());
                                                return 1;
                                            }
                                            else if(result==2) 
                                            {
                                                printf("Error at line %d: return type specification for constructor invalid.\n", yylineno);
                                                return 1;
                                            }
                                            else if(result==3) 
                                            {
                                                printf("Error at line %d: %s already exists as a class variable or array.\n", yylineno, (yyvsp[0].string));
                                                return 1;
                                            }
                                            Functie func((yyvsp[0].string), (yyvsp[-1].string), altcontext); 
                                            ids.adaugaFunc(func); 
                                            context=(yyvsp[0].string); 
                                        }
#line 1514 "parser.tab.c"
    break;

  case 14: /* function_declaration: FNENTRY TYPE ID $@3 '(' parameter_list ')' '{' block '}'  */
#line 115 "parser.y"
                        {
                                            Functie &func=ids.obtineFunctie(context.c_str());
                                            func.parametri=globalParams;
                                            globalParams.clear();  
                                            context=altcontext;
                        }
#line 1525 "parser.tab.c"
    break;

  case 15: /* field_constructors: %empty  */
#line 123 "parser.y"
                    { }
#line 1531 "parser.tab.c"
    break;

  case 16: /* field_constructors: field_constructors constructor_declaration  */
#line 124 "parser.y"
                                                               { }
#line 1537 "parser.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 127 "parser.y"
                            {               if (strcmp((yyvsp[0].string), context.c_str())!= 0)
                                            {
                                                printf("Error at line %d: the constructor should have the same name as the class\n", yylineno);
                                                return 1;
                                            }
                                            altcontext=context;
                                            Functie func((yyvsp[0].string), "none (CONSTRUCTOR)", altcontext); 
                                            ids.adaugaFunc(func); 
                                            context=(yyvsp[0].string); 
                            }
#line 1552 "parser.tab.c"
    break;

  case 18: /* constructor_declaration: ID $@4 '(' parameter_list ')' '{' constructor_block '}'  */
#line 138 "parser.y"
                            { 
                                Functie &func=ids.obtineFunctie(context.c_str());
                                func.parametri=globalParams;
                                globalParams.clear();
                                context=altcontext; 
                            }
#line 1563 "parser.tab.c"
    break;

  case 20: /* constructor_block: %empty  */
#line 147 "parser.y"
                    {}
#line 1569 "parser.tab.c"
    break;

  case 27: /* parameter_list: %empty  */
#line 160 "parser.y"
                 {}
#line 1575 "parser.tab.c"
    break;

  case 28: /* parameter_list: parameter  */
#line 161 "parser.y"
                           { }
#line 1581 "parser.tab.c"
    break;

  case 29: /* parameter_list: parameter_list ',' parameter  */
#line 162 "parser.y"
                                               { }
#line 1587 "parser.tab.c"
    break;

  case 30: /* parameter: TYPE ID  */
#line 167 "parser.y"
{ 
            for(const auto &param: globalParams)
            {
                if(param.nume==(yyvsp[0].string))
                {
                    printf("Error at line %d: parameter \"%s\" declared more than once for this function.\n", yylineno, (yyvsp[0].string));
                    return 1;
                }
            }
    globalParams.push_back(Parametru((yyvsp[0].string), (yyvsp[-1].string)));}
#line 1602 "parser.tab.c"
    break;

  case 31: /* parameter: CONST TYPE ID  */
#line 177 "parser.y"
                         { 
            for(const auto &param: globalParams)
            {
                if(param.nume==(yyvsp[0].string))
                {
                    printf("Error at line %d: parameter \"%s\" declared more than once for this function.\n", yylineno, (yyvsp[0].string));
                return 1;
                }
            }
            Parametru param((yyvsp[0].string), (yyvsp[-1].string));
            param.esteConstanta=true; 
            globalParams.push_back(param);
         }
#line 1620 "parser.tab.c"
    break;

  case 32: /* variable_declaration: TYPE ID ';'  */
#line 193 "parser.y"
{
                        int result=ids.exista((yyvsp[-1].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        }
                        else 
                        {
                            Valoare val((yyvsp[-2].string));
                            Variabila var((yyvsp[-1].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }
                    }
#line 1650 "parser.tab.c"
    break;

  case 33: /* variable_declaration: TYPE ID '=' CHAR ';'  */
#line 219 "parser.y"
                    {
                        string tipul="char";
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if((yyvsp[-4].string)==tipul)
                        {
                            Valoare val(tipul);
                            val.isCharSet=true;
                            val.charVal=(yyvsp[-1].character);
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }  else 
                        {
                            printf("Error at line %d: Different types.1\n", yylineno);
                            return 1;
                        }                     
                    }
#line 1687 "parser.tab.c"
    break;

  case 34: /* variable_declaration: TYPE ID '=' STRING ';'  */
#line 252 "parser.y"
                    {
                        string tipul="string";
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } else if((yyvsp[-4].string)==tipul)
                        {
                            Valoare val(tipul);
                            val.isStringSet=true;
                            val.stringVal=(yyvsp[-1].string);
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }  else 
                        {
                            printf("Error at line %d: Different types.2\n", yylineno);
                            return 1;
                        }                     
                    }
#line 1723 "parser.tab.c"
    break;

  case 35: /* variable_declaration: TYPE ID '=' expression ';'  */
#line 284 "parser.y"
                    {
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        if((yyvsp[-4].string)==(yyvsp[-1].ASTNode)->Eval().tipul) 
                        {
                            Valoare val((yyvsp[-4].string));
                            if(val.tipul=="int") 
                            {
                                val.isIntSet=true;
                                val.intVal=(yyvsp[-1].ASTNode)->Eval().intVal;
                            } else if(val.tipul=="float") 
                            {
                                val.isFloatSet=true;
                                val.floatVal=(yyvsp[-1].ASTNode)->Eval().floatVal;
                            } else if(val.tipul=="bool") 
                            {
                                val.isBoolSet=true;
                                val.boolVal=(yyvsp[-1].ASTNode)->Eval().boolVal;
                            }        
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } else 
                        {
                            printf("Error at line %d: Different types.3\n", yylineno);
                            return 1;
                        }
                    }
#line 1770 "parser.tab.c"
    break;

  case 36: /* variable_declaration: CONST TYPE ID ';'  */
#line 327 "parser.y"
                    { 
                        int result=ids.exista((yyvsp[-1].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                        }
                        else 
                        {
                            Valoare val((yyvsp[-2].string));
                            val.esteConstanta=true;
                            Variabila var((yyvsp[-1].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        }
                    }
#line 1801 "parser.tab.c"
    break;

  case 37: /* variable_declaration: CONST TYPE ID '=' expression ';'  */
#line 354 "parser.y"
                    { 
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        if ((yyvsp[-4].string) == (yyvsp[-1].ASTNode)->TypeOf()) 
                        {
                            Valoare val((yyvsp[-4].string));
                            val.esteConstanta=true;
                            if(val.tipul=="int") 
                            {
                                val.isIntSet=true;
                                val.intVal=(yyvsp[-1].ASTNode)->Eval().intVal;
                            } 
                            else if(val.tipul=="float") 
                            {
                                val.isFloatSet=true;
                                val.floatVal=(yyvsp[-1].ASTNode)->Eval().floatVal;
                            } else if(val.tipul=="bool") 
                            {
                                val.isBoolSet=true;
                                val.boolVal=(yyvsp[-1].ASTNode)->Eval().boolVal;
                            } 
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.4\n", yylineno);
                            return 1;
                        }
                        
                    }
#line 1852 "parser.tab.c"
    break;

  case 38: /* variable_declaration: CONST TYPE ID '=' CHAR ';'  */
#line 401 "parser.y"
                    { 
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                       string tipul="char";
                        if((yyvsp[-4].string)==tipul) 
                        {
                            Valoare val((yyvsp[-4].string));
                            val.esteConstanta=true;
                            val.charVal=(yyvsp[-1].character);
                            val.isCharSet=true;
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.5\n",yylineno);
                            return 1;
                        }
                        
                    }
#line 1892 "parser.tab.c"
    break;

  case 39: /* variable_declaration: CONST TYPE ID '=' STRING ';'  */
#line 437 "parser.y"
                    { 
                        int result=ids.exista((yyvsp[-3].string), context);
                        if(result==1)
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        } 
                        else if(result==2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        else if(result==3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                        }
                        string tipul="string";
                        if((yyvsp[-4].string)==tipul) 
                        {
                            Valoare val((yyvsp[-4].string));
                            val.esteConstanta=true;
                            val.stringVal=(yyvsp[-1].string);
                            val.isStringSet=true;
                            Variabila var((yyvsp[-3].string), val);
                            var.context=context;
                            ids.adaugaVar(var);
                        } 
                        else 
                        {
                            printf("Error at line %d: Different types.6\n",yylineno);
                            return 1;
                        }
                        
                    }
#line 1932 "parser.tab.c"
    break;

  case 40: /* class_var_declaration: CLASS ID ID ';'  */
#line 477 "parser.y"
{
                            if(!ids.existaClasa((yyvsp[-2].string)))
                            {
                                printf("Error at line %d: the class \"%s\" is not defined.\n", yylineno, (yyvsp[-2].string));
                                return 1;
                            }
                            int result=ids.exista((yyvsp[-1].string), context);
                            if( result==1 )
                            {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-1].string));
                            return 1;
                            } 
                            else if(result==2)
                            {
                                printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-1].string));
                                return 1;
                            }
                            else if (result == 3)
                            {
                                printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-1].string));
                                return 1;
                            } 
                            else 
                            {
                                Valoare val((yyvsp[-2].string));
                                Variabila var((yyvsp[-1].string), val);
                                var.context = context;
                                ids.adaugaVar(var);
                            }
                            
                     }
#line 1968 "parser.tab.c"
    break;

  case 41: /* class_var_declaration: CLASS ID ID '=' ID ';'  */
#line 509 "parser.y"
                     { 
                            if(!ids.existaClasa((yyvsp[-4].string)))
                            {
                                printf("Error at line %d: the class \"%s\" is not defined.\n", yylineno, (yyvsp[-4].string));
                                return 1;
                            }
                            int result = ids.exista((yyvsp[-3].string), context);
                            if( result == 1 )
                            {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-3].string));
                            return 1;
                            } 
                            else if (result == 2)
                            {
                                printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-3].string));
                                return 1;
                            }
                            else if (result == 3)
                            {
                                printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-3].string));
                                return 1;
                            } else 
                            {
                                
                                if ( !ids.exista((yyvsp[-1].string)) )
                                {
                                printf("Error at line %d: No %s variable found.\n",yylineno, (yyvsp[-1].string));
                                return 1;
                                }
                                
                                
                                if( ids.obtineVariabila((yyvsp[-1].string)).Eval().tipul != (yyvsp[-4].string)) 
                                {
                                    printf("Error at line %d: Different types between %s and %s.\n",yylineno, (yyvsp[-3].string), (yyvsp[-1].string));
                                    return 1;
                                }
                                Valoare val((yyvsp[-4].string));
                                Variabila var((yyvsp[-3].string), val);
                                var.context = context;
                                ids.adaugaVar(var);
                            }   
                     }
#line 2015 "parser.tab.c"
    break;

  case 42: /* array_declaration: TYPE ID '[' INT ']' ';'  */
#line 554 "parser.y"
{
                    int result = ids.exista((yyvsp[-4].string), context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-4].string));
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-4].string));
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-4].string));
                            return 1;
                        } 
                        else 
                        {
                        Vector arr((yyvsp[-4].string), (yyvsp[-2].integer), (yyvsp[-5].string));
                        arr.context = context;
                        ids.adaugaVec(arr);
                        }
                 }
#line 2044 "parser.tab.c"
    break;

  case 43: /* array_declaration: TYPE ID '[' ']' '=' '[' int_valori ']' ';'  */
#line 579 "parser.y"
                 {
                   int result = ids.exista((yyvsp[-7].string), context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else 
                        {
                        Vector arr((yyvsp[-7].string), static_cast<int>(intValvec.size()), (yyvsp[-8].string));
                        
                        for (const auto &element : intValvec) 
                        {
                            char val[10];
                            sprintf(val, "%d", element);
                            arr.push(Valoare(val, "int"));
                        }

                        intValvec.clear();
                        arr.context = context;
                        ids.adaugaVec(arr);
                        
                    }
                 }
#line 2083 "parser.tab.c"
    break;

  case 44: /* array_declaration: TYPE ID '[' ']' '=' '[' float_valori ']' ';'  */
#line 614 "parser.y"
                 {
                    int result = ids.exista((yyvsp[-7].string), context);
                        if( result == 1 )
                        {
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else 
                        {
                        Vector arr((yyvsp[-7].string), static_cast<int>(floatValvec.size()), (yyvsp[-8].string));
                        
                        for (const auto &element : floatValvec) 
                        {
                            char val[64];
                            sprintf(val, "%f", element);
                            arr.push(Valoare(val, "float"));
                        }
                        
                        arr.context = context;
                        ids.adaugaVec(arr);
                        floatValvec.clear();
                        }
                 }
#line 2121 "parser.tab.c"
    break;

  case 45: /* array_declaration: TYPE ID '[' ']' '=' '[' char_valori ']' ';'  */
#line 648 "parser.y"
                 {
                   int result = ids.exista((yyvsp[-7].string), context);
                        if( result == 1 ){
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } else {
                        Vector arr((yyvsp[-7].string), static_cast<int>(charValvec.size()), (yyvsp[-8].string));
                        
                        for (const auto &element : charValvec) {
                            char val[10];
                            sprintf(val, "%c", element);
                            arr.push(Valoare(val, "char"));
                        }
                        
                        arr.context = context;
                        ids.adaugaVec(arr);
                        charValvec.clear();
                    }
                 }
#line 2155 "parser.tab.c"
    break;

  case 46: /* array_declaration: TYPE ID '[' ']' '=' '[' bool_valori ']' ';'  */
#line 677 "parser.y"
                                                               {
                    int result = ids.exista((yyvsp[-7].string), context);
                        if( result == 1 ){
                            printf("Error at line %d: \"%s\" already exists as a variable or array in this scope.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } 
                        else if (result == 2)
                        {
                            printf("Error at line %d: \"%s\" already exists as a function.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        }
                        else if (result == 3)
                        {
                            printf("Error at line %d: \"%s\" already exists as a user defined type.\n", yylineno, (yyvsp[-7].string));
                            return 1;
                        } else {
                        Vector arr((yyvsp[-7].string), static_cast<int>(boolValvec.size()), (yyvsp[-8].string));
                        
                        for (const auto &element : boolValvec) { 
                            char val[6];
                            if (element){
                                strcpy(val, "true");
                            } else {
                                strcpy(val, "false");
                            }
                            arr.push(Valoare(val, "bool"));
                        }
                        arr.context = context;
                        ids.adaugaVec(arr);
                        boolValvec.clear();
                    }
                 }
#line 2192 "parser.tab.c"
    break;

  case 47: /* int_valori: int_valori ',' INT  */
#line 711 "parser.y"
                               {intValvec.push_back((yyvsp[0].integer));}
#line 2198 "parser.tab.c"
    break;

  case 48: /* int_valori: INT  */
#line 712 "parser.y"
                {intValvec.push_back((yyvsp[0].integer));}
#line 2204 "parser.tab.c"
    break;

  case 49: /* float_valori: float_valori ',' FLOAT  */
#line 715 "parser.y"
                                     {floatValvec.push_back((yyvsp[0].floatnum));}
#line 2210 "parser.tab.c"
    break;

  case 50: /* float_valori: FLOAT  */
#line 716 "parser.y"
                    {floatValvec.push_back((yyvsp[0].floatnum));}
#line 2216 "parser.tab.c"
    break;

  case 51: /* bool_valori: bool_valori ',' BOOL  */
#line 719 "parser.y"
                                  {boolValvec.push_back((yyvsp[0].boolean));}
#line 2222 "parser.tab.c"
    break;

  case 52: /* bool_valori: BOOL  */
#line 720 "parser.y"
                  {boolValvec.push_back((yyvsp[0].boolean));}
#line 2228 "parser.tab.c"
    break;

  case 53: /* char_valori: char_valori ',' CHAR  */
#line 723 "parser.y"
                                  {charValvec.push_back((yyvsp[0].character));}
#line 2234 "parser.tab.c"
    break;

  case 54: /* char_valori: CHAR  */
#line 724 "parser.y"
                  {charValvec.push_back((yyvsp[0].character));}
#line 2240 "parser.tab.c"
    break;

  case 63: /* statement: RETURN expression ';'  */
#line 737 "parser.y"
                                 {
            if ( context == "main" ) {
                if ( (yyvsp[-1].ASTNode)->Eval().tipul != "int" ){
                    printf("Error at line %d: Error at returning a non integer in main scope.\n", yylineno);
                    return 1;
                }

            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                if( fn.returnType != (yyvsp[-1].ASTNode)->Eval().tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n", yylineno, fn.nume.c_str());
                    return 1;
                } 
            }
         }
#line 2260 "parser.tab.c"
    break;

  case 64: /* statement: RETURN STRING ';'  */
#line 752 "parser.y"
                             {
            if ( context == "main") {
                printf("Error at line %d: Error at returning a non integer in main scope.\n",yylineno);
                return 1;
            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                string tipul = "string";
                if( fn.returnType != tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n",yylineno, fn.nume.c_str());
                    return 1;
                }
            }
         }
#line 2278 "parser.tab.c"
    break;

  case 65: /* statement: RETURN CHAR ';'  */
#line 765 "parser.y"
                           {
            if ( context == "main") {
                printf("Error at line %d: Error at returning a non integer in main scope.\n",yylineno);
                return 1;
            } else {
                Functie fn = ids.obtineFunctie(context.c_str());
                string tipul = "char";
                if( fn.returnType != tipul ){
                    printf("Error at line %d: Different returning types in function: %s.\n",yylineno, fn.nume.c_str());
                    return 1;
                }
            }
         }
#line 2296 "parser.tab.c"
    break;

  case 66: /* statement: TYPEOF '(' expression ')' ';'  */
#line 778 "parser.y"
                                         {
            printf("Linia : %d Tipul expresiei este: %s\n",yylineno, (yyvsp[-2].ASTNode)->Eval().tipul.c_str());
         }
#line 2304 "parser.tab.c"
    break;

  case 67: /* statement: EVAL '(' expression ')' ';'  */
#line 781 "parser.y"
                                       {
            string tipul = (yyvsp[-2].ASTNode)->TypeOf();
            if( tipul == "int" ) {
                printf("Linia : %d Valoarea expresiei este: %d\n",yylineno, (yyvsp[-2].ASTNode)->Eval().intVal);
            } else if( tipul == "float" ) {
                printf("Linia : %d Valoarea expresiei este: %f\n",yylineno, (yyvsp[-2].ASTNode)->Eval().floatVal);
            } else if( tipul == "char" ) {
                printf("Linia : %d Valoarea expresiei este: %c\n",yylineno, (yyvsp[-2].ASTNode)->Eval().charVal);
            } else if( tipul == "bool" ) {
                if( (yyvsp[-2].ASTNode)->Eval().boolVal != 0 ){
                    printf("Linia : %d Valoarea expresiei este: true \n",yylineno);
                } else {
                    printf("Linia : %d Valoarea expresiei este: false\n",yylineno);
                } 
            }
         }
#line 2325 "parser.tab.c"
    break;

  case 68: /* assignment_statement: ID '=' expression ';'  */
#line 799 "parser.y"
                                            {
                        if( ids.exista((yyvsp[-3].string)) ) {
                            Valoare result = (yyvsp[-1].ASTNode)->Eval();
                            Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == (yyvsp[-1].ASTNode)->TypeOf()){
                                if (var.val.tipul == "int") {
                                    var.val.isIntSet = true;
                                    var.val.intVal = result.intVal;
                                } else if (var.val.tipul == "float") {
                                    var.val.isFloatSet = true;
                                    var.val.floatVal = result.floatVal;
                                } else if (var.val.tipul == "bool") {
                                    var.val.isBoolSet = true;
                                    var.val.boolVal = result.boolVal;
                                }
                            } else {
                                printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                            } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }                   
                        } else {
                            printf("Error at line %d: Variable not found.1\n", yylineno);
                            return 1;
                        }
                    }
#line 2363 "parser.tab.c"
    break;

  case 69: /* assignment_statement: ID '=' CHAR ';'  */
#line 832 "parser.y"
                                      {
                        if( ids.exista((yyvsp[-3].string)) ) {

                            Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == "char"){
                                    var.val.isCharSet = true;
                                    var.val.charVal = (yyvsp[-1].character);  
                                } else {
                                    printf("Error at line %d: Different types.7\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 

                        } else {
                            printf("Error at line %d: Variable not found.2\n",yylineno);
                            return 1;
                        }
                    }
#line 2394 "parser.tab.c"
    break;

  case 70: /* assignment_statement: ID '=' STRING ';'  */
#line 858 "parser.y"
                                        {
                        if( ids.exista((yyvsp[-3].string)) ) {
                            Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                            if(var.val.esteConstanta) {
                                printf("Error at line %d: Cannot assign value to a constant variable.\n", yylineno);
                                return 1;
                            }
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (var.val.tipul == "string"){
                                    var.val.isStringSet = true;
                                    var.val.stringVal = (yyvsp[-1].string);  
                                } else {
                                    printf("Error at line %d: Different types.8\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }
                        } else {
                            printf("Error at line %d: Variable not found.3\n", yylineno);
                            return 1;
                        }
                    }
#line 2423 "parser.tab.c"
    break;

  case 71: /* assignment_statement: ID '[' INT ']' '=' expression ';'  */
#line 882 "parser.y"
                                                        {
                        Valoare result = (yyvsp[-1].ASTNode)->Eval();
                        if( ids.exista((yyvsp[-6].string)) ) {   
                            Vector& arr = ids.obtineVector((yyvsp[-6].string));
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (arr.tipul == result.tipul){
                                    arr.adauga((yyvsp[-4].integer), result);
                                } else {
                                    printf("Error at line %d: Different types.9\n",yylineno);
                                    return 1;
                                }   
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }
                        } else {
                            printf("Error at line %d: Variable not found.4\n",yylineno);
                            return 1;
                        }
                    }
#line 2448 "parser.tab.c"
    break;

  case 72: /* assignment_statement: ID '[' INT ']' '=' CHAR ';'  */
#line 902 "parser.y"
                                                  {
                        if( ids.exista((yyvsp[-6].string))) {
                            Vector& arr = ids.obtineVector((yyvsp[-6].string));
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                if (arr.tipul == "char"){
                                    Valoare val("char");
                                    val.charVal = (yyvsp[-1].character);
                                    val.isCharSet = true;
                                    val.tipul = "char";
                                    arr.adauga((yyvsp[-4].integer), val);
                                } else {
                                    printf("Error at line %d: Different types.10\n", yylineno);
                                    return 1;
                                } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.5\n", yylineno);
                            return 1;
                        }
                    }
#line 2477 "parser.tab.c"
    break;

  case 73: /* assignment_statement: ID '[' ID ']' '=' expression ';'  */
#line 926 "parser.y"
                                                       {
                        Valoare result = (yyvsp[-1].ASTNode)->Eval();
                        if( ids.exista((yyvsp[-6].string)) && ids.exista((yyvsp[-4].string))) {
                            Vector& arr = ids.obtineVector((yyvsp[-6].string));
                            if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Valoare& val = ids.obtineVariabila((yyvsp[-4].string)).val;
                                if (arr.tipul == result.tipul && val.tipul == "int"){
                                    arr.adauga(val.intVal, result);
                                } else {
                                    printf("Error at line %d: Different types.11\n", yylineno);
                                    return 1;
                                }  
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.6\n", yylineno);
                            return 1;
                        }
                    }
#line 2504 "parser.tab.c"
    break;

  case 74: /* assignment_statement: ID '[' ID ']' '=' CHAR ';'  */
#line 948 "parser.y"
                                                 {

                        if( ids.exista((yyvsp[-6].string)) && ids.exista((yyvsp[-4].string))) {
                            Vector& arr = ids.obtineVector((yyvsp[-6].string));
                            if (arr.context == context  || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Valoare& val = ids.obtineVariabila((yyvsp[-4].string)).val;
                                if (arr.tipul == "char" && val.tipul == "int"){
                                    Valoare v("char");
                                    v.charVal = (yyvsp[-1].character);
                                    v.isCharSet = true;
                                    v.tipul = "char";
                                    arr.adauga(val.intVal, v);
                                } else {
                                    printf("Error at line %d: Different types.12\n",yylineno);
                                    return 1;
                                }
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            }  

                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
#line 2535 "parser.tab.c"
    break;

  case 75: /* assignment_statement: ID '.' ID '=' expression ';'  */
#line 974 "parser.y"
                                                  {
                        if ( ids.exista((yyvsp[-5].string)) && ids.exista((yyvsp[-3].string)) && ids.obtineVariabila((yyvsp[-3].string)).context == ids.obtineVariabila((yyvsp[-5].string)).val.tipul ){
                            Valoare result = (yyvsp[-1].ASTNode)->Eval();
                            Variabila& var = ids.obtineVariabila((yyvsp[-5].string));
                            if (var.context == context  || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                                if (var.val.tipul == (yyvsp[-1].ASTNode)->TypeOf()){
                                if (var.val.tipul == "int") {
                                    var.val.isIntSet = true;
                                    var.val.intVal = result.intVal;
                                } else if (var.val.tipul == "float") {
                                    var.val.isFloatSet = true;
                                    var.val.floatVal = result.floatVal;
                                } else if (var.val.tipul == "bool") {
                                    var.val.isBoolSet = true;
                                    var.val.boolVal = result.boolVal;
                                }
                            } else {
                                printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                            } 
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }

                    }
#line 2571 "parser.tab.c"
    break;

  case 76: /* assignment_statement: ID '.' ID '=' CHAR ';'  */
#line 1005 "parser.y"
                                            {
                        if ( ids.exista((yyvsp[-5].string)) && ids.exista((yyvsp[-3].string)) && ids.obtineVariabila((yyvsp[-3].string)).context == ids.obtineVariabila((yyvsp[-5].string)).val.tipul ){
                            Variabila& var = ids.obtineVariabila((yyvsp[-5].string));
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                                if (var.val.tipul == "char"){
                                    var.val.charVal = (yyvsp[-1].character);
                                    var.val.isCharSet = true;
                                } else {
                                    printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                                }

                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
#line 2598 "parser.tab.c"
    break;

  case 77: /* assignment_statement: ID '.' ID '=' STRING ';'  */
#line 1027 "parser.y"
                                               {
                        if ( ids.exista((yyvsp[-5].string)) && ids.exista((yyvsp[-3].string)) && ids.obtineVariabila((yyvsp[-3].string)).context == ids.obtineVariabila((yyvsp[-5].string)).val.tipul ){
                            Variabila& var = ids.obtineVariabila((yyvsp[-5].string));
                            if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context) ) {
                                Variabila& var = ids.obtineVariabila((yyvsp[-3].string));
                                if (var.val.tipul == "string"){
                                    var.val.stringVal = (yyvsp[-1].string);
                                    var.val.isStringSet = true;
                                } else {
                                    printf("Error at line %d: Different types.\n", yylineno);
                                return 1;
                                }
                                
                            } else {
                                printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                                return 1;
                            } 
                        } else {
                            printf("Error at line %d: Variable not found.\n", yylineno);
                            return 1;
                        }
                    }
#line 2625 "parser.tab.c"
    break;

  case 93: /* expression: arithm_expr  */
#line 1077 "parser.y"
                        { (yyval.ASTNode) = (yyvsp[0].ASTNode); }
#line 2631 "parser.tab.c"
    break;

  case 94: /* expression: bool_expr  */
#line 1078 "parser.y"
                      { (yyval.ASTNode) = (yyvsp[0].ASTNode); }
#line 2637 "parser.tab.c"
    break;

  case 95: /* arithm_expr: arithm_expr '+' arithm_expr  */
#line 1083 "parser.y"
                                         {
               if((yyvsp[-2].ASTNode)->Eval().tipul == "bool" || (yyvsp[0].ASTNode)->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if((yyvsp[-2].ASTNode)->Eval().tipul == "string" || (yyvsp[0].ASTNode)->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "+", (yyvsp[0].ASTNode));                
                   
               else{
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,(yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }

           }
#line 2660 "parser.tab.c"
    break;

  case 96: /* arithm_expr: arithm_expr '-' arithm_expr  */
#line 1101 "parser.y"
                                         {
                if((yyvsp[-2].ASTNode)->Eval().tipul == "bool" || (yyvsp[0].ASTNode)->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if((yyvsp[-2].ASTNode)->Eval().tipul == "string" || (yyvsp[0].ASTNode)->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "-", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,(yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());
                    return 1;
               }
           }
#line 2681 "parser.tab.c"
    break;

  case 97: /* arithm_expr: arithm_expr '/' arithm_expr  */
#line 1117 "parser.y"
                                         {
            if((yyvsp[-2].ASTNode)->Eval().tipul == "bool" || (yyvsp[0].ASTNode)->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if((yyvsp[-2].ASTNode)->Eval().tipul == "string" || (yyvsp[0].ASTNode)->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "/", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,(yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
           }
#line 2702 "parser.tab.c"
    break;

  case 98: /* arithm_expr: arithm_expr '*' arithm_expr  */
#line 1133 "parser.y"
                                         {
            if((yyvsp[-2].ASTNode)->Eval().tipul == "bool" || (yyvsp[0].ASTNode)->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if((yyvsp[-2].ASTNode)->Eval().tipul == "string" || (yyvsp[0].ASTNode)->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "*", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno,(yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
           }
#line 2723 "parser.tab.c"
    break;

  case 99: /* arithm_expr: arithm_expr '%' arithm_expr  */
#line 1149 "parser.y"
                                         {
            if((yyvsp[-2].ASTNode)->Eval().tipul == "bool" || (yyvsp[0].ASTNode)->Eval().tipul == "bool"){
                    printf("Error at line %d: Invalid operation between bools.\n", yylineno);
                    return 1;
               }
               if((yyvsp[-2].ASTNode)->Eval().tipul == "string" || (yyvsp[0].ASTNode)->Eval().tipul == "string"){
                    printf("Error at line %d: Invalid operation between strings.\n", yylineno);
                    return 1;
               }
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "%", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s.\n", yylineno, (yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
                    
           }
#line 2745 "parser.tab.c"
    break;

  case 100: /* arithm_expr: '-' arithm_expr  */
#line 1166 "parser.y"
                             {
                (yyval.ASTNode) = new AST((yyvsp[0].ASTNode), "-", NULL);
           }
#line 2753 "parser.tab.c"
    break;

  case 101: /* arithm_expr: '(' arithm_expr ')'  */
#line 1169 "parser.y"
                                 {
                (yyval.ASTNode) = (yyvsp[-1].ASTNode);
           }
#line 2761 "parser.tab.c"
    break;

  case 102: /* arithm_expr: INT  */
#line 1172 "parser.y"
                 {
               char* identifierText = strdup(yytext);
               (yyval.ASTNode) = new AST(new Valoare(identifierText, "int")); 
           }
#line 2770 "parser.tab.c"
    break;

  case 103: /* arithm_expr: FLOAT  */
#line 1176 "parser.y"
                   {
               char* identifierText = strdup(yytext);
               (yyval.ASTNode) = new AST(new Valoare(identifierText, "float")); 
           }
#line 2779 "parser.tab.c"
    break;

  case 104: /* arithm_expr: fn_call  */
#line 1180 "parser.y"
                     {

                (yyval.ASTNode) = new AST((yyvsp[0].var)->val);
               
            }
#line 2789 "parser.tab.c"
    break;

  case 105: /* arithm_expr: ID  */
#line 1185 "parser.y"
                {
                if( ids.exista((yyvsp[0].string)) ) {
                    Variabila var = ids.obtineVariabila((yyvsp[0].string));
                    if (var.context == context || var.context == "global" || (ids.exista(context.c_str()) && var.context == ids.obtineFunctie(context.c_str()).context)){
                        Valoare val = var.Eval();
                        (yyval.ASTNode) = new AST(val);
                    }else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
#line 2810 "parser.tab.c"
    break;

  case 106: /* arithm_expr: ID '.' ID  */
#line 1201 "parser.y"
                       { 
                if( ids.exista((yyvsp[-2].string)) ) {
                    Variabila obj = ids.obtineVariabila((yyvsp[-2].string));
                    if (obj.context == context || obj.context == "global" || (ids.exista(context.c_str()) && obj.context == ids.obtineFunctie(context.c_str()).context)){
                        if( ids.exista((yyvsp[0].string)) ) {
                            Variabila var = ids.obtineVariabila((yyvsp[0].string));
                            if( var.context == obj.val.tipul ){
                                (yyval.ASTNode) = new AST(var.val);
                            } else {
                                printf("Error at line %d: No %s member in class %s.\n",yylineno, (yyvsp[0].string), (yyvsp[-2].string));
                                return 0;
                            }
                                
                        } else {
                            printf("Error at line %d: No %s member in class %s.\n",yylineno, (yyvsp[0].string), (yyvsp[-2].string));
                            return 0;
                        }

                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                } else {
                    printf("Error at line %d: Class %s not found.\n",yylineno, (yyvsp[-2].string));
                    return 1;
                }
           }
#line 2842 "parser.tab.c"
    break;

  case 107: /* arithm_expr: ID '.' fn_call  */
#line 1228 "parser.y"
                            {
                if( ids.exista((yyvsp[-2].string)) ) {
                    Variabila obj = ids.obtineVariabila((yyvsp[-2].string));
                    if (obj.context == context || obj.context == "global" || (ids.exista(context.c_str()) && obj.context == ids.obtineFunctie(context.c_str()).context)){

                        Functie fn = ids.obtineFunctie((yyvsp[0].var)->nume.c_str());

                        if( obj.val.tipul == fn.context ){
                            (yyval.ASTNode) = new AST((yyvsp[0].var)->val);
                        } else {
                            printf("Error at line %d: No %s method found in class variable %s.", yylineno, (yyvsp[0].var)->nume.c_str(), (yyvsp[-2].string));
                            return 0;
                        }
                        
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                } else {

                    printf("Error at line %d: Variable %s not found.\n",yylineno, (yyvsp[-2].string));
                    return 1;

                }
           }
#line 2873 "parser.tab.c"
    break;

  case 108: /* arithm_expr: ID '[' ID ']'  */
#line 1254 "parser.y"
                           {
                if( ids.exista((yyvsp[-3].string)) && ids.exista((yyvsp[-1].string))) {
                    Vector arr = ids.obtineVector((yyvsp[-3].string));
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        Valoare val = ids.obtineVariabila((yyvsp[-1].string)).Eval();
                        if( val.tipul == "int" )
                            (yyval.ASTNode) = new AST(arr.obtineValoare(val.intVal));
                        else 
                            printf("Error at line %d: Invalid index type.\n", yylineno);
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
#line 2896 "parser.tab.c"
    break;

  case 109: /* arithm_expr: ID '[' INT ']'  */
#line 1272 "parser.y"
                            {
                if( ids.exista((yyvsp[-3].string)) ) {
                    Vector arr = ids.obtineVector((yyvsp[-3].string));
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        (yyval.ASTNode) = new AST(arr.obtineValoare((yyvsp[-1].integer)));
                    } else {
                        printf("Error at line %d: Variable not found in this scope.\n", yylineno);
                        return 1;
                    }
                    
                }else 
                    printf("Error at line %d: Variable not found.\n", yylineno);
           }
#line 2914 "parser.tab.c"
    break;

  case 110: /* arithm_expr: ID '[' fn_call ']'  */
#line 1285 "parser.y"
                                {
                if( ids.exista((yyvsp[-3].string))) {
                    Vector arr = ids.obtineVector((yyvsp[-3].string));
                    if (arr.context == context || arr.context == "global" || (ids.exista(context.c_str()) && arr.context == ids.obtineFunctie(context.c_str()).context)){
                        if( (yyvsp[-1].var)->val.tipul == "int" )
                            (yyval.ASTNode) = new AST(arr.obtineValoare((yyvsp[-1].var)->val.intVal));
                        else 
                            printf("Error at line %d: Invalid index type.\n", yylineno);
                    }
                } else {
                    printf("Error at line %d: Variable not found.\n", yylineno);
                    return 1;
                }
           }
#line 2933 "parser.tab.c"
    break;

  case 111: /* bool_expr: bool_expr AND bool_expr  */
#line 1302 "parser.y"
                                   {
               (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "and", (yyvsp[0].ASTNode)); 
         }
#line 2941 "parser.tab.c"
    break;

  case 112: /* bool_expr: bool_expr OR bool_expr  */
#line 1305 "parser.y"
                                  {
               (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "or", (yyvsp[0].ASTNode)); 
           }
#line 2949 "parser.tab.c"
    break;

  case 113: /* bool_expr: NOT bool_expr  */
#line 1308 "parser.y"
                         {
               (yyval.ASTNode) = new AST((yyvsp[0].ASTNode), "not", NULL); 
         }
#line 2957 "parser.tab.c"
    break;

  case 114: /* bool_expr: '(' bool_expr ')'  */
#line 1311 "parser.y"
                             {
            (yyval.ASTNode) = (yyvsp[-1].ASTNode);
         }
#line 2965 "parser.tab.c"
    break;

  case 115: /* bool_expr: BOOL  */
#line 1314 "parser.y"
                { 
            char* identifierText = strdup(yytext);
            (yyval.ASTNode) = new AST(new Valoare(identifierText, "bool"));
          }
#line 2974 "parser.tab.c"
    break;

  case 116: /* bool_expr: arithm_expr GT arithm_expr  */
#line 1318 "parser.y"
                                      {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "gt", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, (yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
           }
#line 2987 "parser.tab.c"
    break;

  case 117: /* bool_expr: arithm_expr LT arithm_expr  */
#line 1326 "parser.y"
                                      {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "lt", (yyvsp[0].ASTNode)); 
               else{
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, (yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
           }
#line 3000 "parser.tab.c"
    break;

  case 118: /* bool_expr: arithm_expr GEQ arithm_expr  */
#line 1334 "parser.y"
                                       {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "geq", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types between: %s and %s\n", yylineno, (yyvsp[-2].ASTNode)->Eval().tipul.c_str(), (yyvsp[0].ASTNode)->Eval().tipul.c_str());            
                    return 1;
               }
           }
#line 3013 "parser.tab.c"
    break;

  case 119: /* bool_expr: arithm_expr LEQ arithm_expr  */
#line 1342 "parser.y"
                                       {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "leq", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
                    
           }
#line 3027 "parser.tab.c"
    break;

  case 120: /* bool_expr: arithm_expr EQ arithm_expr  */
#line 1351 "parser.y"
                                      {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "eq", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
           }
#line 3040 "parser.tab.c"
    break;

  case 121: /* bool_expr: arithm_expr NEQ arithm_expr  */
#line 1359 "parser.y"
                                       {
               if ((yyvsp[-2].ASTNode)->Eval().tipul == (yyvsp[0].ASTNode)->Eval().tipul)
                   (yyval.ASTNode) = new AST((yyvsp[-2].ASTNode), "neq", (yyvsp[0].ASTNode)); 
               else {
                    printf("Error at line %d: Different types.\n", yylineno);
                    return 1;
               }
           }
#line 3053 "parser.tab.c"
    break;

  case 122: /* fn_call: ID '(' argument_list ')'  */
#line 1370 "parser.y"
                                  { 
            
            if( ids.exista((yyvsp[-3].string)) ) {
                Functie fn = ids.obtineFunctie((yyvsp[-3].string));
                if (fn.context == context || fn.context == "global" || ids.existaVariabila(fn.context.c_str(), context) ){
                        if ( parametri.size() != fn.parametri.size() ){
                        printf("Error at line %d: The %s function call has inapropriate number of parameters.\n", yylineno, fn.nume.c_str());
                        return 1;
                    } else {
                        for( int i = 0; i < parametri.size(); i++ ) {
                            if (parametri.at(i).tipul != fn.parametri.at(i).tipul){
                                printf("Error at line %d: Illegal call params.\n", yylineno);
                                return 1;
                            }
                        }
                        parametri.clear();

                        Valoare result(fn.returnType);
                        if( result.tipul == "int" ){
                            result.intVal = 0;
                            result.isIntSet = true;
                        } else if( result.tipul == "float" ){
                            result.floatVal = 0.0;
                            result.isFloatSet = true;
                        } else if( result.tipul == "bool" ){
                            result.boolVal = true;
                            result.isIntSet = true;
                        } else if( result.tipul == "char" ){
                            result.charVal = '\0';
                            result.isCharSet = true;
                        } else if( result.tipul == "string" ){
                            result.stringVal = "";
                            result.isStringSet = true;
                        }

                        (yyval.var) = new Variabila(fn.nume.c_str(), result);

                    }
                } else {
                    printf("Error at line %d: Function not found in this scope.\n", yylineno);
                    return 1;
                }

                
            }
        }
#line 3104 "parser.tab.c"
    break;

  case 124: /* argument_list: expression  */
#line 1420 "parser.y"
                          { parametri.push_back((yyvsp[0].ASTNode)->Eval());}
#line 3110 "parser.tab.c"
    break;

  case 125: /* argument_list: argument_list ',' expression  */
#line 1421 "parser.y"
                                            { parametri.push_back((yyvsp[0].ASTNode)->Eval());}
#line 3116 "parser.tab.c"
    break;


#line 3120 "parser.tab.c"

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

#line 1424 "parser.y"

void yyerror(const char * s) {
    std::cerr << "error: " << s << " at line:" << yylineno << std::endl;
}

int main(int argc, char** argv) {
    yyin = fopen(argv[1], "r");
    yyparse();

    /* ids.afiseazaVariabile();
    ids.afiseazaFunctii();
    ids.printUsrDefs();
    ids.afiseazaVectori(); */
    ids.exportToFile("symbol_table.txt");
    return 0;
}
