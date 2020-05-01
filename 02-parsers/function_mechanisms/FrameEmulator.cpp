#include "FrameEmulator.h"
#include <iostream>
#include <objects/Array.h>
#include <objects/Object.h>
FrameEmulator::FrameEmulator(size_t params_size) : params_size_(params_size) {
  AllocScope();
}

void FrameEmulator::SetFields(const std::vector<BasicObject *> &values) {
  for (BasicObject *value : values) {
    params_.push_back(value);
  }
  fields_size_ = values.size();
}

void FrameEmulator::SetParams(const std::vector<BasicObject *> &values) {
  if (params_size_ != values.size()) {
    throw std::runtime_error("Mismatched number of arguments");
  }
  for (auto value : values) {
    params_.push_back(value);
  }
}

size_t FrameEmulator::AllocVariable(BasicType *type) {
  size_t index = variables_.size();
  variables_.push_back(new Object(type));

  return index;
}

size_t FrameEmulator::AllocArray(BasicType *type) {
  size_t index = variables_.size();
  variables_.push_back(new Array(type));

  return index;
}

void FrameEmulator::DeallocScope() {
  size_t new_size = offsets_.top();
  offsets_.pop();

  // TODO(@trrttrtrsrfewrwed(@Mr_TrosS) is waiting for @akhtyamovpavel)))) -
  // Call destructors
  variables_.resize(new_size);
}

void FrameEmulator::AllocScope() { offsets_.push(variables_.size()); }

BasicObject *FrameEmulator::Get(int index) const {
  if (index >= 0) {
    return variables_.at(index);
  } else {
    return params_.at(-index - 1);
  }
}

void FrameEmulator::Set(int index, BasicObject *value) {
  if (index >= 0) {
    variables_.at(index)->AssignValue(value);
  } else {
    params_.at(-index - 1)->AssignValue(value);
  }
}

void FrameEmulator::SetReturnValue(BasicObject *value) {
  return_value_ = value;
}

void FrameEmulator::SetParentFrame(FrameEmulator *frame) {
  parent_frame = frame;
}

void FrameEmulator::SetParentReturnValue(BasicObject *value) {
  parent_frame->return_value_ = value;
}

bool FrameEmulator::HasParent() { return parent_frame != nullptr; }

BasicObject *FrameEmulator::GetReturnValue() const { return return_value_; }
