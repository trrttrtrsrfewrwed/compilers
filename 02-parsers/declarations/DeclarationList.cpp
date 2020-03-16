#include "DeclarationList.h"

DeclarationList::DeclarationList() {}

void DeclarationList::AddDeclaration(Declaration *decl) {
  declarations_.push_back(decl);
}