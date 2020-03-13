#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: Array Declarations
//*******************************************
#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cArrayDeclNode: public cDeclNode
{
public:
    cArrayDeclNode(cSymbol* name, cDeclNode* type, cDeclsNode* decls)
        :cDeclNode()
    {
        if(g_symbolTable.GlobalFind(name->GetName()))
            name = new cSymbol(name->GetName());
    
        name->SetDecl(this);
        AddChild(g_symbolTable.Insert(name));
        AddChild(type);
        AddChild(decls);
    }
    
    virtual string AttributesToString()
    {
        string row = " rowsizes=\"";
        string ind = " startindexes=\"";

        for(int i = 0; i < static_cast<int>(m_rowSizes.size()) - 1; i++)
        {
            row += std::to_string(m_rowSizes[i]) + " ";
        }
        row += std::to_string(m_rowSizes[static_cast<int>(m_rowSizes.size())-1]) + "\"";
        
        for(int i = 0; i < static_cast<int>(m_startIndexes.size()) - 1; i++)
        {
            ind += std::to_string(m_startIndexes[i]) + " ";
        }
        ind += std::to_string(m_startIndexes[static_cast<int>(m_startIndexes.size())-1]) + "\"";
        
        return " size=\"" + std::to_string(m_size) + "\"" + row + ind;
    }
    virtual cDeclNode* GetDecl() { return dynamic_cast<cDeclNode*>(GetChild(1)); }
    virtual cDeclsNode* GetDecls() { return dynamic_cast<cDeclsNode*>(GetChild(2)); }
    virtual string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); } 
    virtual bool IsArray() { return true; }
    virtual string NodeType() { return string("array"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }

    int GetSizeOfRowSize() { return static_cast<int>(m_rowSizes.size()); }
    int GetSizeOfStartIndex() { return static_cast<int>(m_startIndexes.size()); }
    int GetRowSizeAt(int index) { return m_rowSizes[index]; }
    int GetStartIndexAt(int index) { return m_startIndexes[index]; }
    void AddRowSize(int size) { m_rowSizes.push_back(size); }
    void AddStartIndex(int index) { m_startIndexes.push_back(index); }

private:
    vector<int> m_rowSizes;
    vector<int> m_startIndexes;
};
