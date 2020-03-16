#pragma once
#include "Statement.h"
#include <method_invokation/MethodInvokation.h>

class MethodInvokationStatement: public Statement {
public:
  MethodInvokationStatement(MethodInvokation* method_invokation);

private:
  MethodInvokation* method_invokation_;
};

