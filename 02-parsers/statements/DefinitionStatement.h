#pragma once
#include "Statement.h"
#include <expressions/Expression.h>
#include <lvalues/Lvalue.h>

class DefinitionStatement: public Statement {
public:
  DefinitionStatement(Lvalue* lvalue, Expression* expr);

private:
  Lvalue* lvalue_;
  Expression* expr_;
};
