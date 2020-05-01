#include "ObjectExpression.h"

ObjectExpression::ObjectExpression(TypeIdentifier *identifier): identifier_(identifier) {}

ExprInfo ObjectExpression::eval() const {
  //TODO

  return {};
}

void ObjectExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}