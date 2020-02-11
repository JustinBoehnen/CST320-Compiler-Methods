#pragma once

#include "cExprNode.h"
#include "cStmtNode.h"

class cWhileNode : public cStmtNode
{
public:
    cWhileNode(cExprNode* expr, cStmtNode* stmt) : cStmtNode()
    {
        AddChild(expr);
        AddChild(stmt);
    }

    virtual string NodeType() { return string("while"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
