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
    
    virtual string AttributesToString()
    {
        return " paramSize=\"" + std::to_string(m_paramSize) + "\"";
    }

    virtual string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); }
    virtual int GetNumParams() 
    {   
        if(GetChild(1) != nullptr)
            return dynamic_cast<cExprListNode*>(GetChild(1))->GetNumChildren();
        else
           return 0; 
    }
    cExprListNode* GetParams() { return dynamic_cast<cExprListNode*>(GetChild(1)); }
    virtual string NodeType() { return string("funcCall"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    virtual cDeclNode* GetDecl()
    {
        return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl();
    }
    void SetParamSize(int size){m_paramSize = size;};
private:
    int m_paramSize;
};
