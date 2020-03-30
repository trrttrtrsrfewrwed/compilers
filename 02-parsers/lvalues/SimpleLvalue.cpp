#include "SimpleLvalue.h"

SimpleLvalue::SimpleLvalue(std::string id): id_(std::move(id)) {}

void SimpleLvalue::Accept(Visitor *visitor) {
  visitor->Visit(this);
}