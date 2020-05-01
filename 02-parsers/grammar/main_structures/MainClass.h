#pragma once
#include "string"
#include <grammar/base_elements/BaseElement.h>
#include <iostream>
#include <grammar/statements/StatementList.h>

class MainClass: public BaseElement {
public:
  MainClass(std::string main_class_name, StatementList* statements);
  void Accept(Visitor* visitor);
  std::string main_class_name_;
  StatementList* statements_;
};
