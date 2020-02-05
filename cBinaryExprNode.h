#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents binary expression
//*******************************************
#include "cAstNode.h"
#include "cExprNode.h"

class cBinaryExprNode : public cExprNode
{
public:
    cBinaryExprNode(cExprNode* leftop, cOpNode* op, cExprNode* rightop)
        : cExprNode()
    {
        AddChild(leftop);
        AddChild(op);
        AddChild(rightop);
    }

    virtual string NodeType() { return string("expr"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
