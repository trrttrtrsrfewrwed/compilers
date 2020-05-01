#pragma once
#include "Expression.h"

class ParenthesesExpression: public Expression {
public:
  ParenthesesExpression(Expression* expr);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  Expression* expr_;
};

