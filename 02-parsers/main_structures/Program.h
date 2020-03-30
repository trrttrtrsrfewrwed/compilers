#pragma once

#include <declarations/ClassDeclarationList.h>
#include "MainClass.h"
class Program: public BaseElement {
public:
  Program(MainClass* main_class, ClassDeclarationList* class_declarations);
  void Accept(Visitor* visitor);
  MainClass* main_class_;
  ClassDeclarationList* class_declarations_;
};
