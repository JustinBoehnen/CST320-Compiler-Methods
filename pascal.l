%{
//**************************************
// lang.l
//
// Scanner definition file for CST 320 project
//
// Author: Justin Boehnen

#include "lex.h"
#include "cSymbolTable.h"
#include "pascalparse.h"

    // comment out the other line to generate debug info
#define DO_RETURN(a) return (a)
//#define DO_RETURN(a) return Return(a)
int Return(int val);
int Find();
extern YYSTYPE yylval;
extern cSymbolTable g_symbolTable;

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. PUNCTUATION is an example. */
PUNCTUATION         [:\(\)\[\];,\.+\-*/=^<>]
INTCONST            [0-9]*
REALCONST           [0-9]+\.[0-9][0-9]*
COMMENT             \{.*\}
IDENT               [a-zA-Z][a-zA-Z0-9]*
%%
"<="                        DO_RETURN(LE);
">="                        DO_RETURN(GE);
":="                        DO_RETURN(ASSIGN);
"<>"                        DO_RETURN(NOT_EQUAL);

{PUNCTUATION}               DO_RETURN(yytext[0]);
{COMMENT}                   {}
{IDENT}                     DO_RETURN(Find()); 
{INTCONST}                  {
                                yylval.int_val = atoi(yytext);
                                DO_RETURN(INT_VAL);
                            }
{REALCONST}                 {
                                yylval.real_val = atof(yytext);
                                DO_RETURN(REAL_VAL);
                            }
"\n"                        {}
"\t"                        {}
" "                         {}
.                           DO_RETURN(JUNK_TOKEN);
%%

// This function allows us to do extra processing on each token
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}

int Find(){
    string str = yytext;

    for(int i = 0; str[i] != '\0'; ++i) 
        str[i] = tolower(str[i]);

    cSymbol* temp = g_symbolTable.GlobalFind(str);
    if(!temp)
        yylval.symbol = new cSymbol(str); // new g_symbolTable.Insert(str);
    else
        yylval.symbol = temp;

    return yylval.symbol->GetIsType() ? TYPE_ID : yylval.symbol->GetType();
}
