#pragma once
//**************************************
// cNilNode.h
//
// Defines an AST node for a no-op statement
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cStmtNode.h"

class cNilNode : public cStmtNode
{
    public:
        // param is the value of the integer constant
        cNilNode() : cStmtNode()
        {
        }

        virtual string NodeType() { return string("NIL"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
