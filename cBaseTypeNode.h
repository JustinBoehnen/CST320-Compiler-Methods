#pragma once
#include "cDeclNode.h"

class cBaseTypeNode : public cDeclNode
{
public:
    cBaseTypeNode(string name)
        : cDeclNode(), m_name(name), m_isFloat(false)
    {
        if (name == "integer")
            m_size = sizeof(int);
        else if (name == "real")
        {
            m_size = sizeof(double);
            m_isFloat = true;
        }
        else if (name == "char")
            m_size = sizeof(char);
    }

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
    virtual string NodeType() { return string("type"); }
    virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }
private:
    string m_name;
    int m_size;
    bool m_isFloat;
};
