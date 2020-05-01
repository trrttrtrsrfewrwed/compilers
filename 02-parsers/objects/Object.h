#pragma once

#include "BasicObject.h"
class Object: public BasicObject {
public:
  Object(BasicType* type, int value);
  explicit Object(BasicType* type);
  ~Object();
  void SetValue(int value) override;
  void AssignValue(BasicObject* another) override;

  BasicType* GetType() override;

  void SetType(BasicType* type) override;
  int GetValue() override;
  std::unordered_map<Symbol, BasicObject*>& GetFieldValues() override;

private:
  BasicType* type_;
  int value_;
  std::unordered_map<Symbol, BasicObject*> field_values_;
};