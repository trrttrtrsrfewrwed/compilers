#pragma once
#include "Expression.h"
#include <string>

class ThisExpression: public Expression {
public:
  ThisExpression(std::string value);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);
};
