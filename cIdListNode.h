#pragma once

#include "cAstNode.h"
#include "cSymbol.h"

class cIdListNode : public cAstNode
{
public:
    cIdListNode(cSymbol* sym) : cAstNode()
    {
        AddChild(sym);
    }

    void AddSymbol(cSymbol* sym)
    {
        AddChild(sym);
    }

    cSymbol* GetSymbol(int index)
    {
        return dynamic_cast<cSymbol*>(GetChild(index));
    }

    virtual string NodeType() { return string("IdList"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
