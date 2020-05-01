#pragma once
#include "BasicObject.h"
class Array: public BasicObject {
public:
  explicit Array(BasicType* type);

  void SetSize(size_t size);

  BasicObject*& GetValue(size_t index);

  void SetValueAtIndex(size_t index, BasicObject* ob);

  void SetValue(int value) override;

  BasicType* GetType() override;
  void AssignValue(BasicObject* another) override;
  void SetType(BasicType* type) override;
  int GetValue() override;
  std::unordered_map<Symbol, BasicObject*>& GetFieldValues() override;
private:
  BasicType* type_;
  std::vector<BasicObject*> array_;
  size_t size_ = 0;
};

