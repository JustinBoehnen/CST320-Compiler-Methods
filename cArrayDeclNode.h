#pragma once
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cArrayDeclNode: public cDeclNode
{
public:
    cArrayDeclNode(cSymbol* name, cDeclNode* type, cDeclsNode* decls)
        :cDeclNode()
    {
        if(g_symbolTable.GlobalFind(name->GetName()))
            name = new cSymbol(name->GetName());

        AddChild(g_symbolTable.Insert(name));
        AddChild(type);
        AddChild(decls);
    }
    
        virtual string NodeType() { return string("array"); }
        virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
