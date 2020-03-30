#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class SoutStatement: public Statement {
public:
  SoutStatement(Expression* expr);
  void Accept(Visitor* visitor);
  Expression* expr_;
};
