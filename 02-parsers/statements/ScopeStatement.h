#pragma once
#include "Statement.h"
#include "StatementList.h"

class ScopeStatement: public Statement {
public:
  ScopeStatement(StatementList* statements);

private:
  StatementList* statements_;
};
