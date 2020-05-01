#include "SoutStatement.h"

SoutStatement::SoutStatement(Expression *expr) : expr_(expr) {}

void SoutStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}