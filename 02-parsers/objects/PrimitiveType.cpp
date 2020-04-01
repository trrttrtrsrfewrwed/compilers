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

