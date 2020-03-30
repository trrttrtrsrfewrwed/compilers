#pragma once
#include <vector>
#include "ClassDeclaration.h"

class ClassDeclarationList: public BaseElement {
public:
  ClassDeclarationList();
  ClassDeclarationList(ClassDeclaration* decl);
  void Accept(Visitor* visitor);

  std::vector<ClassDeclaration*> declarations_;
};