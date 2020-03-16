#pragma once

#include "Expression.h"
#include <deque>
class ExpressionList {
public:
  ExpressionList();
  void AddExpression(Expression* expr);
private:
  std::deque<Expression*> expressions_;
};

