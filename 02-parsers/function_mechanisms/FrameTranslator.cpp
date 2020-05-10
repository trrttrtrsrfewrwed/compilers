//
// Created by akhtyamovpavel on 4/14/20.
//

#include "FrameTranslator.h"
#include <function_mechanisms/address/AddressInFrame.h>
#include <function_mechanisms/address/AddressInRegister.h>
#include <irtree/types/BinaryOperatorType.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>

namespace IRT {
FrameTranslator::FrameTranslator(const std::string &function_name, ClassType* class_type)
    : function_name_(function_name), class_type_(class_type) {

  addresses_[frame_pointer_address_].push(new AddressInRegister(
      Temporary(frame_pointer_address_)
  ));

  addresses_[return_value_address_].push(new AddressInRegister(
      Temporary(return_value_address_)
  ));
}
void FrameTranslator::SetupScope() {
  symbols_.push("{");
}

void FrameTranslator::TearDownScope() {
  while (symbols_.top() != "{") {
    std::string symbol = symbols_.top();

//    std::cerr << "Popping " << symbol.GetName() << std::endl;

    addresses_[symbol].pop();
    if (addresses_[symbol].empty()) {
      addresses_.erase(symbol);
    }
    symbols_.pop();
  }
  symbols_.pop();
}

void FrameTranslator::AddLocalVariable(const std::string &name) {
  AddVariable(name);
}

Address *FrameTranslator::FramePointer() {
  return addresses_[frame_pointer_address_].top();
}

int FrameTranslator::GetOffset() {
  int tmp = max_offset_;
  max_offset_ += word_size_;
  return tmp;
}
void FrameTranslator::AddArgumentAddress(const std::string &name) {
  AddVariable(name);
}

void FrameTranslator::AddVariable(const std::string &name) {
  symbols_.push(name);

  if (addresses_.find(name) == addresses_.end()) {
    addresses_[name];
  }
  addresses_[name].push(
      new AddressInFrame(FramePointer(), GetOffset())
  );
}

Expression *FrameTranslator::GetField(const std::string &name) {
  IRT::Expression* this_pointer = addresses_["this"].top()->ToExpression();

  IRT::Expression* field_pointer = nullptr;

  size_t offset = 0;
  bool flg = false;
  for (size_t i = 0; i < class_type_->field_names_.size(); ++i) {
    if (class_type_->field_names_[i] == name) {
      flg  = true;
      break;
    }
    offset += class_type_->field_types_[i]->GetSize();
  }
  if (flg) {
    field_pointer = new IRT::MemExpression(
        new IRT::BinopExpression(IRT::BinaryOperatorType::PLUS,
                             this_pointer,
                             new IRT::ConstExpression(offset)));
  } else {
    throw std::runtime_error("trying to get non existing field");
  }
  return field_pointer;
}

IRT::Expression *FrameTranslator::GetAddress(const std::string &name) {
  // this будет храниться в виде IRT::Address* в addresses_["this"]
  // Важно! В случае, если переменная не примитивного типа, GetAdress()->ToExpression()
  // вернёт указатель на переменную (её адрес в памяти), иначе - значение
  if (addresses_[name].empty()) {
    return GetField(name);
  }

  return addresses_[name].top()->ToExpression();
}
void FrameTranslator::AddReturnAddress() {
  AddVariable(return_address_);
}

IRT::Expression *FrameTranslator::GetReturnValueAddress() {
  return  GetAddress(return_value_address_);
}
void FrameTranslator::AddLocalArray(std::string& name) {
  AddVariable(name);
}

}