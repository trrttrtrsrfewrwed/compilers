#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class IfStatement: public Statement {
public:
  IfStatement(Expression* query, Statement* if_statement);
  void Accept(Visitor* visitor);
  Expression* query_;
  Statement* if_statement_;
};
