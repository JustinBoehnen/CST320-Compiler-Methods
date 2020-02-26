#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable expression
//*******************************************

#include "cSymbol.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
public:
    cVarExprNode(cSymbol* sym) : cExprNode()
    {
        AddChild(sym);
    }

    virtual cDeclNode* GetDecl()
    {
        return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl();
    }
    string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); }
    void AddVariable(cVarExprNode* var) { AddAllChildren(var); }
    void AddExpr(cExprListNode* expr) { AddChild(expr); }
    virtual string NodeType() { return string("varref"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    cExprListNode* GetList() { return dynamic_cast<cExprListNode*>(GetChild(1)); }
};
