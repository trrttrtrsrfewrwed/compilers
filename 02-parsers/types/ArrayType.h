#pragma once
#include "SimpleType.h"
class ArrayType {
public:
  ArrayType(SimpleType* element_type);

  std::string GetType();
private:
  SimpleType* element_type_;
};
