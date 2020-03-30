#pragma once
#include "Statement.h"
#include <expressions/Expression.h>
#include <lvalues/Lvalue.h>

class DefinitionStatement: public Statement {
public:
  DefinitionStatement(Lvalue* lvalue, Expression* expr);
  void Accept(Visitor* visitor);
  Lvalue* lvalue_;
  Expression* expr_;
};
