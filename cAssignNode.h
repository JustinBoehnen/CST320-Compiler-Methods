#pragma once
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

    virtual string NodeType() { return string("assign"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
