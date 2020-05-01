#include "MainClass.h"
#include <iostream>

MainClass::MainClass(std::string main_class_name, StatementList *statements)
    : main_class_name_(std::move(main_class_name)), statements_(statements) {
}

void MainClass::Accept(Visitor *visitor) {
  visitor->Visit(this);
}