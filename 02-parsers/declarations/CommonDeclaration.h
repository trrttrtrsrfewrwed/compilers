#pragma once

#include <base_elements/BaseElement.h>

class CommonDeclaration: public BaseElement {
public:
  void Accept(Visitor* visitor);
};