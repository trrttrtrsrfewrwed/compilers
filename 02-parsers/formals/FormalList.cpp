#include "FormalList.h"

FormalList::FormalList() {};

void FormalList::AddFormal(Type *arg_type, std::string arg_name) {
  args_.push_front(std::make_pair(arg_type, std::move(arg_name)));
}

void FormalList::Accept(Visitor *visitor) {
  visitor->Visit(this);
}