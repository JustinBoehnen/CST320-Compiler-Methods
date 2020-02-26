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
#line 23 "pascal.y" /* yacc.c:1909  */

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
    cVarDeclNode*   var_decl_node;
    cVarDeclsNode*  var_decls_node;
    cBaseTypeNode*  base_type_node;
    cVarExprNode*   var_expr_node;
    cProcDeclNode*  proc_decl_node;
    cRangeDeclNode* range_decl_node;
    cFuncDeclNode*  func_decl_node;
    

#line 123 "pascalparse.h" /* yacc.c:1909  */
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