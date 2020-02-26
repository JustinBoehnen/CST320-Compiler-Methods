#pragma once
//**************************************
// cExprNode.h
//
// Defines base class for all expressions
//
// This is a pure virtual class because there is no definition for
// cAstNode::NodeType()
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cStmtNode.h"
#include "cDeclNode.h"

class cExprNode : public cStmtNode
{
    public:
        cExprNode() : cStmtNode() {}

        virtual cDeclNode* GetDecl() = 0;
};
