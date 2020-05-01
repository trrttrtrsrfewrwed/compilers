//
// Created by timur on 31.03.2020.
//

#include "MethodType.h"

MethodType::MethodType(
    const std::vector<std::pair<BasicType*, std::string>> &arguments,
    BasicType* return_type): return_type_(return_type) {
  for (const auto& arg: arguments) {
    argument_types_.push_back(arg.first);
    argument_names_.push_back(arg.second);
  }
}
void MethodType::Print(std::ofstream &ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "MethodType: " << std::endl;
  PrintTabs(ofstream, num_tabs);
  ofstream << "  args" << std::endl;
  for (size_t i = 0; i < argument_names_.size(); ++i) {
    PrintTabs(ofstream, num_tabs + 1);
    ofstream << i << ". " << argument_names_[i] << std::endl;
    argument_types_[i]->Print(ofstream, num_tabs + 1);
  }
  PrintTabs(ofstream, num_tabs);
  ofstream << "  returns" << std::endl;
  return_type_->Print(ofstream, num_tabs + 1);
}
std::string MethodType::GetType() { return "MethodType"; }
