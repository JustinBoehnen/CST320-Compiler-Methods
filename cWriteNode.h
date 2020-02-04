#pragma once
//**************************************
// cWriteNode.h
//
// Defines AST node for WRITE statements
//
// Inherits from cStmtNode so WRITE statments can go in statement lists, and be
// used anywhere a statement is legal.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprListNode.h"

class cWriteNode : public cStmtNode
{
    public:
        // param is the value to be printed
        cWriteNode(cExprListNode *exprList) : cStmtNode()
        {
            AddChild(exprList);
        }

        virtual string NodeType() { return string("WRITE"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
