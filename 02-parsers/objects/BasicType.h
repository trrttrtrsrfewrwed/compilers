#pragma once

#include <fstream>
class BasicType {
public:
  virtual void Print(std::ofstream& ofstream, int num_tabs);
  virtual int ToInt();
  virtual ~BasicType() = default;
  void PrintTabs(std::ofstream& ofstream, int num_tabs);
};
