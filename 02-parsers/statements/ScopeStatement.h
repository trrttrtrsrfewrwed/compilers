#pragma once
#include "Statement.h"
#include "StatementList.h"

class ScopeStatement: public Statement {
public:
  ScopeStatement(StatementList* statements);
  void Accept(Visitor* visitor);
  StatementList* statements_;
};
