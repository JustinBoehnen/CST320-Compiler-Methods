#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: number range ast node
//*******************************************

#include "cAstNode.h"
#include "cExprNode.h"

class cRangeDeclNode : public cDeclNode
{
public:
    cRangeDeclNode(int left, int right) : cDeclNode()
    {
        _left = left;
        _right = right;
    }

    virtual string AttributesToString()
    {
        string str =" start=\"";
        str += std::to_string(_left);
        str += "\" end = \"";
        str += std::to_string(_right);
        str += "\"";
        return str;
    }
    virtual string NodeType() { return string("range"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    int GetStart() { return _left; }
    int GetEnd() { return _right; }

protected:
    int _left;
    int _right;
};
