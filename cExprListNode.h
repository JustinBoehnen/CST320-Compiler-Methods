#pragma once
//**************************************
// cExprListNode.h
//
// Defines AST node for actual params passed to a function
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cExprNode.h"

class cExprListNode : public cAstNode
{
    public:
        // param is first actual param passed to function
        cExprListNode(cExprNode *param = nullptr)
            : cAstNode()
        {
            if (param != nullptr) AddChild(param);
        }

        void AddExpr(cExprNode* expr)
        {
            AddChild(expr);
        }

        cExprNode* GetParamAt(int index) 
        { 
            return dynamic_cast<cExprNode*>(GetChild(index)); 
        
        }

        cDeclNode* GetDeclAt(int index)
        {
            return dynamic_cast<cExprNode*>(GetChild(index))->GetDecl();
        }
        virtual int GetNumChildren() { return NumChildren(); } 
        virtual string NodeType() { return string("exprList"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
