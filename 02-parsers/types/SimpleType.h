#pragma once
#include <string>
#include "TypeIdentifier.h"

class SimpleType {
public:
  SimpleType(std::string type);
  SimpleType(TypeIdentifier* type_id);

  std::string GetType();
private:
  std::string type_;
};
