#pragma once

#include "BasicType.h"

class UninitObject: public BasicType {
public:
  int ToInt() override;
};

