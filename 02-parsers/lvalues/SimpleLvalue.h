#pragma once

#include "Lvalue.h"
#include <string>
class SimpleLvalue: public Lvalue {
public:
  SimpleLvalue(std::string id);

private:
  std::string id_;
};

