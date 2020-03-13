#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: Procedure Declarations ast node
//*******************************************

#include "cDeclNode.h"
#include "cSymbolTable.h"

extern cSymbolTable g_symbolTable;

class cProcDeclNode : public cDeclNode
{
public:
    cProcDeclNode(cSymbol* header) : cDeclNode()
    {
        string name = header->GetName();

        if(g_symbolTable.GlobalFind(name))
        {
            cSymbol* proto = g_symbolTable.LocalFind(name);
            if(proto)
            {
                if(!proto->GetDecl()->IsFunc()){
                    SemanticParseError("Symbol " + name 
                        + " already exists in current scope");
                    header = new cSymbol(name);
                    AddChild(g_symbolTable.Insert(header));
                }
                else
                {        
                    header->SetDecl(proto->GetDecl());
                    AddChild(header);
                }
            }
            else
            {
                header = new cSymbol(header->GetName());
                header->SetDecl(this);
                AddChild(g_symbolTable.Insert(header));
            }
        }
        else
        {
            header->SetDecl(this);
            AddChild(g_symbolTable.Insert(header));
        }
    }

    void AddParameters(cVarDeclsNode* params)
    {
        cSymbol* sym = dynamic_cast<cSymbol*>(GetChild(0));
        string name = sym->GetName();
        cProcDeclNode* proc = dynamic_cast<cProcDeclNode*>(sym->GetDecl());
    
        if(proc)
        {
            if(proc->GetParameters() != nullptr &&
                    proc->GetParameters()->GetNumChildren() != params->GetNumChildren())
                SemanticParseError(name
                        + " redeclared with different number of parameters");            
        }

        AddChild(params);
    }

    virtual void AddBlock(cBlockNode* block)
    {
        cSymbol* sym = dynamic_cast<cSymbol*>(GetChild(0));
        string name = sym->GetName();
        cProcDeclNode* proc = dynamic_cast<cProcDeclNode*>(sym->GetDecl());
    
        if(proc)
        {
            if(proc->GetBlock() != nullptr)
                SemanticParseError(name
                        + " already has a definition");            
            else if(block != nullptr)
            {
                sym->SetDecl(this);
            }
            
            AddChild(block);
        }
    }

    virtual string AttributesToString()
    {
        if(m_size != 0)
            return" size=\"" + std::to_string(m_size) 
                + "\" offset=\"" + std::to_string(m_offset) + "\"";
        else
            return string("");
    }

    virtual string GetName() { return dynamic_cast<cSymbol*>(GetChild(0))->GetName(); }
    virtual int GetNumParams() { return dynamic_cast<cVarDeclsNode*>(GetChild(1))
                                    ->GetNumChildren(); }
    virtual cVarDeclsNode* GetParameters() { return dynamic_cast<cVarDeclsNode*>(GetChild(1));}
    virtual cBlockNode* GetBlock() { return dynamic_cast<cBlockNode*>(GetChild(2)); }
    virtual bool IsFunc() { return true; }
    virtual string NodeType() { return string("proc"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
