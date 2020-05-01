#include "TypeIdentifier.h"

TypeIdentifier::TypeIdentifier(std::string type_name)
    : type_name_(std::move(type_name)) {}

std::string TypeIdentifier::GetTypeName() { return type_name_; }

void TypeIdentifier::Accept(Visitor *visitor) {
  visitor->Visit(this);
}