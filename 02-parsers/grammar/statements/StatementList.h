#pragma once

#include "Statement.h"
#include <vector>
class StatementList: public BaseElement {
public:
  StatementList();
  void AddStatement(Statement* statement);
  void Accept(Visitor* visitor);
  std::vector<Statement*> statements_;
};
