#pragma once
#include "Expression.h"
#include "types/SimpleType.h"

class ArrayExpression: public Expression {
public:
  ArrayExpression(SimpleType* type, Expression* expr);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  SimpleType* type_;
  Expression* expr_;
};

