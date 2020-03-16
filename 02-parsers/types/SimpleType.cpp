#include "SimpleType.h"
#include "iostream"

SimpleType::SimpleType(std::string type) {
  if (type == "int" || type == "boolean" || type == "void") {
    type_ = std::move(type);
  } else {
    std::cerr << "Exception in SimpleType: " << type << "\n";
  }
}

SimpleType::SimpleType(TypeIdentifier *type_id) {
  type_ = type_id->GetTypeName();
}

std::string SimpleType::GetType() { return type_; }