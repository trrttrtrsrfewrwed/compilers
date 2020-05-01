#pragma once
#include <grammar/base_elements/BaseElement.h>
#include <string>

class TypeIdentifier: public BaseElement {
public:
  TypeIdentifier(std::string type_name);
  std::string GetTypeName();
  void Accept(Visitor* visitor);
  std::string type_name_;
};
