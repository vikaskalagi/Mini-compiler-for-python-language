/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 87 "icg.y" /* yacc.c:1909  */

struct node *np;
	char var[10];

#line 133 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
