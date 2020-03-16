#pragma once
#include <string>

class TypeIdentifier {
public:
  TypeIdentifier(std::string type_name);
  std::string GetTypeName();
private:
  std::string type_name_;
};
