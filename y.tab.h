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
#line 22 "calc.y" /* yacc.c:1909  */

   float f;
   int i;
   char* s;
   Number n;

#line 113 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
