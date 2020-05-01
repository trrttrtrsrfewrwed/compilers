#pragma once

#include <object_types/BasicType.h>
#include <symbol_table/Symbol.h>
#include <vector>


class BasicObject {
public:
  virtual void SetValue(int value) = 0;

  virtual BasicType* GetType() = 0;
  virtual void AssignValue(BasicObject* obj) = 0;
  virtual void SetType(BasicType* type) = 0;
  virtual int GetValue() = 0;
  virtual std::unordered_map<Symbol, BasicObject*>& GetFieldValues() = 0;
};