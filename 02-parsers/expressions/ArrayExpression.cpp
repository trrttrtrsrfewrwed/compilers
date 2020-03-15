#include "ArrayExpression.h"

ArrayExpression::ArrayExpression(SimpleType *type, Expression *expr)
    : type_(type), expr_(expr) {}

ExprInfo ArrayExpression::eval() const {
  //TODO
  return {};
}