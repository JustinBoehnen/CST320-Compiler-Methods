#pragma once

#include "cDeclsNode.h"
#include "cVarDeclNode.h"
#include "cIdListNode.h"
#include "cBaseTypeNode.h"

class cVarDeclsNode : public cDeclsNode
{
public:
    cVarDeclsNode(cIdListNode* ids, cBaseTypeNode* type) : cDeclsNode()
    {
        int index = 0;
        cSymbol* temp = ids->GetSymbol(index);

        while(temp != nullptr)
        {
            AddChild(new cVarDeclNode(type, temp));
            temp = ids->GetSymbol(++index);
        }
    }

    void AddVarDecls(cVarDeclsNode* decls)
    {
        AddAllChildren(decls);
    }

    virtual string NodeType() { return string("var-decls"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
};
