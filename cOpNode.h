#pragma once
//**************************************
// cOpNode.h
//
// Class for an operator (e.g. + - etc.)
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "pascalparse.h"

class cOpNode : public cAstNode
{
    public:
        cOpNode(int op) : cAstNode()
        {
            m_op = op;
        }

        virtual string NodeType()       { return "op"; }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual string AttributesToString()   
        { 
            string result(" value=\"");

            switch (m_op)
            {
                case OR:
                    result += "OR";
                    break;
                case AND:
                    result += "AND";
                    break;
                case MOD:
                    result += "MOD";
                    break;
                case DIV:
                    result += "DIV";
                    break;
                case NOT:
                    result += "NOT";
                    break;
                case LE:
                    result += "LE";
                    break;
                case GE:
                    result += "GE";
                    break;
                case NOT_EQUAL:
                    result += "NE";
                    break;
                case '<':
                    result += "LE";
                    break;
                case '>':
                    result += "GE";
                    break;
                default:
                    result += (char)m_op;
                    break;
            }

            result += "\"";

            return result;
        }
    protected:
        int m_op;      // the operand
};

