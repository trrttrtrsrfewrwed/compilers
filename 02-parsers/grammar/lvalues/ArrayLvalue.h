#pragma once

#include "Lvalue.h"
#include <grammar/expressions/Expression.h>
#include <string>
class ArrayLvalue: public Lvalue {
public:
  ArrayLvalue(std::string id, Expression* idx);
  void Accept(Visitor* visitor);

  Expression* idx_;
};
