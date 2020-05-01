#include "ArrayLvalue.h"
#include <iostream>

ArrayLvalue::ArrayLvalue(std::string id, Expression *idx)
    : Lvalue(id, true), idx_(idx) {
}

void ArrayLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}