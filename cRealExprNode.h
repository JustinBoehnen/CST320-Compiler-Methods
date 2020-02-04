#pragma once

#include "cAstNode.h"
#include "cExprNode.h"

class cRealExprNode : public cExprNode
{
public:
    cRealExprNode(double value) : cExprNode()
    {
        m_value = value;
    }
    
    virtual string AttributesToString()
    {
        return " value=\"" + std::to_string(m_value) + "\"";
    }
    virtual string NodeType() { return string("REAL"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
protected:
    double m_value;
};
