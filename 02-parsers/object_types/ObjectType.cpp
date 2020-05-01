//
// Created by timur on 31.03.2020.
//

#include "ObjectType.h"

ObjectType::ObjectType(ClassType* type, bool is_array)
    : is_array_(is_array), field_names_(type->field_names_),
      field_types_(type->field_types_),
      class_name_(type->class_name_) {}

void ObjectType::Print(std::ofstream &ofstream, int num_tabs) {
  PrintTabs(ofstream, num_tabs);
  ofstream << "ObjectType: " << std::endl;
  PrintTabs(ofstream, num_tabs);
  ofstream << "  fields" << std::endl;
  for (size_t i = 0; i < field_types_.size(); ++i) {
    PrintTabs(ofstream, num_tabs + 1);
    ofstream << i << ". " << field_names_[i] << std::endl;
    field_types_[i]->Print(ofstream, num_tabs + 1);
  }
  PrintTabs(ofstream, num_tabs);
  if (is_array_) {
    ofstream << "  array" << std::endl;
  } else {
    ofstream << "  simple" << std::endl;
  }
}
std::string ObjectType::GetType() { return "ObjectType"; }
std::string ObjectType::GetTypeName() { return class_name_; }
