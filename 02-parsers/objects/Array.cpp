#include "Array.h"
#include "Object.h"
#include <iostream>

void Array::SetValue(int value) {
  throw std::runtime_error("trying to set simple value to array");
}
BasicType *Array::GetType() {
  throw std::runtime_error("trying to get type from array");
}

Array::Array(BasicType *type) : type_(type) {
  std::ofstream off("lol2.txt");
  type_->Print(off, 0);
}

void Array::SetType(BasicType *type) {
  throw std::runtime_error("trying to set type to array");
}

int Array::GetValue() {
  throw std::runtime_error("trying to get simple value from array");
}

std::unordered_map<Symbol, BasicObject *> &Array::GetFieldValues() {
  throw std::runtime_error("trying to get field values from array");
}

void Array::SetSize(size_t size) {
  size_ = size;
  for (size_t i = 0; i < size_; ++i) {
    array_.push_back(new Object(type_));
  }
}

BasicObject *&Array::GetValue(size_t index) {
  if (index >= size_) {
    throw std::runtime_error("Out of bounds");
  } else {
    return array_[index];
  }
}

void Array::SetValueAtIndex(size_t index, BasicObject* object) {
  if (index >= size_) {
    throw std::runtime_error("Out of bounds");
  } else {
    array_[index] = object;
  }
}
void Array::AssignValue(BasicObject *another) {
  auto another_array = dynamic_cast<Array*>(another);
  SetSize(another_array->size_);
  for (size_t i = 0; i < size_; ++i) {
    array_[i]->AssignValue(another_array->array_[i]);
  }
}
