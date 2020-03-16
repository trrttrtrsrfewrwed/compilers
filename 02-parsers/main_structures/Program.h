#pragma once

#include <declarations/ClassDeclarationList.h>
#include "MainClass.h"
class Program {
public:
  Program(MainClass* main_class, ClassDeclarationList* class_declarations);

private:
  MainClass* main_class_;
  ClassDeclarationList* class_declarations_;
};
