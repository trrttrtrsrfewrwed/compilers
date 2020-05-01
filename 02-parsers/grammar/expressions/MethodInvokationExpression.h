#pragma once
#include "Expression.h"
#include "grammar/method_invokation/MethodInvokation.h"

class MethodInvokationExpression: public Expression {
public:
  MethodInvokationExpression(MethodInvokation* method_invokation);
  ExprInfo eval() const override;
  void Accept(Visitor* visitor);

  MethodInvokation* method_invokation_;
};

