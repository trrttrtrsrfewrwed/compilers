#pragma once

#include "../BaseElement.h"

namespace IRT {

class Statement : public BaseElement {
 public:
  virtual ~Statement() = default;
  virtual bool IsSEQ() { return false; }
  virtual bool IsEXP() { return false; }
};
}
