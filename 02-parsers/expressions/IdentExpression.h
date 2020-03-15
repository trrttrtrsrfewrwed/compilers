#pragma once
#include "Expression.h"
#include <string>

class IdentExpression: public Expression {
public:
  IdentExpression(std::string id);
  ExprInfo eval() const override;

private:
  std::string id_;
};

