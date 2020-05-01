#pragma once
#include "DeclarationList.h"
#include <grammar/base_elements/BaseElement.h>
#include <string>

class ClassDeclaration: public BaseElement {
public:
  ClassDeclaration(std::string class_name, DeclarationList* fields);
  ClassDeclaration(std::string class_name, std::string parent_name, DeclarationList* fields);
  void Accept(Visitor* visitor);

  std::string class_name_;
  DeclarationList* fields_;
  std::string parent_name_ = "";
};
