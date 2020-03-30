#pragma once
#include "Expression.h"

class ArrayLengthExpression: public Expression {
public:
  ArrayLengthExpression(Expression* expr);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  Expression* expr_;
};

