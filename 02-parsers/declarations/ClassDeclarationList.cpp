#include "ClassDeclarationList.h"

ClassDeclarationList::ClassDeclarationList(){};

ClassDeclarationList::ClassDeclarationList(ClassDeclaration *decl) {
  declarations_.push_back(decl);
}
