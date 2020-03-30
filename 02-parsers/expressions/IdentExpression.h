#pragma once
#include "Expression.h"
#include <string>

class IdentExpression: public Expression {
public:
  IdentExpression(std::string id);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  std::string id_;
};

