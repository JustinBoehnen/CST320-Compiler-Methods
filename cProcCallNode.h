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

    virtual string AttributesToString()
    {
        return " paramSize=\"" + std::to_string(m_paramSize) + "\"";
    }

    cDeclNode* GetDecl() {return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl();}
    virtual string NodeType() { return string("procCall"); }    
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    void SetParamSize(int size){m_paramSize = size;}
private:
    int m_paramSize;
};
