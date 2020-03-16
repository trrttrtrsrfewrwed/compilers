#pragma once

#include "VariableDeclaration.h"
class LocalVariableDeclaration {
public:
  LocalVariableDeclaration(VariableDeclaration* variable_declaration);

private:
  VariableDeclaration* variable_declaration_;
};
