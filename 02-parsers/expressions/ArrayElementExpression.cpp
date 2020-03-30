#include "ArrayElementExpression.h"

ArrayElementExpression::ArrayElementExpression(Expression *type,
                                               Expression *idx):
                                               type_(type),
                                               idx_(idx) {}
ExprInfo ArrayElementExpression::eval() const {
  //TODO
  return {};
}

void ArrayElementExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}