#pragma once

#include "ScopeLayer.h"

class ClassSymbolTree {
public:
  explicit ClassSymbolTree(ScopeLayer * root);
  ClassSymbolTree(const ClassSymbolTree &other);

  std::shared_ptr<BasicType> Get(Symbol symbol);
  ScopeLayer * root_;
  ~ClassSymbolTree();

  /**
   * Adds mapping from named scope for fast access
   * @param name - name of layer - method name
   * @param layer - scope layer to use
   */
  void AddMapping(Symbol name, ScopeLayer * layer, MethodDeclaration* decl);
  /**
   * Get function by name
   * @param name
   * @return Function scope
   */
  ScopeLayer * GetMethodScopeByName(Symbol name);
  MethodDeclaration * GetMethodBodyByName(Symbol name);

  void PrintTree(std::ofstream& ofstream);
private:
  std::unordered_map<Symbol, ScopeLayer *> layer_mapping_;
  std::unordered_map<Symbol, MethodDeclaration *> method_bodies_;
};