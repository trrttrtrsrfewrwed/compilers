#pragma once
#include "Declaration.h"
class DeclarationList {
public:
  DeclarationList();
  void AddDeclaration(Declaration* decl);
private:
  std::vector<Declaration*> declarations_;
};