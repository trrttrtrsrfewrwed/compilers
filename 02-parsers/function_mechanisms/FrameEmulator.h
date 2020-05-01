//
// Created by Pavel Akhtyamov on 25.03.2020.
//

#pragma once

#include <memory>
#include <objects/BasicObject.h>
#include <objects/Object.h>
#include <stack>
#include <vector>

class FrameEmulator {
public:
  explicit FrameEmulator(size_t params_size);
  void SetParams(const std::vector<BasicObject *> &values);
  void SetFields(const std::vector<BasicObject *> &values);

  size_t AllocVariable(BasicType *type);
  size_t AllocArray(BasicType* type);

  void DeallocScope();
  void AllocScope();

  BasicObject *Get(int index) const;

  void Set(int index, BasicObject *value);

  void SetParentFrame(FrameEmulator *frame);

  BasicObject *GetReturnValue() const;

  void SetParentReturnValue(BasicObject *value);

  bool HasParent();

  size_t GetFieldsSize() { return fields_size_; }

private:
  std::stack<int> offsets_;
  std::vector<BasicObject *> params_; // and fields of the object
  size_t params_size_;
  size_t fields_size_;
  std::vector<BasicObject *> variables_;

  BasicObject *return_value_;

  void SetReturnValue(BasicObject *value);

  FrameEmulator *parent_frame = nullptr;
};
