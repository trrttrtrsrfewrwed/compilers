#pragma once

#include <grammar/base_elements/BaseElement.h>
#include <string>
#include <utility>
class Lvalue: public BaseElement {
public:
  Lvalue(std::string id, bool is_array) : id_(id), is_array_(is_array) {};
  std::string id_;
  bool is_array_;
};
