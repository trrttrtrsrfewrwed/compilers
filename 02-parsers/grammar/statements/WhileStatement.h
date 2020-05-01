#pragma once
#include "Statement.h"
#include <grammar/expressions/Expression.h>

class WhileStatement: public Statement {
public:
  WhileStatement(Expression* query, Statement* while_statement);
  void Accept(Visitor* visitor);
  Expression* query_;
  Statement* while_statement_;
};