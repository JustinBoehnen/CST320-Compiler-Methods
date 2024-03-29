#pragma once
//**************************************
// cBlockNode.h
//
// Defines AST node for a block of code (stuff inside {})
//
// Since blocks can take the place of statements, this class inherits from 
// cStmtNode
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cDeclsNode.h"
#include "cStmtNode.h"
#include "cStmtsNode.h"

class cBlockNode : public cStmtNode
{
    public:
        // params are the decls and statements contained in the block
        cBlockNode(cDeclsNode *decls, cStmtsNode *statements)
            : cStmtNode()
        {
            AddChild(decls);
            AddChild(statements);
        }

        virtual string AttributesToString()
        {
            return " size=\"" + std::to_string(m_size) + "\"";
        }

        virtual cDeclsNode* GetDecls() { return dynamic_cast<cDeclsNode*>(GetChild(0)); }
        virtual cStmtsNode* GetStmts() { return dynamic_cast<cStmtsNode*>(GetChild(1)); }
        virtual string NodeType() { return string("block"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        void SetSize(int size) { m_size = size;}
        int GetSize() {return m_size;}

    private:
        int m_size;
};
