#pragma once

#include "cVisitor.h"
#include "astnodes.h"

class cComputeSize : public cVisitor
{
public:
    cComputeSize() : cVisitor()
    {
        m_offset = 0;   
    }
    
    virtual void VisitAllNodes(cAstNode* node)
    {
        node->VisitAllChildren(this);
    }

    virtual void Visit(cBlockNode* node)
    {
        node->VisitAllChildren(this);   

        m_offset = RoundUp(m_offset);
        node->SetSize(m_offset);
    } 

    virtual void Visit(cVarDeclNode* node)
    {
        int size = node->GetDecl()->GetSize();
        node->SetSize(size);

        if(size != 1)
            m_offset = RoundUp(m_offset);

        node->SetOffset(m_offset);

        m_offset += (m_offset < 0 ? -size : size);
        
        if(m_offset < 0)
            m_offset = RoundUp(m_offset);
    }

    virtual void Visit(cVarDeclsNode* node)
    {
        m_offset = -12;
        node->VisitAllChildren(this);
        
        node->SetSize(-(m_offset + 12));
    }

    virtual void Visit(cVarExprNode* node)
    {
        node->VisitAllChildren(this);

        node->SetOffset(node->GetDecl()->GetOffset());
        if(node->GetDecl()->GetDecl()->IsArray() && node->HasIndexes())
            node->SetSize(node->GetDecl()->GetDecl()->GetDecl()->GetSize());
        else
            node->SetSize(node->GetDecl()->GetSize());
        
        /*
        cDeclNode* varDecl = node->GetDecl();

        node->SetSize(varDecl->GetSize());
        node->SetOffset(varDecl->GetOffset());

        cDeclNode* type = varDecl->GetType();

        if(type->IsArray())
        {
            cArrayDeclNode* array = dynamic_cast<cArrayDeclNode*>(type);
            node->SetSize(array->GetBaseType()->GetSize());

            int index = 0;
            while (index < array->NumIndexes())
            {
                index += array->NumIndexes();
                for(int i=0; i < array->NumIndexes(); i++)
                {
                    node->SetRowSize(array->GetRowSize(i));
                    node->SetRowStart(array->GetRowStart(i));
                }
                type = array->GetBaseType();
                if (type->IsArray()) array = dynamic_cast<cArrayDeclNode*>(type);
            }
        }
        node->VistAllChildren(this);
        */
    }

    virtual void Visit(cArrayDeclNode* node)
    {
        VisitAllNodes(node);

        int numRanges = node->GetDecls()->NumDecls();

        int totalSize = node->GetDecl()->GetSize();
        node->AddRowSize(totalSize);
        
        for(int i = 0; i < numRanges; i++)
        {
            int startIndex = node->GetDecls()->GetRangeAt(i)->GetStart();
            int size = node->GetDecls()->GetRangeAt(i)->GetSize();

            node->AddStartIndex(startIndex);
            totalSize *= size;

            if(i != numRanges - 1)
                node->AddRowSize(totalSize);
        }

        node->SetSize(totalSize);
        


        /*
        cDeclNode* varDecl = node->GetDecl();

        node->SetSize(varDecl->GetSize());
        node->SetOffset(varDecl->GetOffset());

        cDeclNode* type = varDecl->GetType();

        if(type->IsArray())
        {
            cArrayDeclNode* array = dynamic_cast<cArrayDeclNode*>(type);
            node->SetSize(array->GetDecl()->GetSize());

            int index = 0;
            while (index < array->GetSizeOfStartIndex())
            {
                index += array->GetSizeOfStartIndex();
                for(int i=0; i < array->GetSizeOfStartIndex(); i++)
                {
                    node->AddRowSize(array->GetRowSizeAt(i));
                    node->AddStartIndex(array->GetStartIndexAt(i));
                }
                type = array->GetDecl();
                if (type->IsArray()) array = dynamic_cast<cArrayDeclNode*>(type);
            }
        }
        node->VistAllChildren(this);
        */
    }

    virtual void Visit(cRangeDeclNode* node)
    {
        node->SetSize(node->GetEnd() - node->GetStart() + 1);
    }

    virtual void Visit(cFuncDeclNode* node)
    {
        /*
        int prev = m_offset;
        int size = node->GetDecl()->GetSize();

        node->SetSize(size);
        node->GetParameters()->Visit(this);

        m_offset = size;
        node->GetBlock()->Visit(this);
        m_offset = prev;
    */

        int old_offset = m_offset;

        node->SetSize(node->GetDecl()->GetSize());
        node->SetOffset(0);

        cDeclsNode* params = node->GetParameters();
        if(params != nullptr)
        {
            params->Visit(this);
        }

        cBlockNode* block = node->GetBlock();
        if(block != nullptr)
        {
            m_offset = node->GetSize();
            block->Visit(this);
        }

        m_offset = old_offset;
    }

    virtual void Visit(cFuncExprNode* node)
    {
        cFuncDeclNode* func = dynamic_cast<cFuncDeclNode*>(node->GetDecl());
        if(func->GetParameters() != nullptr)
        {
            node->SetParamSize(func->GetParameters()->GetSize());
        }
        node->VisitAllChildren(this);
    }

    virtual void Visit(cProcDeclNode* node)
    {
        int old_offset = m_offset;

        cVarDeclsNode* params = node->GetParameters();
        if(params != nullptr)
        {
            m_offset = -12;
            m_isParams = true;
            params->Visit(this);
            m_isParams = false;
        }  

        cBlockNode* block = node->GetBlock();
        if (block != nullptr)
        {
            m_offset = 0;
            block->Visit(this);
        }

        m_offset = old_offset;
    }

    virtual void Visit(cProcCallNode* node)
    {
        cProcDeclNode* proc = dynamic_cast<cProcDeclNode*>(node->GetDecl());
        if(proc->GetParameters() != nullptr)
        {
            node->SetParamSize(proc->GetParameters()->GetSize());
        }
        node->VisitAllChildren(this);
    }

    int RoundUp(int value)
    {
        if(value % 4 == 0) return value;
        if(value < 0)
            return value - 4 - (value % 4);
        else
            return value + 4 - (value % 4);
    }

private:
    int m_offset;
    bool m_isParams;
};
