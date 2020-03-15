#pragma once
#include "Expression.h"

class ArrayElementExpression: public Expression {
public:
  ArrayElementExpression(Expression* type, Expression* idx);
  ExprInfo eval() const override;
private:
  Expression* type_;
  Expression* idx_;
};

