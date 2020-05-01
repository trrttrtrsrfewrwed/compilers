#include "CommonDeclaration.h"

void CommonDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}
