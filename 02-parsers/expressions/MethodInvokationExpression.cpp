#include "MethodInvokationExpression.h"

MethodInvokationExpression::MethodInvokationExpression(
    MethodInvokation *method_invokation)
    : method_invokation_(method_invokation) {}

ExprInfo MethodInvokationExpression::eval() const {
  //TODO
  return {};
}

void MethodInvokationExpression::Accept(Visitor *visitor) {
  visitor->Visit(this);
}