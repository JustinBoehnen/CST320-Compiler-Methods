#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable declaration
//*******************************************
#include "cDeclNode.h"
#include "cSymbol.h"
#include "cBaseTypeNode.h"

class cVarDeclNode : public cDeclNode
{
public:
    cVarDeclNode(cBaseTypeNode* type, cSymbol* sym) : cDeclNode()
    {
        AddChild(type);
        AddChild(sym);
    }

    virtual string NodeType() { return string("var_decl"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
