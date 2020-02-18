%{
//**************************************
// pascal.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Justin Boehnen

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR;} }

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
    cVarDeclNode*   var_decl_node;
    cVarDeclsNode*  var_decls_node;
    cBaseTypeNode*  base_type_node;
    cVarExprNode*   var_expr_node;
    cProcDeclNode*  proc_decl_node;
    cRangeDeclNode* range_decl_node;
    cFuncDeclNode*  func_decl_node;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
    extern cSymbolTable g_symbolTable;
    static bool g_semanticErrorHappened;
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
%type <symbol> type
%type <decls_node> decls
%type <decls_node> constdecls
%type <decls_node> constdecl
%type <expr_node> constant
%type <decls_node> typedecls
%type <decls_node> typedecl
%type <decl_node> singleType
%type <decls_node> rangeList
%type <range_decl_node> range
%type <var_decls_node> goodvar
%type <var_decls_node> onevar
%type <var_decls_node> recorddef
%type <var_decls_node> vardecls
%type <var_decls_node> vardecl;
%type <decls_node> procdecls
%type <var_decls_node> paramSpec
%type <proc_decl_node> procdecl
%type <var_decls_node> parlist
%type <id_list_node> idlist
%type <expr_node> func_call
%type <func_decl_node> funcProto
%type <func_decl_node> funcHeader
%type <proc_decl_node> procHeader
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
                                        $$->AddDecls($1);
                                        $$->AddDecls($2);
                                        $$->AddDecls($3);
                                        $$->AddDecls($4);
                                    }
                                }
constdecls: CONST constdecl ';'
                                { $$ = $2; }
        | /*empty */
                                { $$ = nullptr; }
constdecl: constdecl ';' IDENTIFIER '=' constant 
                                { 
                                    $$ = $1;
                                    $$->AddDecl(new cConstDeclNode($3, $5));
                                }
        |  IDENTIFIER '=' constant 
                                { $$ = new cDeclsNode(new cConstDeclNode($1, $3)); }
typedecls: TYPE typedecl
                                { $$ = $2; }
        | /*empty */
                                { $$ = nullptr; }
typedecl: typedecl singleType
                                { 
                                    $$ = $1;
                                    $$->AddDecl($2); 
                                }
        |  singleType
                                { $$ = new cDeclsNode($1); }
        |  error ';'
                                {}
singleType:  IDENTIFIER '=' recHeader recorddef ';'
                                { 
                                    $1->SetIsType(true);
                                    $$ = new cRecordDeclNode($1, $4); 
                                    //$1->SetDecl($$);
                                }

        | IDENTIFIER '=' ARRAY '[' rangeList ']' OF type ';'
                                { 
                                    $1->SetIsType(true);
                                    $$ = new cArrayDeclNode($1, $8->GetDecl(), $5);
                                    //$1->SetDecl($$);
                                }

rangeList: rangeList ',' range
                                { 
                                    $$ = $1;
                                    $$->AddDecl($3); 
                                }
        |  range
                                { $$ = new cDeclsNode($1); }
range: INT_VAL '.' '.' INT_VAL
                                { $$ = new cRangeDeclNode($1, $4); }

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
                                { }
goodvar: idlist ':' type
                                { 
                                    $$ = new cVarDeclsNode($1, $3->GetDecl()); 
                                    PROP_ERROR();
                                }
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
                                    $$ = $1;
                                    $$->AddParameters($2);
                                    $$->AddBlock($4);
                                    CHECK_ERROR(); 
                                }
        |  procHeader paramSpec ';' FORWARD ';'
                                { 
                                    $$ = $1; 
                                    $$->AddParameters($2);
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }
        |  funcProto ';' block ';'
                                { 
                                    $$ = $1;
                                    $$->AddBlock($3);
                                    CHECK_ERROR();
                                }
        |  funcProto ';' FORWARD ';'
                                { 
                                    $$ = $1;
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }
        |  error ';' block ';'
                                { }
        |  error ';' FORWARD ';'
                                { }
procHeader: PROCEDURE IDENTIFIER 
                                { 
                                    $$ = new cProcDeclNode($2);
                                    g_symbolTable.IncreaseScope();
                                }
funcHeader: FUNCTION IDENTIFIER
                                { 
                                    $$ = new cFuncDeclNode($2);
                                    g_symbolTable.IncreaseScope();    
                                }
funcProto: funcHeader paramSpec ':' type
                                { $$->AddTypeParameters($4->GetDecl(), $2); }
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
                                    $$->AddVarDecls($4, $6->GetDecl());
                                }
    |    parlist ';' idlist ':' type 
                                {
                                    $$ = $1; //new cVarDeclsNode($3, $5);
                                    $$->AddVarDecls($3, $5->GetDecl());
                                }
    |    VAR idlist ':' type
                                { $$ = new cVarDeclsNode($2, $4->GetDecl()); }
    |    idlist ':' type
                                { $$ = new cVarDeclsNode($1, $3->GetDecl()); }

type: TYPE_ID
                                { $$ = $1; }
recHeader: RECORD
                                { g_symbolTable.IncreaseScope(); }
recorddef: vardecl CLOSE
                                { 
                                    $$ = $1;
                                    g_symbolTable.DecreaseScope();    
                                }
constant: INT_VAL
                                { $$ = new cIntExprNode($1); }
    |   '-' INT_VAL
                                { $$ = new cUnaryExprNode('-', new cIntExprNode($2)); }

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
                                { $$ = nullptr; }
oneExpr: expr
                                { $$ = $1; }

func_call:  IDENTIFIER '(' exprList ')'
                                { $$ = new cFuncExprNode($1, $3); }

variable: variable '.' varpart
                                { 
                                    $$ = $1;
                                    $$->AddVariable($3);
                                }
        | variable '[' exprList ']'
                                { 
                                    $$ = $1;
                                    $$->AddExpr($3);
                                 }
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
                                { $$ = $1; }
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

void SemanticParseError(std::string error)
{
    std::cout << "ERROR: " << error << " on line " << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
