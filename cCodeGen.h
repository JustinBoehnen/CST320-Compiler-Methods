#pragma once

#include "cVisitor.h"
#include "astnodes.h"
#include "emit.h"
#include "pascalparse.h"

class cCodeGen : public cVisitor
{
public:
    cCodeGen(string file) : cVisitor()
    {
        InitOutput(file);   
    }

    ~cCodeGen()
    {
        FinalizeOutput();
    }

    virtual void VisitAllNodes(cAstNode* node)
    {
        node->Visit(this);
    }

    virtual void Visit(cProgramNode* node)
    {
        cBlockNode* block = node->GetBlock();
        cDeclsNode* decl = block->GetDecls();
        cStmtsNode* stmts = block->GetStmts();

        if(decl)
            decl->Visit(this);

        EmitString(".function main\n");
        EmitString("main:\n");
        EmitString("ADJSP ");
        EmitInt(block->GetSize());
        EmitString("\n");

        if(stmts != nullptr)
            stmts->Visit(this);
 
        EmitString("PUSH 0\nRETURNV");
    }

    virtual void Visit(cWriteNode* node)
    {
        cExprListNode* list = node->GetList();

        for(int i = 0; i < list->GetNumChildren(); i++)
        {
            list->GetParamAt(i)->Visit(this);
            
            EmitString("CALL @print\n");
            EmitString("POP\n");
            EmitString("POP\n");
        }
    }

    virtual void Visit(cIntExprNode* node)
    {
        EmitString("PUSH ");
        EmitInt(node->GetValue());
        EmitString("\n");
    }

    virtual void Visit(cVarExprNode* node)
    {
        cExprListNode* list = node->GetList();
        
        if(list == nullptr)
        {
            if(node->GetSize() == 1)
                EmitString("PUSHCVAR ");
            else
                EmitString("PUSHVAR ");

            EmitInt(node->GetOffset());
            EmitString("\n");    
        }
    }

    virtual void Visit(cAssignNode* node)
    {
        node->GetRight()->Visit(this);
        cExprListNode* list = node->GetLeft()->GetList();
        int size = node->GetLeft()->GetSize();

        if(list == nullptr)
        {
            if(size != 1)
                EmitString("POPVAR ");
            else
                EmitString("POPCVAR ");

            EmitInt(node->GetLeft()->GetOffset());
            EmitString("\n");
        }
    }

    virtual void Visit(cBinaryExprNode* node)
    {
        node->GetLeft()->Visit(this);
        node->GetRight()->Visit(this);
        int op = node->GetOp();

        switch(op)
        {
            case OR:
                EmitString("OR\n");
                break;
            case AND:
                EmitString("AND\n");
                break;
            case '%':
                EmitString("MOD\n");
                break;
            case '/':
                EmitString("DIVIDE\n");
                break;
            case '*':
                EmitString("TIMES\n");
                break;
            case '+':
                EmitString("PLUS\n");
                break;
            case '-':
                EmitString("MINUS\n");
                break;
            case LE:
                EmitString("LE\n");
                break;
            case GE:
                EmitString("GE\n");
                break;
            case NOT_EQUAL:
                EmitString("NE\n");
                break;
            case '<':
                EmitString("LT\n");
                break;
            case '>':
                EmitString("GT\n");
                break;
        }
    }

    virtual void Visit(cUnaryExprNode* node)
    {
        node->GetExpr()->Visit(this);

        int op = node->GetOp();

        switch(op)
        {
            case '-':
                EmitString("NEG\n");
                break;
            case NOT:
                EmitString("NOT\n");
                break;
        }
    }

    virtual void Visit(cFuncDeclNode* node)
    {
        string name = node->GetName();
        cBlockNode* block = node->GetBlock();
        cDeclsNode* decls = block->GetDecls();

        if(block != nullptr)
        {
            EmitString(".function " + name + "\n");
            EmitString(name + ":\n");
            EmitString("ADJSP");
            EmitInt(block->GetSize());
            EmitString("\n");

            if(decls != nullptr)
                decls->Visit(this);

            block->GetStmts()->Visit(this);

            if(node->GetSize() == 1)
                EmitString("PUSHCVAR 0\n");
            else
                EmitString("PUSHVAR 0\n");

            EmitString("RETURNV\n");
        }
    }

    virtual void Visit(cFuncExprNode* node)
    {
        cExprListNode* params = node->GetParams();

        for(int i = 0; i < params->GetNumChildren(); i++)
            params->GetParamAt(i)->Visit(this);

        EmitString("CALL @" + node->GetName() + "\n");
        EmitString("POPARGS ");
        EmitInt(node->GetParamSize());
        EmitString("\n");
    }

    virtual void Visit(cIfNode* node)
    {
        string ifLabel = GenerateLabel();
        string elseLabel = GenerateLabel();
        cStmtNode* elseNode = node->GetElse();
        node->GetExpr()->Visit(this);

        EmitString("JUMPE @" + ifLabel + "\n");
        node->GetIf()->Visit(this);

        if(elseNode != nullptr)
        {
            EmitString("JUMP @" + elseLabel);
            EmitString("\n");
        }

        EmitString(ifLabel + ":\n");

        if(elseNode != nullptr)
        {
            elseNode->Visit(this);
            EmitString(elseLabel + ":\n");
        }
    }

    virtual void Visit(cWhileNode* node)
    {
        cExprNode* expr = node->GetExpr();
        cStmtNode* stmt = node->GetStmt();
        string start = GenerateLabel();
        string end = GenerateLabel();

        EmitString(start + ":\n");

        expr->Visit(this);
        EmitString("JUMPE @" + end + "\n");

        stmt->Visit(this);
        EmitString("JUMP @" + start + "\n");

        EmitString(end + ":\n");
    }
};
