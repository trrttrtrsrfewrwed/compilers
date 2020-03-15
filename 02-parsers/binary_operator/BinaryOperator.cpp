#include "BinaryOperator.h"

BinaryOperator::BinaryOperator(BinaryOps binary_operation):
binary_operation_(binary_operation) {}

BinaryOps BinaryOperator::get_operation() {
  return binary_operation_;
}