#include "ThisExpression.h"
#include <iostream>

ThisExpression::ThisExpression(std::string value) {
  if (value != "this") {
    std::cerr << "Exception in ThisExpression!: " << value << "\n";
  }
}

ExprInfo ThisExpression::eval() const {
  //TODO
  return {};
}