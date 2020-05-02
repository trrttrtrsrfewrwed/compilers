#include "VoidType.h"

void VoidType::Print(std::ofstream &ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "VoidType " << std::endl;
}
std::string VoidType::GetType() { return "VoidType"; }

bool VoidType::IsArray() {
  throw std::runtime_error("Trying to ask IsArray from VoidType");
}
