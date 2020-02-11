#pragma once
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cExprNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cConstDeclNode: public cDeclNode
{
public:
    cConstDeclNode(cSymbol* name, cExprNode* value): cDeclNode()
    {
        if(g_symbolTable.GlobalFind(name->GetName()))
            name = new cSymbol(name->GetName());

        AddChild(g_symbolTable.Insert(name));
        AddChild(value);
    }

    virtual string NodeType() { return string("const_decl"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
