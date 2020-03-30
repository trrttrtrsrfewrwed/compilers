#pragma once

#include "Expression.h"
#include <deque>
class ExpressionList: public BaseElement{
public:
  ExpressionList();
  void AddExpression(Expression* expr);
  void Accept(Visitor* visitor);

  std::deque<Expression*> expressions_;
};

