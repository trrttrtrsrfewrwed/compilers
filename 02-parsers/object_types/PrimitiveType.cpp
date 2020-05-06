#include "PrimitiveType.h"

PrimitiveType::PrimitiveType(TYPE type, bool is_array)
    : is_array_(is_array), type_(type) {}

void PrimitiveType::Print(std::ofstream &ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "PrimitiveType: " << std::endl;
  PrintTabs(ofstream, num_tabs);
  if (type_ == Integer) {
    ofstream << "  Integer" << std::endl;
  } else {
    ofstream << "  Boolean" << std::endl;
  }
  PrintTabs(ofstream, num_tabs);
  if (is_array_) {
    ofstream << "  array" << std::endl;
  } else {
    ofstream << "  simple" << std::endl;
  }

}
std::string PrimitiveType::GetType() { return "PrimitiveType"; }

std::string PrimitiveType::GetTypeName() {
  if (type_ == Integer) {
    return "Integer";
  } else {
    return "Boolean";
  }
}
bool PrimitiveType::IsArray() { return is_array_; }
size_t PrimitiveType::GetSize() {
  // TODO (@trrttrtrsrfewrwed) change 4 to word size
  return 4;
}
