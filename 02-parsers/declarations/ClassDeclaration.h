#pragma once
#include <string>
#include "DeclarationList.h"

class ClassDeclaration {
public:
  ClassDeclaration(std::string class_name, DeclarationList* fields);
  ClassDeclaration(std::string class_name, std::string parent_name, DeclarationList* fields);

private:
  std::string class_name_;
  DeclarationList* fields_;
  std::string parent_name_ = "";
};
