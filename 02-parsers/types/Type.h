#pragma once

#include "ArrayType.h"
#include "SimpleType.h"
class Type {
public:
  Type(SimpleType* type);
  Type(ArrayType* type);

private:
  std::string type_;
  bool is_array_;
};
