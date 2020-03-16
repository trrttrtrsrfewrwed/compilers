#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class IfElseStatement: public Statement {
public:
  IfElseStatement(Expression* query, Statement* if_statement, Statement* else_statement);

private:
  Expression* query_;
  Statement* if_statement_;
  Statement* else_statement_;
};
