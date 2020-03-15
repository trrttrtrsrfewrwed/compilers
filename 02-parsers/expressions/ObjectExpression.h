#pragma once
#include "Expression.h"
#include "types/TypeIdentifier.h"

class ObjectExpression: public Expression {
public:
  ObjectExpression(TypeIdentifier* identifier);
  ExprInfo eval() const override;

private:
  TypeIdentifier* identifier_;
};
