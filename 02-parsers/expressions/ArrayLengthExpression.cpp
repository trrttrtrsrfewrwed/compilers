#include "ArrayLengthExpression.h"

ArrayLengthExpression::ArrayLengthExpression(Expression *expr): expr_(expr) {}

ExprInfo ArrayLengthExpression::eval() const {
  //TODO
  return {};
}

void ArrayLengthExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}