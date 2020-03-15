#include "BoolExpression.h"
#include <iostream>

BoolExpression::BoolExpression(const std::string& value) {
  if (value == "true") {
    value_ = true;
  } else if (value == "false") {
    value_ = false;
  } else {
    std::cerr << "exception in bool!" << "\n";
  }
}

ExprInfo BoolExpression::eval() const {
  //TODO
  return {};
}