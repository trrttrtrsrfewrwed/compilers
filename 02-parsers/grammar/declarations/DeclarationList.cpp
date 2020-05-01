#include "DeclarationList.h"

DeclarationList::DeclarationList() {}

void DeclarationList::AddDeclaration(Declaration *decl) {
  declarations_.push_back(decl);
}

void DeclarationList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}