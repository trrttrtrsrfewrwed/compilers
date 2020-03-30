#pragma once
#include "Statement.h"
#include <declarations/LocalVariableDeclaration.h>

class LocalVariableDeclarationStatement: public Statement {
public:
  LocalVariableDeclarationStatement(LocalVariableDeclaration* lv_decl);
  void Accept(Visitor* visitor);
  LocalVariableDeclaration* lv_decl_;
};
