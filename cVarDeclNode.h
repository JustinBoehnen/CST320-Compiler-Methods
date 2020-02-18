#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable declaration
//*******************************************
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cVarDeclNode : public cDeclNode
{
public:
    cVarDeclNode(cDeclNode* type, cSymbol* sym) : cDeclNode()
    {
        std::string name = sym->GetName();
        
        if(g_symbolTable.GlobalFind(name))
        {
            if(g_symbolTable.LocalFind(name))
                SemanticParseError("Symbol " + name + " already exists in current scope");
            else
            {
                sym = new cSymbol(name);
                g_symbolTable.Insert(sym); 
            }
        }
        else
            g_symbolTable.Insert(sym);
        
        sym->SetDecl(this);
        AddChild(type);
        AddChild(sym);
    }

    virtual string NodeType() { return string("var_decl"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
