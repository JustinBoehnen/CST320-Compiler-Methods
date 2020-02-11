#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable declaration
//*******************************************
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cBaseTypeNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cVarDeclNode : public cDeclNode
{
public:
    cVarDeclNode(cBaseTypeNode* type, cSymbol* sym) : cDeclNode()
    {
        if(g_symbolTable.GlobalFind(sym->GetName()))
            sym = new cSymbol(sym->GetName());
        
        AddChild(type);
        AddChild(g_symbolTable.Insert(sym));
    }

    virtual string NodeType() { return string("var_decl"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
