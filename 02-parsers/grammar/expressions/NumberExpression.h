#pragma once
#include "Expression.h"

class NumberExpression: public Expression {
public:
  NumberExpression(int value);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  int value_;
};

