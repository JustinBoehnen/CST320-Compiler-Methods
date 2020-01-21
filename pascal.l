%{
//**************************************
// lang.l
//
// Scanner definition file for CST 320 project
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Dec. 6, 2017
//

#include "lex.h"
#include "cSymbolTable.h"
#include "tokens.h"

    // comment out the other line to generate debug info
#define DO_RETURN(a) return (a)
//#define DO_RETURN(a) return Return(a)
int Return(int val);
void Find();
extern yylval_t yylval;
extern cSymbolTable g_symbolTable;

%}

%option noyywrap
%option noinput
%option nounput
%option yylineno


    /* definitions go here. PUNCTUATION is an example. */
PUNCTUATION         [\(\)\[\];,\.+\-*/=^<>]
INTCONST            [0-9]*
REALCONST           [0-9]*\.[0-9][0-9]*
COMMENT             \{.*\}
VARID               [a-zA-Z][a-zA-Z0-9]*
%%
"PROGRAM"                   DO_RETURN(PROGRAM);
"PROCEDURE"                 DO_RETURN(PROCEDURE);
"FUNCTION"                  DO_RETURN(FUNCTION);
"BEGIN"                     { 
                                g_symbolTable.IncreaseScope(); 
                                DO_RETURN(OPEN); 
                            }
"END"                       { 
                                g_symbolTable.DecreaseScope(); 
                                DO_RETURN(CLOSE); 
                            }
"IF"                        DO_RETURN(IF);
"THEN"                      DO_RETURN(THEN);
"ELSE"                      DO_RETURN(ELSE);
"WHILE"                     DO_RETURN(WHILE);
"REPEAT"                    DO_RETURN(REPEAT);
"UNTIL"                     DO_RETURN(UNTIL);
"FOR"                       DO_RETURN(FOR);
"DO"                        DO_RETURN(DO);
"TO"                        DO_RETURN(TO);
"DOWNTO"                    DO_RETURN(DOWNTO);
"FORWARD"                   DO_RETURN(FORWARD);
"CONST"                     DO_RETURN(CONST);
"TYPE"                      DO_RETURN(TYPE);
"VAR"                       DO_RETURN(VAR);
"ARRAY"                     DO_RETURN(ARRAY);
"RECORD"                    DO_RETURN(RECORD);
"OF"                        DO_RETURN(OF);
"NIL"                       DO_RETURN(NIL);
"WRITE"                     DO_RETURN(WRITE);
"integer"                   DO_RETURN(INTEGER);
"real"                      DO_RETURN(REAL);
"char"                      DO_RETURN(CHAR);
"<="                        DO_RETURN(LE);
">="                        DO_RETURN(GE);
":="                        DO_RETURN(ASSIGN);
"<>"                        DO_RETURN(NOT_EQUAL);
"OR"                        DO_RETURN(OR);
"DIV"                       DO_RETURN(DIV);
"MOD"                       DO_RETURN(MOD);
"AND"                       DO_RETURN(AND);
"NOT"                       DO_RETURN(NOT);
{PUNCTUATION}               DO_RETURN(yytext[0]);
{COMMENT}                   {}
{VARID}                     { 
                                Find(); 
                                DO_RETURN(IDENTIFIER); 
                            }
{INTCONST}                  DO_RETURN(INT_VAL);
{REALCONST}                 DO_RETURN(REAL_VAL);
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

void Find(){
    string str = yytext;

    for(int i = 0; str[i] != '\0'; ++i) 
        str[i] = tolower(str[i]);

    cSymbol* temp = g_symbolTable.LocalFind(str);
    if(!temp)
        yylval.symbol = g_symbolTable.Insert(str);
    else
        yylval.symbol = temp;   
}
