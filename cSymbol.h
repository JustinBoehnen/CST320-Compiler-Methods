#pragma once
//*********************************************************
// cSymbol.h
//
// cSymbol class declaration.
// cSymbols are objects that represent identifiers and other such strings in 
// the compiler.
//
// Author: Phil Howard
// phil.howard@oit.edu
//

#include <string>
#include <utility>
#include "cAstNode.h"
#include "pascalparse.h"
#include "cDeclsNode.h"
#include "cBaseTypeNode.h"
using std::string;

class cSymbol : public cAstNode
{
    public:
        cSymbol(string name, int id=-1, bool isType=false) 
            : cAstNode(), _isType(isType)
        {
            if(id == -1)
            {
                m_id = ++nextId;
                _tokenType = IDENTIFIER;
            }
            else 
            {
                m_id = id;
                _tokenType = m_id;
            }
            
            m_name = name;
            /*
            if(id == -1)
                m_id = ++nextId; 
            else
            {
                m_id = -1;

                switch(id){
                    case CHAR:    
                        _tokenType = TYPE_ID;
                        _decl = new cBaseTypeNode(name);
                        break;
                    case INTEGER:
                        _tokenType = TYPE_ID;
                        _decl = new cBaseTypeNode(name);
                        break;
                    case REAL:
                        _tokenType = TYPE_ID;
                        _decl = new cBaseTypeNode(name);
                        break;
                    default:
                        _tokenType = id;
                        break;
                } 
            }
            */
        }
        
        // Used to print cSymbols
        string ToString()
        {
            string result("<sym id=\"");
            result += std::to_string(m_id);
            result += "\" name=\"" + m_name + "\" />";

            return result;
        }

        virtual string NodeType() { return string("sym"); }
        virtual string AttributesToString(){
            string res(" id=\"");
            res += std::to_string(m_id);
            res += "\" name=\"" + m_name + "\"";
            return res;
        }
        virtual void Visit(cVisitor* visitor) { visitor->Visit(this); }

        // return the name of the cSymbol
        string GetName() { return m_name; }

        void SetDecl(cDeclNode* decl)
        {
            _decl = decl;
        }

        cDeclNode* GetDecl()
        {
            return _decl;
        }

        void SetIsType(bool isType)
        {
            _isType = isType;   
        }

        bool GetIsType()
        {
            return _isType;
        }

        int GetType() { return _tokenType; }
    protected:
        static long long nextId;    // used to generate unique IDs
        long long m_id;             // ID for this cSymbol
        string m_name;              // name for this cSymbol
        int _tokenType;
        cDeclNode* _decl;
        bool _isType;
};
