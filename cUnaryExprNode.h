#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents unary expressions
//*******************************************

#include "cAstNode.h"
#include "cExprNode.h"

class cUnaryExprNode : public cExprNode
{
public:
    cUnaryExprNode(int op, cExprNode* expr)
        :cExprNode()
    {
        AddChild(new cOpNode(op));
        AddChild(expr);
    }

    virtual string NodeType() { return string("unaryExpr"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
