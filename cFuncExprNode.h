#include "cExprNode.h"

class cFuncExprNode : public cExprNode
{
public
    cFuncExprNode( cSymbol* name, cExprListNode*) : cExprNode()
    {
        AddChild()
    }
    
    virtual string NodeType() { return string("funcCall"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
