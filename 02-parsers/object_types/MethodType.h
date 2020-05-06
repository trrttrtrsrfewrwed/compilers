#pragma once

#include "BasicType.h"
#include <string>
#include <vector>

class MethodType : public BasicType {
public:
  MethodType(const std::vector<std::pair<BasicType*, std::string>>& arguments, BasicType* return_type);
  void Print(std::ofstream& ofstream, int num_tabs) override;
  size_t GetSize() override;
  std::string GetType() override;
  std::vector<BasicType*> argument_types_;
  std::vector<std::string> argument_names_;
  BasicType* return_type_;
  bool IsArray() override;
};
