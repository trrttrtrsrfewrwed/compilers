#pragma once
#include "expr_info/ExprInfo.h"

class Expression {
public:
  virtual ExprInfo eval() const = 0;
};