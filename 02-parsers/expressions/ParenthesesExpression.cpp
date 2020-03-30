#include "ParenthesesExpression.h"

ParenthesesExpression::ParenthesesExpression(Expression *expr): expr_(expr) {}

ExprInfo ParenthesesExpression::eval() const {
  //TODO
  return {};
}

void ParenthesesExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}