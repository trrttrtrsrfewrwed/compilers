#include "WhileStatement.h"

WhileStatement::WhileStatement(Expression *query, Statement *while_statement)
    : query_(query), while_statement_(while_statement) {}

void WhileStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}