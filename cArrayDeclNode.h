#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: Array Declarations
//*******************************************
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

        name->SetDecl(this);
        AddChild(g_symbolTable.Insert(name));
        AddChild(type);
        AddChild(decls);
    }
   
    virtual cDeclsNode* GetDecls() { return dynamic_cast<cDeclsNode*>(GetChild(2)); }
    virtual string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); } 
    virtual bool IsArray() { return true; }
    virtual string NodeType() { return string("array"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
