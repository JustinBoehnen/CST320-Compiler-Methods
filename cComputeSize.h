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

        RoundUp();
        node->SetSize(m_offset);
    } 

    virtual void Visit(cVarDeclNode* node)
    {
        node->SetSize(node->GetDecl()->GetSize());

        if(node->GetSize() > 1)
            RoundUp();

        node->SetOffset(m_offset);
        m_offset += node->GetSize();
    }

    virtual void Visit(cVarExprNode* node)
    {
        node->VisitAllChildren(this);

        node->SetOffset(node->GetDecl()->GetOffset());
        if(node->GetDecl()->GetDecl()->IsArray() && node->HasIndexes())
            node->SetSize(node->GetDecl()->GetDecl()->GetDecl()->GetSize());
        else
            node->SetSize(node->GetDecl()->GetSize());
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
    }

    virtual void Visit(cRangeDeclNode* node)
    {
        node->SetSize(node->GetEnd() - node->GetStart() + 1);
    }

    void RoundUp()
    {
        if((m_offset % 4) != 0)
            m_offset += 4 - (m_offset % 4);
    }
private:
    int m_offset;
};
