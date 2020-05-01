#pragma once

#include "BasicType.h"

enum TYPE {
  Integer = 0,
  Boolean = 1
};

class PrimitiveType: public BasicType {
public:
  void Print(std::ofstream& ofstream, int num_tabs) override;
  explicit PrimitiveType(TYPE type, bool is_array);
  std::string GetType() override;
  std::string GetTypeName() override;
  TYPE type_;
  bool is_array_;
};

