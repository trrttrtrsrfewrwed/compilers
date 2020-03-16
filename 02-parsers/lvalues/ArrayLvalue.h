#pragma once

#include "Lvalue.h"
#include <expressions/Expression.h>
#include <string>
class ArrayLvalue: public Lvalue {
public:
  ArrayLvalue(std::string id, Expression* idx);

private:
  std::string id_;
  Expression* idx_;
};
