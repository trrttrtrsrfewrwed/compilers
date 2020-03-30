#pragma once
#include "string"
#include <base_elements/BaseElement.h>
#include <iostream>
#include <statements/StatementList.h>

class MainClass: public BaseElement {
public:
  MainClass(std::string main_class_name, StatementList* statements);
  void Accept(Visitor* visitor);
  std::string main_class_name_;
  StatementList* statements_;
};
