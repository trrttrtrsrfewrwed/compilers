#pragma once
#include "types/Type.h"
#include <base_elements/BaseElement.h>
#include <deque>
#include <string>

class FormalList: public BaseElement {
public:
  FormalList();
  void AddFormal(Type* arg_type, std::string arg_name);
  void Accept(Visitor* visitor);

  std::deque<std::pair<Type*, std::string>> args_;
};

