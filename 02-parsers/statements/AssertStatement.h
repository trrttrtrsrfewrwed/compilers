#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class AssertStatement: public Statement {
public:
  AssertStatement(Expression* expr);

private:
  Expression* expr_;
};

