#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class ReturnStatement: public Statement {
public:
  ReturnStatement(Expression* return_expr);

private:
  Expression* return_expr_;
};

