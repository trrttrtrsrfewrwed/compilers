#include "ArrayType.h"

ArrayType::ArrayType(SimpleType *element_type) : element_type_(element_type) {}

std::string ArrayType::GetType() { return element_type_->GetType(); }

void ArrayType::Accept(Visitor *visitor) {
  visitor->Visit(this);
}