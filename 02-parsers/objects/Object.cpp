#include "Object.h"

#include "BasicObject.h"
#include <iostream>
#include <object_types/ObjectType.h>

Object::Object(BasicType *type) : type_(type) {
  if (type->GetType() == "ObjectType") {
    auto obj_type = dynamic_cast<ObjectType *>(type);
    for (size_t i = 0; i < obj_type->field_names_.size(); ++i) {
      if (obj_type->field_types_[i]->GetType() != "MethodType") {
        field_values_[Symbol(obj_type->field_names_[i])] =
            new Object(obj_type->field_types_[i]);
      }
    }
  }
}

Object::Object(BasicType *type, int value) : type_(type) {
  if (type->GetType() != "PrimitiveType") {
    throw std::runtime_error("trying to create non primitive with value\n");
  }
  SetValue(value);
}

void Object::SetValue(int value) {
  if (!field_values_.empty()) {
    throw std::runtime_error("trying to set value to non primitive\n");
  }
  value_ = value;
}
void Object::AssignValue(BasicObject *another) {
  auto another_obj = dynamic_cast<Object*>(another);
  this->value_ = another_obj->GetValue();
  this->type_ = another_obj->type_;
  for (const auto &field : another_obj->field_values_) {
    *this->field_values_[field.first] = *field.second;
  }
}

BasicType *Object::GetType() { return type_; }
void Object::SetType(BasicType *type) { type_ = type; };
int Object::GetValue() { return value_; };

std::unordered_map<Symbol, BasicObject *> &Object::GetFieldValues() {
  return field_values_;
}
Object::~Object(){

}
