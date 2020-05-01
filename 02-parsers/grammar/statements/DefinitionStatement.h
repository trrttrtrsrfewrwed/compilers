#pragma once
#include "Statement.h"
#include <grammar/expressions/Expression.h>
#include <grammar/lvalues/Lvalue.h>

class DefinitionStatement: public Statement {
public:
  DefinitionStatement(Lvalue* lvalue, Expression* expr);
  void Accept(Visitor* visitor);
  Lvalue* lvalue_;
  Expression* expr_;
};
