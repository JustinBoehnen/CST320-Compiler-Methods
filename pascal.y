%{
//**************************************
// pascal.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Justin Boehnen

#include <iostream>
#include "lex.h"
#include "astnodes.h"
#include "cSymbolTable.h"
%}

%locations

 /* union defines the type for lexical values */
%union{
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
    cProcDeclNode*  proc_decl_node;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
    extern cSymbolTable g_symbolTable;
%}

%start  program

%token PROGRAM PROCEDURE FUNCTION FORWARD
%token OPEN CLOSE
%token WRITE
%token WHILE IF THEN ELSE REPEAT UNTIL
%token FOR DO TO DOWNTO
%token CONST TYPE VAR
%token RECORD ARRAY OF
%token NIL
%token CHAR INTEGER REAL
%token JUNK_TOKEN

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <real_val>  REAL_VAL
%token <int_val>   AND
%token <int_val>   OR
%token <int_val>   NOT
%token <int_val>   DIV
%token <int_val>   MOD
%token <int_val>   NOT_EQUAL
%token <int_val>   LE
%token <int_val>   GE
%token <int_val>   ASSIGN

%type <program_node> program
%type <symbol> header
%type <block_node> block
%type <base_type_node> type
%type <decls_node> decls
%type <ast_node> constdecls
%type <ast_node> constdecl
%type <ast_node> constant
%type <ast_node> typedecls
%type <ast_node> typedecl
%type <ast_node> singleType
%type <ast_node> rangeList
%type <ast_node> range
%type <var_decls_node> goodvar
%type <var_decls_node> onevar
%type <ast_node> recorddef
%type <var_decls_node> vardecls
%type <var_decls_node> vardecl;
%type <decls_node> procdecls
%type <var_decls_node> paramSpec
%type <proc_decl_node> procdecl
%type <var_decls_node> parlist
%type <id_list_node> idlist
%type <ast_node> func_call
%type <ast_node> funcProto
%type <ast_node> funcHeader
%type <symbol> procHeader
%type <stmts_node> statements
%type <stmt_node> statement
%type <expr_node> expr
%type <expr_node> oneExpr
%type <expr_node> addit
%type <expr_node> term
%type <expr_node> fact
%type <var_expr_node> variable
%type <var_expr_node> varpart
%type <expr_list_node> exprList
%type <ast_node> recHeader
%%

