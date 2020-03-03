#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents variable expression
//*******************************************

#include "cSymbol.h"
#include "cExprNode.h"
#include "cArrayDeclNode.h"

class cVarExprNode : public cExprNode
{
public:
    cVarExprNode(cSymbol* sym) : cExprNode()
    {
        AddChild(sym);
    }

    virtual string AttributesToString()
    {
        string ret = " size=\"" 
            + std::to_string(m_size) 
            + "\" offset=\"" 
            + std::to_string(m_offset) 
            + "\"";

        if(GetDecl()->GetDecl()->IsArray())
        {
            cArrayDeclNode* array = dynamic_cast<cArrayDeclNode*>(GetDecl()->GetDecl());

            ret += array->RowSizesAsString() + array->StartIndexesAsString();
        }

        return ret;
    }

    virtual cDeclNode* GetDecl()
    {
        return dynamic_cast<cSymbol*>(GetChild(0))->GetDecl();
    }
    string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); }
    void AddVariable(cVarExprNode* var) { AddAllChildren(var); }
    void AddExpr(cExprListNode* expr) { AddChild(expr); }
    virtual string NodeType() { return string("varref"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    cExprListNode* GetList() { return dynamic_cast<cExprListNode*>(GetChild(1)); }

    int GetSize() { return m_size; }
    int GetOffset() { return m_offset; }
    void SetSize(int size) { m_size = size; }
    void SetOffset(int offset) { m_offset = offset; }
    bool HasIndexes(){ return NumChildren() > 1; }

private:
    int m_size;
    int m_offset;
};
