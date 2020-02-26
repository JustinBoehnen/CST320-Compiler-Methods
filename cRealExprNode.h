#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents real (double) number values
//*******************************************

#include "cAstNode.h"
#include "cExprNode.h"

extern cSymbolTable g_symbolTable;

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
    virtual cDeclNode* GetDecl()
    {
        return g_symbolTable.GlobalFind("real")->GetDecl();       
    }
protected:
    double m_value;
};
