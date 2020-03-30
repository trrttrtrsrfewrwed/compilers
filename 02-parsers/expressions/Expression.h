#pragma once
#include "expr_info/ExprInfo.h"
#include <base_elements/BaseElement.h>

class Expression: public BaseElement {
public:
  virtual ExprInfo eval() const = 0;
};