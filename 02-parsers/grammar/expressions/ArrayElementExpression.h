#pragma once
#include "Expression.h"

class ArrayElementExpression: public Expression {
public:
  ArrayElementExpression(Expression* type, Expression* idx);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  Expression* type_;
  Expression* idx_;
};

