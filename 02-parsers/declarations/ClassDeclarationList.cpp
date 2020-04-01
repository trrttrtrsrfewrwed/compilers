#include "ClassDeclarationList.h"
#include <iostream>

ClassDeclarationList::ClassDeclarationList(){};

void ClassDeclarationList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
void ClassDeclarationList::AddClassDeclaration(ClassDeclaration *decl) {
  declarations_.push_back(decl);
}
