#include "BasicType.h"

void BasicType::Print(std::ofstream& ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "BasicType" << std::endl;
}

void BasicType::PrintTabs(std::ofstream &ofstream, int num_tabs) {
  for (int i = 0; i < num_tabs; ++i) {
    ofstream << "\t";
  }
}
std::string BasicType::GetType() { return "BasicType"; }
std::string BasicType::GetTypeName() {
  throw std::runtime_error("trying to get unrecognized type name\n");
}
