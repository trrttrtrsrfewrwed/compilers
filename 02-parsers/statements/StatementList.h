#pragma once

#include "Statement.h"
#include <vector>
class StatementList {
public:
  StatementList();
  void AddStatement(Statement* statement);
private:
  std::vector<Statement*> statements_;
};
