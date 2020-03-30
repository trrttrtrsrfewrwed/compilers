#pragma once
#include "Expression.h"
#include "binary_operator/BinaryOperator.h"

class BinaryExpression: public Expression {
public:
  BinaryExpression(Expression* e1, Expression* e2, BinaryOperator* op);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  Expression* first;
  Expression* second;
  BinaryOperator* op_;
};

