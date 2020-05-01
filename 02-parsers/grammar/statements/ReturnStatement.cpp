#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Expression *return_expr)
    : return_expr_(return_expr) {}

void ReturnStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}