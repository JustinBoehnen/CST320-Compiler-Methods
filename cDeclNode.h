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
        cDeclNode() : cAstNode() { m_offset = 0;}

        void AddBody(cAstNode* body)
        {
            AddChild(body);
        }

        int GetSize() {return m_size;}
        int GetOffset() {return m_offset;}
        void SetSize(int size) {m_size = size;}
        void SetOffset(int offset) {m_offset = offset;}

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
    
    protected:
        int m_size;
        int m_offset;
};
