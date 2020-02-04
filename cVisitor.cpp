//******************************************************
// Implementation of visitor base class
//
// Author: Philip Howard
// Email: phil.howard@oit.edu
//
//

#include "lex.h"
#include "cVisitor.h"
#include "astnodes.h"

void cVisitor::Visit(cAstNode *node)          { node->VisitAllChildren(this); }
void cVisitor::Visit(cBlockNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cDeclNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cDeclsNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cExprNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cIntExprNode *node)      { node->VisitAllChildren(this); }
void cVisitor::Visit(cOpNode *node)           { node->VisitAllChildren(this); }
void cVisitor::Visit(cWriteNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cProgramNode *node)      { node->VisitAllChildren(this); }
void cVisitor::Visit(cStmtNode *node)         { node->VisitAllChildren(this); }
void cVisitor::Visit(cStmtsNode *node)        { node->VisitAllChildren(this); }
void cVisitor::Visit(cSymbol *node)           { node->VisitAllChildren(this); }

