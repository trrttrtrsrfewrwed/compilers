#pragma once
#include "Statement.h"
#include <expressions/Expression.h>

class SoutStatement: public Statement {
public:
  SoutStatement(Expression* expr);

private:
  Expression* expr_;
};
