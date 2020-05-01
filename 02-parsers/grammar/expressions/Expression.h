#pragma once
#include "grammar/expressions/expr_info/ExprInfo.h"
#include <grammar/base_elements/BaseElement.h>

class Expression: public BaseElement {
public:
  virtual ExprInfo eval() const = 0;
};