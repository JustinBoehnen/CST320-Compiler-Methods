#pragma once

/*************************************************
 * Author:      Justin Boehnen
 * Modified:    2/25/20
 * Purpose:     Semantic Error Reporting
 ************************************************/

#include "cVisitor.h"
#include "cAstNode.h"

class cSemantics : public cVisitor
{
public:
    cSemantics() : cVisitor()
    {
    
    }

    virtual void VisitAllNodes(cAstNode *node)
    {
        node->VisitAllChildren(this);
    }

    virtual void Visit(cFuncExprNode* node)
    {
        node->VisitAllChildren(this);
        cDeclNode* decl = node->GetDecl();
        
        if(decl == nullptr)
            node->SemanticError(node->GetName() + " is not declared");
        else
        {
            if(!decl->IsFunc())
                node->SemanticError(node->GetName() + " is not a function");
            else
            {
                cFuncDeclNode* func = dynamic_cast<cFuncDeclNode*>(decl);

                if(func->GetBlock() == nullptr)
                    node->SemanticError(node->GetName() + " is not fully defined");
                else if(func->GetNumParams() != node->GetNumParams())
                    node->SemanticError(node->GetName() 
                            + " called with wrong number of arguments");
                else
                {
                    //Param type check loop
                    int index = 0;
                    int numParams = func->GetNumParams(); 
                
                    while(index < numParams)
                    {
                        cDeclNode* expected = func->GetParameters()
                            ->GetParamAt(index)->GetDecl();
                        cDeclNode* actual = node->GetParams()
                            ->GetParamAt(index)->GetDecl();

                        if(expected->IsFunc() || expected->IsVar())
                            expected = expected->GetDecl();
                        if(actual->IsFunc() || actual->IsVar())
                            actual = actual->GetDecl();
                        
                        if(expected->IsInt() && actual->IsReal())
                            node->SemanticError("Cannot assign real to integer");
                        else if(expected->IsChar() && actual->IsReal())
                            node->SemanticError("Cannot assign real to char");
                        else if(expected->IsChar() && actual->IsInt())
                            node->SemanticError("Cannot assign integer to char");
                        else if(expected->IsArray() || actual->IsArray())
                        {
                            if(expected->IsFunc() || expected->IsVar())
                                expected = expected->GetDecl();
                            if(actual->IsFunc() || actual->IsVar())
                                actual = actual->GetDecl();
                    
                            if(expected != actual)
                                node->SemanticError("Cannot assign " + actual->GetName()
                                + " to " + expected->GetName());
                        }
                        index++;
                    }
                }
            }
        }
    }

    virtual void Visit(cVarExprNode* node)
    {
        node->VisitAllChildren(this);
        string name = node->GetName();
        cDeclNode* decl = node->GetDecl();
        cExprListNode* list = node->GetList();
    
        if(decl == nullptr)
            node->SemanticError("Variable " + name + " is not defined");
        else
        {
            if(decl->IsVar())
                decl = decl->GetDecl();

            if(list && !decl->IsArray())
                node->SemanticError(name + " is not an array");

            if(decl->IsArray())
            {
                cArrayDeclNode* array = dynamic_cast<cArrayDeclNode*>(decl);

                if(list != nullptr)
                {
                    if(list->GetNumChildren() != array->GetDecls()->GetNumChildren())
                        node->SemanticError(name 
                                + " does not have the correct number of indexes");
                    
                    for(int i = 1; i < list->GetNumChildren(); i++)
                    {
                        cDeclNode* decl = list->GetDeclAt(i);
                        
                        if(decl->IsFunc() || decl->IsVar())
                            decl = decl->GetDecl();

                        if(!decl->IsInt())
                            node->SemanticError("Index of " + name + " is not an integer");
                    }
                }
            }
        }
    }

    virtual void Visit(cAssignNode* node)
    {
        node->VisitAllChildren(this);
        cDeclNode* left = node->GetLeft()->GetDecl();
        cDeclNode* right = node->GetRight()->GetDecl();
        
        if(left->IsFunc() || left->IsVar())
            left = left->GetDecl();
        
        if(right != nullptr)
        {
            if(right->IsFunc() || right->IsVar())
                right = right->GetDecl();
            
            if(left != nullptr && right != nullptr)
            {
                if(left->IsInt() && right->IsReal())
                    node->SemanticError("Cannot assign real to integer");
                else if(left->IsChar() && right->IsReal())
                    node->SemanticError("Cannot assign real to char");
                else if(left->IsChar() && right->IsInt())
                    node->SemanticError("Cannot assign integer to char");
                else if(left->IsArray() && !node->GetLeft()->GetList())
                {
                    if(left != right)
                        node->SemanticError("Cannot assign " + right->GetName()
                            + " to " + left->GetName());
                }
                else if(right->IsArray())
                {
                    cVarExprNode* expr = dynamic_cast<cVarExprNode*>(node->GetRight());

                    if(expr->GetList() == nullptr)
                        node->SemanticError("Cannot assign " + right->GetName() 
                            + " to " + left->GetName());
                }
            }
        }
    }
};
