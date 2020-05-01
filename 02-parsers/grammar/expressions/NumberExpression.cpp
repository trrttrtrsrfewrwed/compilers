#include "NumberExpression.h"

NumberExpression::NumberExpression(int value): value_(value) {}

ExprInfo NumberExpression::eval() const {
  //TODO
  return {};
}

void NumberExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}