#pragma once

#include "cDeclNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cRecordDeclNode : public cDeclNode
{
public:
    cRecordDeclNode(cSymbol* header, cVarDeclsNode* decls) : cDeclNode()
    {
        if(g_symbolTable.GlobalFind(header->GetName()))
            header = new cSymbol(header->GetName());
        
        AddChild(g_symbolTable.Insert(header));
        AddChild(decls);
    }

    virtual string NodeType() { return string("record"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
