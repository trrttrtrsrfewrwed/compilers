#pragma once
#include "SimpleType.h"
#include <base_elements/BaseElement.h>
class ArrayType: public BaseElement {
public:
  ArrayType(SimpleType* element_type);

  std::string GetType();

  void Accept(Visitor* visitor);
  SimpleType* element_type_;
};
