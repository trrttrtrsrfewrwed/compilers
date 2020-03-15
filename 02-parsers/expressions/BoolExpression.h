#pragma once
#include "Expression.h"
#include "string"

class BoolExpression: public Expression {
public:
  BoolExpression(const std::string& value);
  ExprInfo eval() const override;

private:
  bool value_;
};

