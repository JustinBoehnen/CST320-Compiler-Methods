#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: Procedure call ast node
//*******************************************

#include "cStmtNode.h"

class cProcCallNode : public cStmtNode
{
public:
    cProcCallNode(cSymbol* name, cExprListNode* args) : cStmtNode()
    {
        AddChild(name);
        AddChild(args);
    }

    virtual string NodeType() { return string("procCall"); }    
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
