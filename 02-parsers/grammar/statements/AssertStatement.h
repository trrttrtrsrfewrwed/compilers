#pragma once
#include "Statement.h"
#include <grammar/expressions/Expression.h>

class AssertStatement: public Statement {
public:
  AssertStatement(Expression* expr);
  void Accept(Visitor* visitor);
  Expression* expr_;
};

