#include "NotExpression.h"

NotExpression::NotExpression(Expression *expr): expr_(expr) {}

ExprInfo NotExpression::eval() const {
  //TODO
  return {};
}

void NotExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}