#pragma once

#include "Symbol.h"
#include "object_types/BasicType.h"
#include <memory>
#include <object_types/ObjectType.h>
#include <grammar/types/Type.h>
#include <unordered_map>
#include <vector>

class ScopeLayer {
public:
  explicit ScopeLayer(ScopeLayer * parent);
  ScopeLayer();
  void DeclarePrimitive(Symbol symbol, Type* type);
  void DeclareMethod(Symbol symbol, MethodType* type);
  void DeclareObject(Symbol symbol, ClassType* type, bool is_array);
  void Put(Symbol symbol, std::shared_ptr<BasicType> value);
  std::shared_ptr<BasicType> Get(Symbol symbol);
  bool Has(Symbol symbol);

  void AddChild(ScopeLayer * child);
  // void AttachParent();
  ~ScopeLayer();

  ScopeLayer * GetChild(size_t index);
  ScopeLayer * GetParent() const;

  void PrintLayer(std::ofstream& ofstream, int num_tabs);
private:
  std::unordered_map<Symbol, std::shared_ptr<BasicType>> values_;
  ScopeLayer * parent_;
  std::vector<ScopeLayer * > children_;
};
