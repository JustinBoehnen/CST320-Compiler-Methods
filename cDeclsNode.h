#pragma once
//**************************************
// cDeclsNode.h
//
// Defines a class to represent a list of declarations.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cDeclNode.h"
#include "cRangeDeclNode.h"

class cDeclsNode : public cAstNode
{
    public:
        // param is the first decl in this decls
        cDeclsNode(cDeclNode *decl = nullptr) : cAstNode()
        {
            if (decl != nullptr) AddChild(decl);
        }

        // Copy all the decls from another node into this one
        void AddDecls(cDeclsNode *decls) { AddAllChildren(decls); }

        // Add another decl to the list
        void AddDecl(cDeclNode *decl) { AddChild(decl); }

        int HasDecls(){ return HasChildren(); }

        int NumDecls(){ return NumChildren(); }

        cRangeDeclNode* GetRangeAt(int index)
        {
            return dynamic_cast<cRangeDeclNode*>(GetChild(index));
        }

        int GetNumChildren() { return NumChildren(); }
        virtual string NodeType() { return string("decls"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