program: header block '.'
                                { $$ = new cProgramNode($1, $2);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
header: PROGRAM IDENTIFIER ';'
                                {  
                                    g_symbolTable.IncreaseScope();
                                    $$ = $2; 
                                }
block:  decls OPEN statements CLOSE
                                { 
                                    $$ = new cBlockNode($1, $3); 
                                    g_symbolTable.DecreaseScope();
                                }

decls: constdecls typedecls vardecls procdecls
                                { 
                                    if($1 != nullptr || $2 != nullptr
                                    || $3 != nullptr || $4 != nullptr)
                                    {
                                        $$ = new cDeclsNode();
                                        $$->AddDecls($3);
                                        $$->AddDecls($4);
                                    }
                                }
constdecls: CONST constdecl ';'
                                { }
        | /*empty */
                                { $$ = nullptr; }
constdecl: constdecl ';' IDENTIFIER '=' constant 
                                { }
        |  IDENTIFIER '=' constant 
                                { }
typedecls: TYPE typedecl
                                { }
        | /*empty */
                                { $$ = nullptr; }
typedecl: typedecl singleType
                                { }
        |  singleType
                                { }
        |  error ';'
                                {}
singleType:  IDENTIFIER '=' recHeader recorddef ';'
                                { }
        | IDENTIFIER '=' ARRAY '[' rangeList ']' OF type ';'
                                { }
rangeList: rangeList ',' range
                                { }
        |  range
                                { }
range: INT_VAL '.' '.' INT_VAL
                                { }

vardecls: VAR vardecl
                                { $$ = $2; }
        | /* empty */
                                { $$ = nullptr; }
vardecl: vardecl onevar
                                {
                                    $$ = $1;
                                    $$->AddVarDecls($2);
                                }
        | onevar
                                { $$ = $1; }
onevar: goodvar ';'
                                { $$ = $1; }
        | error ';'
                                { $$ = nullptr; }
goodvar: idlist ':' type
                                { $$ = new cVarDeclsNode($1, $3); }
procdecls: procdecls procdecl
                                { 
                                    if($1 == nullptr)
                                        $$ = new cDeclsNode();
                                    else
                                        $$ = $1;

                                    $$->AddDecl($2);
                                }
        | /* empty */
                                { $$ = nullptr;  }

procdecl: procHeader paramSpec ';' block ';'
                                { 
                                    $$ = new cProcDeclNode($1,$2,$4); 
                                }
        |  procHeader paramSpec ';' FORWARD ';'
                                { }
        |  funcProto ';' block ';'
                                { }
        |  funcProto ';' FORWARD ';'
                                { }
        |  error ';' block ';'
                                { }
        |  error ';' FORWARD ';'
                                { }
procHeader: PROCEDURE IDENTIFIER 
                                { 
                                    $$ = $2;
                                    g_symbolTable.IncreaseScope();
                                }
funcHeader: FUNCTION IDENTIFIER
                                { }
funcProto: funcHeader paramSpec ':' type
                                { }
paramSpec: '(' parlist ')'
                                { $$ = $2; }
        | /* empty */
                                { $$ = nullptr; }

idlist: idlist ',' IDENTIFIER
                                { 
                                    $$ = $1; 
                                    $$->AddSymbol($3);
                                }
    |    IDENTIFIER
                                { $$ = new cIdListNode($1); }

parlist: parlist ';' VAR idlist ':' type 
                                { 
                                    $$ = $1; //new cVarDeclsNode($4, $6);
                                    $$->AddVarDecls($4, $6);
                                }
    |    parlist ';' idlist ':' type 
                                {
                                    $$ = $1; //new cVarDeclsNode($3, $5);
                                    $$->AddVarDecls($3, $5);
                                }
    |    VAR idlist ':' type
                                { $$ = new cVarDeclsNode($2, $4); }
    |    idlist ':' type
                                { $$ = new cVarDeclsNode($1, $3); }

type: TYPE_ID
                                { $$ = $1->GetDecl(); }
recHeader: RECORD
                                { }
recorddef: vardecl CLOSE
                                { }
constant: INT_VAL
                                { }
    |   '-' INT_VAL
                                { }

statements: statements statement
                                { 
                                  $$ = $1;
                                  $$->AddStmt($2); 
                                }
    |   statement
                                { $$ = new cStmtsNode($1); }

statement: variable ASSIGN expr ';'
                                { $$ = new cAssignNode($1, $3); }
    |   IF expr THEN statement
                                { $$ = new cIfNode($2, $4, nullptr); }
    |   IF expr THEN statement ELSE statement
                                { $$ = new cIfNode($2, $4, $6); }
    |   REPEAT statements UNTIL expr ';'
                                { }
    |   WHILE expr DO statement
                                { $$ = new cWhileNode($2, $4); }
    |   FOR IDENTIFIER ASSIGN expr TO expr DO statement
                                {}
    |   FOR IDENTIFIER ASSIGN expr DOWNTO expr DO statement
                                {}
    |   IDENTIFIER '(' exprList ')' ';'
                                { $$ = new cProcCallNode($1, $3); }
    |   IDENTIFIER ';'
                                { $$ = new cProcCallNode($1, nullptr); }
    |   WRITE '(' exprList ')' ';'
                                { $$ = new cWriteNode($3); }
    |   OPEN statements CLOSE
                                { $$ = new cCompoundStmtNode($2); }
    |   NIL ';'
                                { $$ = new cNilNode(); }
    |   error ';'
                                { }

exprList: exprList ',' oneExpr
                                { 
                                  $$ = $1;
                                  $$->AddExpr($3); 
                                }
        | oneExpr
                                { $$ = new cExprListNode($1); }
        | /* empty */
                                { }
oneExpr: expr
                                { $$ = $1; }

func_call:  IDENTIFIER '(' exprList ')'
                                { }

variable: variable '.' varpart
                                { }
        | variable '[' exprList ']'
                                { }
        | varpart
                                { $$ = $1; }

varpart:  IDENTIFIER
                                { $$ = new cVarExprNode($1); }

expr:       expr '=' addit
                                { $$ = new cBinaryExprNode($1, new cOpNode('='), $3); }
        |   expr '>' addit
                                { $$ = new cBinaryExprNode($1, new cOpNode('>'), $3); }
        |   expr '<' addit
                                { $$ = new cBinaryExprNode($1, new cOpNode('<'), $3); }
        |   expr LE addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(LE), $3); }
        |   expr GE addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(GE), $3); }
        |   expr NOT_EQUAL addit
                                { $$ = new cBinaryExprNode($1, new cOpNode(NOT_EQUAL), $3); }
        |   addit
                                { $$ = $1; }

addit:      addit '+' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('+'), $3); }
        |   addit '-' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('-'), $3); }
        |   addit OR term
                                { $$ = new cBinaryExprNode($1, new cOpNode(OR), $3); }
        |   term
                                { $$ = $1; }
        |   '-' term
                                { $$ = new cUnaryExprNode('-', $2); }

term:       term '*' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('*'), $3); }
        |   term '/' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('/'), $3); }
        |   term MOD fact
                                { $$ = new cBinaryExprNode($1, new cOpNode(MOD), $3); }
        |   term DIV fact
                                { $$ = new cBinaryExprNode($1, new cOpNode(DIV), $3); }
        |   term AND fact
                                { $$ = new cBinaryExprNode($1, new cOpNode(AND), $3); }
        |   fact
                                { $$ = $1; }

fact:        '(' expr ')'
                                { $$ = $2; }
        |   INT_VAL
                                { $$ = new cIntExprNode($1); }
        |   REAL_VAL
                                { $$ = new cRealExprNode($1); }
        |   variable
                                { $$ = $1; }
        |   func_call
                                { }
        |   NOT fact
                                { $$ = new cUnaryExprNode(NOT, $2); }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
