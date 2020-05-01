#pragma once
#include "Expression.h"
#include "grammar/types/TypeIdentifier.h"

class ObjectExpression: public Expression {
public:
  ObjectExpression(TypeIdentifier* identifier);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  TypeIdentifier* identifier_;
};
