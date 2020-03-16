#include "ExpressionList.h"

ExpressionList::ExpressionList() {}

void ExpressionList::AddExpression(Expression *expr) {
  expressions_.push_front(expr);
}