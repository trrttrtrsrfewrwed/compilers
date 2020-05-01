#pragma once
#include <vector>
#include "ClassDeclaration.h"

class ClassDeclarationList: public BaseElement {
public:
  ClassDeclarationList();
  void AddClassDeclaration(ClassDeclaration* decl);
  void Accept(Visitor* visitor);

  std::vector<ClassDeclaration*> declarations_;
};