#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents binary expression
//*******************************************
#include "cAstNode.h"
#include "cExprNode.h"

extern cSymbolTable g_symbolTable;

class cBinaryExprNode : public cExprNode
{
public:
    cBinaryExprNode(cExprNode* leftop, cOpNode* op, cExprNode* rightop)
        : cExprNode()
    {
        AddChild(leftop);
        AddChild(op);
        AddChild(rightop);
    }

    virtual cDeclNode* GetDecl()
    {
        cDeclNode* left = dynamic_cast<cExprNode*>(GetChild(0))->GetDecl();
        cDeclNode* right = dynamic_cast<cExprNode*>(GetChild(2))->GetDecl();

        if(left->IsFunc() || left->IsVar())
            left = left->GetDecl();
        if(right->IsFunc() || right->IsVar())
            right = right->GetDecl();

        if(left->IsReal() || right->IsReal())
            return g_symbolTable.GlobalFind("real")->GetDecl();
        else if (left->IsInt() || right->IsInt())
            return g_symbolTable.GlobalFind("integer")->GetDecl();
        else
            return g_symbolTable.GlobalFind("char")->GetDecl();
    }
    cExprNode* GetLeft(){return dynamic_cast<cExprNode*>(GetChild(0));}
    cExprNode* GetRight(){return dynamic_cast<cExprNode*>(GetChild(2));}
    int GetOp(){return dynamic_cast<cOpNode*>(GetChild(1))->GetOp();}
    virtual string NodeType() { return string("expr"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
