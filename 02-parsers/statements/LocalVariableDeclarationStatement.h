#pragma once
#include "Statement.h"
#include <declarations/LocalVariableDeclaration.h>

class LocalVariableDeclarationStatement: public Statement {
public:
  LocalVariableDeclarationStatement(LocalVariableDeclaration* lv_decl);

private:
  LocalVariableDeclaration* lv_decl_;
};
