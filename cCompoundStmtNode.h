#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents list of stmts
//*******************************************

#include "cStmtNode.h"
#include "cStmtsNode.h"

class cCompoundStmtNode : public cStmtNode
{
public:
    cCompoundStmtNode(cStmtsNode* list) : cStmtNode()
    {
        AddAllChildren(list);
    }

    virtual string NodeType() { return string("compound"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
