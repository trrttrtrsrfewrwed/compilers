#pragma once

#include "ArrayType.h"
#include "SimpleType.h"
#include <grammar/base_elements/BaseElement.h>
class Type: public BaseElement {
public:
  Type(SimpleType* type);
  Type(ArrayType* type);
  void Accept(Visitor* visitor);

  std::string type_;
  bool is_array_;
};
