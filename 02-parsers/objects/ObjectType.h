#pragma once

#include "BasicType.h"
#include "ClassType.h"
#include "MethodType.h"
#include <string>
#include <utility>
#include <vector>

class ObjectType : public BasicType {
public:
  ObjectType(ClassType* type,
             bool is_array = false);
  void Print(std::ofstream& ofstream, int num_tabs) override;
  std::vector<BasicType*> field_types_;
  std::vector<std::string> field_names_;
  bool is_array_;
};
