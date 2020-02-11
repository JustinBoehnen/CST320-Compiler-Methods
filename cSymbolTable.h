#pragma once
//*******************************************
// Author: Justin Boehnen
// Purpose: Symbol Table for CST320 compiler
//*******************************************

#include <vector>
#include <unordered_map>
#include <string>
#include "cSymbol.h"
#include "pascalparse.h"

using std::vector;
using std::unordered_map;
using std::string;

class cSymbolTable {
public:
    cSymbolTable(){
        _scope = 0;

        _stack.push_back(new unordered_map<string, cSymbol*>());

        InitializeKeywords();
    }

    ~cSymbolTable(){
        for (auto scope : _stack){
            delete scope;
            scope = nullptr;
        }
    }

    // Name: IncreaseScope
    // Purpose: Pushes a new hash table onto the stack and increments scope
    void IncreaseScope(){
        _stack.push_back(new unordered_map<string, cSymbol*>());
        _scope++;
    }
    
    // Name: DecreaseScope
    // Purpose: Pops the current hash table off the stack and decrements scope
    void DecreaseScope(){
        delete _stack[_scope--];
        _stack.pop_back();
    }

    // Name: GlobalFind
    // Purpose: Finds a symbol in any scope
    cSymbol* GlobalFind(string key)
    {
        cSymbol* temp = nullptr;
        int index = _scope;

        while(temp == nullptr && index >= 0)
        {
            auto it = (_stack[index])->find(key);
            temp = it != (_stack[index--])->end() ? it->second : nullptr;
        }
        
        return temp;
    }

    // Name: LocalFind
    // Purpose: Finds a symbol in the current scope
    cSymbol* LocalFind(string key)
    {
        auto it = (_stack[_scope])->find(key);
        return it != (_stack[_scope])->end() ? it->second : nullptr;
    }

    // Name: Insert
    // Purpose: Inserts a symbol into the current scope
    cSymbol* Insert(string key){
        (*_stack[_scope])[key] = new cSymbol(key);
        return (*_stack[_scope])[key];
    }

    cSymbol* Insert(cSymbol* sym)
    {
        (*_stack[_scope])[sym->GetName()] = sym;
        return sym;
    }

private:
    int _scope;
    vector<unordered_map<string, cSymbol*>*> _stack;

    void InitializeKeywords()
    {
        cSymbol* keyword;
       
        keyword = new cSymbol("program", PROGRAM);
        Insert(keyword);
        keyword = new cSymbol("procedure", PROCEDURE);
        Insert(keyword);
        keyword = new cSymbol("function", FUNCTION);
        Insert(keyword);
        keyword = new cSymbol("forward", FORWARD);
        Insert(keyword);
        keyword = new cSymbol("begin", OPEN);
        Insert(keyword);
        keyword = new cSymbol("end", CLOSE);
        Insert(keyword);
        keyword = new cSymbol("while", WHILE);
        Insert(keyword);
        keyword = new cSymbol("write", WRITE);
        Insert(keyword);
        keyword = new cSymbol("if", IF);
        Insert(keyword);
        keyword = new cSymbol("then", THEN);
        Insert(keyword);
        keyword = new cSymbol("else", ELSE);
        Insert(keyword);
        keyword = new cSymbol("repeat", REPEAT);
        Insert(keyword);
        keyword = new cSymbol("until", UNTIL);
        Insert(keyword);
        keyword = new cSymbol("for", FOR);
        Insert(keyword);
        keyword = new cSymbol("do", DO);
        Insert(keyword);
        keyword = new cSymbol("to", TO);
        Insert(keyword);
        keyword = new cSymbol("downto", DOWNTO);
        Insert(keyword);
        keyword = new cSymbol("const", CONST);
        Insert(keyword);
        keyword = new cSymbol("type", TYPE);
        Insert(keyword);
        keyword = new cSymbol("var", VAR);
        Insert(keyword);
        keyword = new cSymbol("record", RECORD);
        Insert(keyword);
        keyword = new cSymbol("array", ARRAY);
        Insert(keyword);
        keyword = new cSymbol("of", OF);
        Insert(keyword);
        keyword = new cSymbol("nil", NIL);
        Insert(keyword);
        keyword = new cSymbol("or", OR);
        Insert(keyword);
        keyword = new cSymbol("div", DIV);
        Insert(keyword);
        keyword = new cSymbol("mod", MOD);
        Insert(keyword);
        keyword = new cSymbol("and", AND);
        Insert(keyword);
        keyword = new cSymbol("not", NOT);
        Insert(keyword);
        keyword = new cSymbol("integer", INTEGER);
        Insert(keyword);
        keyword = new cSymbol("real", REAL);
        Insert(keyword);
        keyword = new cSymbol("char", CHAR);
        Insert(keyword);
    }
};
