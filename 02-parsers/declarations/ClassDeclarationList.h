#pragma once
#include <vector>
#include "ClassDeclaration.h"

class ClassDeclarationList {
public:
  ClassDeclarationList();
  ClassDeclarationList(ClassDeclaration* decl);
private:
  std::vector<ClassDeclaration*> declarations_;
};