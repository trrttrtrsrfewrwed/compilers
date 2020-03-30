#include "ClassDeclarationList.h"
#include <iostream>

ClassDeclarationList::ClassDeclarationList(){};

ClassDeclarationList::ClassDeclarationList(ClassDeclaration *decl) {
  declarations_.push_back(decl);
}

void ClassDeclarationList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}