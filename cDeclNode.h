#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode() {}

        void AddBody(cAstNode* body)
        {
            AddChild(body);
        }

        virtual string GetName() { return string("");}
        virtual cDeclNode* GetDecl() { return nullptr; }
        //virtual cDeclNode* GetDecl() = 0;
        virtual bool IsReal() {return false;}
        virtual bool IsInt() {return false;}
        virtual bool IsChar() {return false;}
        virtual bool IsType() {return false;}
        virtual bool IsFunc() {return false;}
        virtual bool IsVar() {return false;}
        virtual bool IsArray() {return false;}
};
