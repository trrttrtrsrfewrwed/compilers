#pragma once

#include "MethodDeclaration.h"
#include "VariableDeclaration.h"
class Declaration {
public:
  Declaration(VariableDeclaration* var_decl);
  Declaration(MethodDeclaration* method_decl);

private:
  CommonDeclaration* decl_;
};
