#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: ast node represents and declares size of
//          base types: integer, real, and char
//*******************************************
#include "cDeclNode.h"

class cBaseTypeNode : public cDeclNode
{
public:
    cBaseTypeNode(string name, int size, bool isFloat)
        : cDeclNode(), m_name(name), m_size(size), m_isFloat(isFloat)
    { }

    virtual string AttributesToString()
    {
        string res(" name=\"");
        res += m_name;
        res += "\" size=\"";
        res += std::to_string(m_size);
        res += "\" isFloat=\"";
        res += std::to_string(m_isFloat);
        res += "\"";

        return res;
    }
    virtual string GetName() { return m_name; }
    virtual string NodeType() { return string("type"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
    virtual bool IsInt() { return m_name == "integer"; }
    virtual bool IsReal() { return m_name == "real"; }
    virtual bool IsChar() { return m_name == "char"; }
private:
    string m_name;
    int m_size;
    bool m_isFloat;
};
