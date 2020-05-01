#include "ScopeStatement.h"

ScopeStatement::ScopeStatement(StatementList *statements)
    : statements_(statements) {}

void ScopeStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}