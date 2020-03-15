#include "IdentExpression.h"

IdentExpression::IdentExpression(std::string id) : id_(std::move(id)) {}

ExprInfo IdentExpression::eval() const {
  //TODO
  return {}
}