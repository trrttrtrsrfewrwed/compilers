#pragma once
#include "Expression.h"

class NotExpression: public Expression {
public:
  NotExpression(Expression* expr);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  Expression* expr_;
};

