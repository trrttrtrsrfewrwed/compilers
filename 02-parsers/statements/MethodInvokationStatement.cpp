#include "MethodInvokationStatement.h"

MethodInvokationStatement::MethodInvokationStatement(
    MethodInvokation *method_invokation)
    : method_invokation_(method_invokation) {}

void MethodInvokationStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}