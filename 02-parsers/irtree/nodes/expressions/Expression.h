#pragma once

#include "../BaseElement.h"

namespace IRT {

class Expression : public BaseElement {
public:
  virtual ~Expression() = default;
  virtual bool IsESEQ() { return false; }
  virtual bool IsCONST() { return false; }
  virtual bool IsNAME() { return false; }
};
} // namespace IRT
