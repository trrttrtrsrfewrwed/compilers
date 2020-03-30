#pragma once

#include "Lvalue.h"
#include <expressions/Expression.h>
#include <string>
class ArrayLvalue: public Lvalue {
public:
  ArrayLvalue(std::string id, Expression* idx);
  void Accept(Visitor* visitor);

  std::string id_;
  Expression* idx_;
};
