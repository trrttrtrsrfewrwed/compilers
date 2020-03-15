#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *e1, Expression *e2,
                                   BinaryOperator *op):
                                   first(e1),
                                   second(e2),
                                   op_(op){}

ExprInfo BinaryExpression::eval() const {
  switch(op_->get_operation()) {
  case AndOp:
    return first->eval() && second->eval();
  case OrOp:
    return first->eval() || second->eval();
  case LessOp:
    return first->eval() < second->eval();
  case GreaterOp:
    return first->eval() > second->eval();
  case EqualOp:
    return first->eval() == second->eval();
  case AddOp:
    return first->eval() + second->eval();
  case SubtractOp:
    return first->eval() - second->eval();
  case MultiplyOp:
    return first->eval() * second->eval();
  case DivOp:
    return first->eval() / second->eval();
  case ModOp:
    return first->eval() % second->eval();
  }
}
