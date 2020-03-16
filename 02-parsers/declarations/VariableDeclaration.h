#pragma once
#include "CommonDeclaration.h"
#include "types/Type.h"
#include <string>

class VariableDeclaration : public CommonDeclaration {
public:
  VariableDeclaration(Type *type, std::string variable_name);

private:
  Type *type_;
  std::string variable_name_;
};
