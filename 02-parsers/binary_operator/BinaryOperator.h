#pragma once
#include "BinaryOps.h"
#include <base_elements/BaseElement.h>

class BinaryOperator: public BaseElement {
public:
  BinaryOperator(BinaryOps binary_operation);
  BinaryOps get_operation();
  void Accept(Visitor* visitor);

  BinaryOps binary_operation_;
};;

