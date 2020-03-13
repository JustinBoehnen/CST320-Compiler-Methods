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

    cExprNode* GetExpr() {return dynamic_cast<cExprNode*>(GetChild(0));}
    cStmtNode* GetStmt() {return dynamic_cast<cStmtNode*>(GetChild(1));}
    virtual string NodeType() { return string("while"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
