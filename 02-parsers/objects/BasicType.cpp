#include "BasicType.h"

int BasicType::ToInt() {
  return 0;
}
void BasicType::Print(std::ofstream& ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "BasicType" << std::endl;
}

void BasicType::PrintTabs(std::ofstream &ofstream, int num_tabs) {
  for (int i = 0; i < num_tabs; ++i) {
    ofstream << "\t";
  }
}
