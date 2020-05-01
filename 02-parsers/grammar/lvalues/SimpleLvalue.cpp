#include "SimpleLvalue.h"

SimpleLvalue::SimpleLvalue(std::string id): Lvalue(std::move(id), false) {}

void SimpleLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}