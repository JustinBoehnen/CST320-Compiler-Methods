#pragma once
#include "cExprNode.h"
#include "cSymbol.h"
#include "cExprListNode.h"

class cFuncExprNode : public cExprNode
{
public:
    cFuncExprNode( cSymbol* name, cExprListNode* params) : cExprNode()
    {
        AddChild(name);
        AddChild(params);
    }
    
    virtual string NodeType() { return string("funcCall"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
