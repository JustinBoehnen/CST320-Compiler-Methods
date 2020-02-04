//**************************************
// main.cpp
//
// Main function for pascal compiler
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2016
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "cSymbolTable.h"
#include "lex.h"
#include "astnodes.h"
#include "pascalparse.h"

// define global variables
cSymbolTable g_symbolTable;
long long cSymbol::nextId = 3;
extern cAstNode* yyast_root;

// takes two string args: input_file, and output_file
int main(int argc, char **argv)
{
    std::cout << "Justin Boehnen" << std::endl;

    const char *outfile_name;
    int result = 0;
    std::streambuf *cout_buf = std::cout.rdbuf();

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
    } else {
        outfile_name = "/dev/tty";
    }

    std::ofstream output(outfile_name);
    if (!output.is_open())
    {
        std::cerr << "ERROR: Unable to open file " << outfile_name << "\n";
        exit(-1);
    }

    // fixup cout so it redirects to output
    std::cout.rdbuf(output.rdbuf());

    result = yyparse();
    if (yyast_root != nullptr && result == 0 && yynerrs == 0)
    {
        output << yyast_root->ToString() << std::endl;
    } else {
            output << yynerrs << " Errors in compile\n";
    }

    if (result == 0 && yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    // close output and fixup cout
    // If these aren't done, you may get a segfault on program exit
    output.close();
    std::cout.rdbuf(cout_buf);

    return result;
}
