#pragma once
#include "BinaryOps.h"
class BinaryOperator {
public:
  BinaryOperator(BinaryOps binary_operation);
  BinaryOps get_operation();
private:
  BinaryOps binary_operation_;
};;

