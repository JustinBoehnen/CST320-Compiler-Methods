#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable assignments (:=)
//*******************************************
#include "cStmtNode.h"
#include "cVarExprNode.h"
#include "cExprNode.h"

class cAssignNode : public cStmtNode
{
public:
    cAssignNode(cVarExprNode* var, cExprNode* expr) : cStmtNode()
    {
        AddChild(var);
        AddChild(expr);
    }

    cVarExprNode* GetLeft() { return dynamic_cast<cVarExprNode*>(GetChild(0)); }
    cExprNode* GetRight() { return dynamic_cast<cExprNode*>(GetChild(1)); }
    virtual string NodeType() { return string("assign"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
