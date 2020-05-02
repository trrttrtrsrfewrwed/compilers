#pragma once

#include <fstream>
class BasicType {
public:
  virtual void Print(std::ofstream& ofstream, int num_tabs);
  virtual std::string GetType();
  virtual std::string GetTypeName();
  virtual ~BasicType() = default;
  void PrintTabs(std::ofstream& ofstream, int num_tabs);
  virtual bool IsArray() = 0;
};
