
#pragma once

#include "cDeclNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cFuncDeclNode : public cDeclNode
{
public:
    cFuncDeclNode(cSymbol* header, cDeclNode* type, cVarDeclsNode* vars, cBlockNode* block) : cDeclNode()
    {
        if(g_symbolTable.GlobalFind(header->GetName()))
            header = new cSymbol(header->GetName());
        
        AddChild(g_symbolTable.Insert(header));
        AddChild(vars);
        AddChild(block);
    }

    virtual string NodeType() { return string("proc"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
