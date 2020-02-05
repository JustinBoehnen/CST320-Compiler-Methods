#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable expression
//*******************************************

#include "cSymbol.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
public:
    cVarExprNode(cSymbol* sym) : cExprNode()
    {
        AddChild(sym);
    }

    virtual string NodeType() { return string("varref"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
