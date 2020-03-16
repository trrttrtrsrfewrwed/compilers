#include "MainClass.h"

MainClass::MainClass(std::string main_class_name, StatementList *statements)
    : main_class_name_(std::move(main_class_name)), statements_(statements) {}