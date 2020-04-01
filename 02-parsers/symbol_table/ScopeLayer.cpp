#include "ScopeLayer.h"
#include <objects/MethodType.h>
#include <objects/PrimitiveType.h>

ScopeLayer::ScopeLayer(ScopeLayer * parent): parent_(parent) {
  parent_->AddChild(this);
}

ScopeLayer::ScopeLayer(): parent_(nullptr) {}

void ScopeLayer::DeclarePrimitive(Symbol symbol, Type* type) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable has declared");
  }
  if (type->type_ == "int") {
    values_[symbol] = std::make_shared<PrimitiveType>(Integer, type->is_array_);
  } else if (type->type_ == "boolean") {
    values_[symbol] = std::make_shared<PrimitiveType>(Boolean, type->is_array_);
  } else {
    throw std::runtime_error("Unexpected error in declaring primitive");
  }
}

void ScopeLayer::DeclareMethod(Symbol symbol, MethodType* type) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Method has declared");
  }
  values_[symbol] = std::shared_ptr<MethodType>(type);
}

void ScopeLayer::DeclareObject(Symbol symbol, ClassType* type, bool is_array) {
  if (values_.find(symbol) != values_.end()) {
    throw std::runtime_error("Variable has declared");
  }
  values_[symbol] = std::make_shared<ObjectType>(type, is_array);
}


void ScopeLayer::Put(Symbol symbol, std::shared_ptr<BasicType> value) {

  ScopeLayer * current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    current_layer->values_.find(symbol)->second = value;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

bool ScopeLayer::Has(Symbol symbol) {
  return values_.find(symbol) != values_.end();
}


std::shared_ptr<BasicType> ScopeLayer::Get(Symbol symbol) {
  ScopeLayer * current_layer = this;

  while (!current_layer->Has(symbol) && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }
  if (current_layer->Has(symbol)) {
    return current_layer->values_.find(symbol)->second;
  } else {
    throw std::runtime_error("Variable not declared");
  }
}

ScopeLayer *ScopeLayer::GetChild(size_t index) {
  return children_[index];
}

void ScopeLayer::AddChild(ScopeLayer * child) {
  children_.push_back(child);
}

ScopeLayer *ScopeLayer::GetParent() const {
  return parent_;
}

ScopeLayer::~ScopeLayer() {
  for (ScopeLayer * layer: children_) {
    delete layer;
  }
}

void ScopeLayer::PrintLayer(std::ofstream &ofstream, int num_tabs) {
  for (int i = 0; i < num_tabs; ++i) {
    ofstream << "\t";
  }
  ofstream << "layer {" << std::endl;
  for (auto symbol : values_) {
    for (int i = 0; i < num_tabs; ++i) {
      ofstream << "\t";
    }
    ofstream << "name: " << symbol.first.GetName() << std::endl;
    symbol.second->Print(ofstream, num_tabs);
    ofstream << std::endl;
  }
  for (int i = 0; i < num_tabs; ++i) {
    ofstream << "\t";
  }
  ofstream << "}" << std::endl;
  for (ScopeLayer* layer : children_) {
    layer->PrintLayer(ofstream, num_tabs + 1);
  }
}
