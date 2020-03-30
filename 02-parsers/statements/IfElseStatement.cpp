#include "IfElseStatement.h"

IfElseStatement::IfElseStatement(Expression *query, Statement *if_statement,
                                 Statement *else_statement)
    : query_(query), if_statement_(if_statement),
      else_statement_(else_statement) {}

void IfElseStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}