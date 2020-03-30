#pragma once

#include "MethodDeclaration.h"
#include "VariableDeclaration.h"
class Declaration: public BaseElement {
public:
  Declaration(VariableDeclaration* var_decl);
  Declaration(MethodDeclaration* method_decl);
  void Accept(Visitor* visitor);


  CommonDeclaration* decl_;
};
