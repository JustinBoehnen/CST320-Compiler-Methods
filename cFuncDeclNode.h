#pragma once

#include "cDeclNode.h"
#include "cSymbolTable.h"
#include "cProcDeclNode.h"

extern cSymbolTable g_symbolTable;

class cFuncDeclNode : public cProcDeclNode
{
public:
    cFuncDeclNode(cSymbol* header) : cProcDeclNode(header)
    {}

    void AddTypeParameters(cDeclNode* type, cVarDeclsNode* params)
    {
        cSymbol* sym = dynamic_cast<cSymbol*>(GetChild(0));
        string name = sym->GetName();
        cFuncDeclNode* func = dynamic_cast<cFuncDeclNode*>(sym->GetDecl());

        if(func)
        {
            if(func->GetDecl() != nullptr && func->GetDecl() != type)
                SemanticParseError(name 
                        + " previsously declared with different return type");
            else
                AddChild(type);

            if(func->GetParameters() != nullptr &&
                    func->GetParameters()->GetNumChildren() != params->GetNumChildren())
                SemanticParseError(name + " redeclared with different number of parameters");
            else
                AddChild(params);
        }
    }
    
    
    virtual cDeclNode* GetDecl() { return dynamic_cast<cDeclNode*>(GetChild(1)); }
    virtual int GetNumParams() 
    { 
        if(GetChild(2) != nullptr)
            return dynamic_cast<cVarDeclsNode*>(GetChild(2))->GetNumChildren(); 
        else
            return 0;
    }
    virtual cVarDeclsNode* GetParameters() { return dynamic_cast<cVarDeclsNode*>(GetChild(2)); }
    virtual cBlockNode* GetBlock() { return dynamic_cast<cBlockNode*>(GetChild(3)); }
    virtual bool IsFunc() { return true; }
    virtual string NodeType() { return string("func"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
