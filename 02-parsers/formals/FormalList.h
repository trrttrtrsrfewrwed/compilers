#pragma once
#include "types/Type.h"
#include <string>
#include <deque>

class FormalList {
public:
  FormalList();
  void AddFormal(Type* arg_type, std::string arg_name);

private:
  std::deque<std::pair<Type*, std::string>> args_;
};

