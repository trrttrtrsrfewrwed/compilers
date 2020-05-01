#pragma once

#include "BasicType.h"
#include <string>
#include <vector>

class ClassType {
public:
  ClassType(const std::vector<std::pair<BasicType*, std::string>> &fields, std::string class_name);
  void Print(std::ofstream& ofstream, int num_tabs);
  void PrintTabs(std::ofstream& ofstream, int num_tabs);
  std::vector<BasicType*> field_types_;
  std::vector<std::string> field_names_;
  std::string class_name_;
};
