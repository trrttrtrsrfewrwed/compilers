#pragma once
#include "Expression.h"

class ArrayLengthExpression: public Expression {
public:
  ArrayLengthExpression(Expression* expr);
  ExprInfo eval() const override;

private:
  Expression* expr_;
};

