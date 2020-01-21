// Justin Boehnen
#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include "cSymbol.h"

using std::vector;
using std::unordered_map;
using std::string;

class cSymbolTable {
public:
    cSymbolTable(){
        _scope = 0;

        _stack.push_back(new unordered_map<string, cSymbol*>());
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
    cSymbol* GlobalFind(string key){
        cSymbol* temp = nullptr;
        int index = _scope;

        while(temp != nullptr && index >= 0)
            temp = (*_stack[index--])[key];

        return temp;
    }

    // Name: LocalFind
    // Purpose: Finds a symbol in the current scope
    cSymbol* LocalFind(string key){
        return (*_stack[_scope])[key];
    }

    // Name: Insert
    // Purpose: Inserts a symbol into the current scope
    cSymbol* Insert(string key){
        (*_stack[_scope])[key] = new cSymbol(key);
        return (*_stack[_scope])[key];
    }

private:
    int _scope;
    vector<unordered_map<string, cSymbol*>*> _stack;
};
