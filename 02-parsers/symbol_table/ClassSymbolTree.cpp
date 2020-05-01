#include "ClassSymbolTree.h"

ClassSymbolTree::ClassSymbolTree(ScopeLayer * root) : root_(root) {}

ClassSymbolTree::~ClassSymbolTree() {

}

ClassSymbolTree::ClassSymbolTree(const ClassSymbolTree &other) {
  root_ = other.root_;
  layer_mapping_ = other.layer_mapping_;
}

void ClassSymbolTree::AddMapping(Symbol name, ScopeLayer *layer, MethodDeclaration* decl) {
  if (layer_mapping_.find(name) != layer_mapping_.end()) {
    throw std::runtime_error("Method has already been declared");
  }
  layer_mapping_[name] = layer;
  method_bodies_[name] = decl;
}

ScopeLayer *ClassSymbolTree::GetMethodScopeByName(Symbol name) {
  if (layer_mapping_.find(name) == layer_mapping_.end()) {
    throw std::runtime_error("No such method");
  }
  return layer_mapping_[name];
}

MethodDeclaration *ClassSymbolTree::GetMethodBodyByName(Symbol name) {
  if (method_bodies_.find(name) == method_bodies_.end()) {
    throw std::runtime_error("No such method");
  }
  return method_bodies_[name];
}

std::shared_ptr<BasicType> ClassSymbolTree::Get(Symbol symbol) {
  return root_->Get(symbol);
}

void ClassSymbolTree::PrintTree(std::ofstream &ofstream) {
  ofstream << "Printing tree: " << std::endl;
  root_->PrintLayer(ofstream, 0);
}
