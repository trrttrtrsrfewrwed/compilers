#include "ClassType.h"

ClassType::ClassType(
    const std::vector<std::pair<BasicType*, std::string>> &fields) {
  for (const auto &field : fields) {
    field_types_.push_back(field.first);
    field_names_.push_back(field.second);
  }
}
void ClassType::Print(std::ofstream &ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "ClassType: " << std::endl;
  PrintTabs(ofstream, num_tabs);
  ofstream << "  fields" << std::endl;
  for (size_t i = 0; i < field_types_.size(); ++i) {
    PrintTabs(ofstream, num_tabs + 1);
    ofstream << i << ". " << field_names_[i] << std::endl;
    field_types_[i]->Print(ofstream, num_tabs + 1);
  }
}
void ClassType::PrintTabs(std::ofstream &ofstream, int num_tabs) {
  for (int i = 0; i < num_tabs; ++i) {
    ofstream << "\t";
  }
}
