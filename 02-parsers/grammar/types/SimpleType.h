#pragma once
#include "TypeIdentifier.h"
#include <grammar/base_elements/BaseElement.h>
#include <string>

class SimpleType: public BaseElement {
public:
  SimpleType(std::string type);
  SimpleType(TypeIdentifier* type_id);

  std::string GetType();

  void Accept(Visitor* visitor);
  std::string type_;
};
