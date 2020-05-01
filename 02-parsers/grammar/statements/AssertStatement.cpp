#include "AssertStatement.h"

AssertStatement::AssertStatement(Expression *expr): expr_(expr) {}

void AssertStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}