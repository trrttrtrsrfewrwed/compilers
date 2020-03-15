#pragma once
#include "Expression.h"

class ParenthesesExpression: public Expression {
public:
  ParenthesesExpression(Expression* expr);
  ExprInfo eval() const override;

private:
  Expression* expr_;
};

