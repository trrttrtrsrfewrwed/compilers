#pragma once

#include "VariableDeclaration.h"
class LocalVariableDeclaration: public BaseElement {
public:
  LocalVariableDeclaration(VariableDeclaration* variable_declaration);
  void Accept(Visitor* visitor);

  VariableDeclaration* variable_declaration_;
};
