#pragma once
#include "string"
#include <statements/StatementList.h>

class MainClass {
public:
  MainClass(std::string main_class_name, StatementList* statements);

private:
  std::string main_class_name_;
  StatementList* statements_;
};
