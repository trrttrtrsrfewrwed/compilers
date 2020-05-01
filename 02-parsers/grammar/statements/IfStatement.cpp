#include "IfStatement.h"

IfStatement::IfStatement(Expression *query, Statement *if_statement)
    : query_(query), if_statement_(if_statement) {}

void IfStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}