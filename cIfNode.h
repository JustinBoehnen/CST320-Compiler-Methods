#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents if stmt
//*******************************************

#include "cStmtNode.h"

class cIfNode : public cStmtNode
{
public:
    cIfNode(cExprNode* condition, cStmtNode* ifStmt, cStmtNode* elseStmt) : cStmtNode() 
    {
        AddChild(condition);
        AddChild(ifStmt);
        AddChild(elseStmt);
    }

    virtual string NodeType() { return string("if"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
