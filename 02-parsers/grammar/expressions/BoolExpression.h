#pragma once
#include "Expression.h"
#include "string"

class BoolExpression: public Expression {
public:
  BoolExpression(const std::string& value);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  bool value_;
};

