#pragma once

#include "cDeclNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cFuncDeclNode : public cDeclNode
{
public:
    cFuncDeclNode(cSymbol* header) : cDeclNode()
    {
        if(g_symbolTable.GlobalFind(header->GetName()))
            header = new cSymbol(header->GetName());
        
        AddChild(g_symbolTable.Insert(header));
    }

    void AddTypeParameters(cDeclNode* type, cDeclsNode* params)
    {
        AddChild(type);
        AddChild(params);
    }

    virtual string NodeType() { return string("func"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
