#pragma once
#include "Statement.h"
#include <grammar/method_invokation/MethodInvokation.h>

class MethodInvokationStatement: public Statement {
public:
  MethodInvokationStatement(MethodInvokation* method_invokation);
  void Accept(Visitor* visitor);
  MethodInvokation* method_invokation_;
};

