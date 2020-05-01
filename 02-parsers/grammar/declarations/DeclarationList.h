#pragma once
#include "Declaration.h"
class DeclarationList: public BaseElement {
public:
  DeclarationList();
  void AddDeclaration(Declaration* decl);
  void Accept(Visitor* visitor);

  std::vector<Declaration*> declarations_;
};