#include "TemplateVisitor.h"
#include <irtree/tree_wrapper/SubtreeWrapper.h>
#include <objects/BasicObject.h>

template<typename T>
T TemplateVisitor<T>::Accept(BaseElement * element) {
  element->Accept(this);
  return tos_value_;
}

template BasicObject* TemplateVisitor<BasicObject*>::Accept(BaseElement* element);

template IRT::SubtreeWrapper* TemplateVisitor<IRT::SubtreeWrapper*>::Accept(BaseElement* element);

template std::string TemplateVisitor<std::string>::Accept(BaseElement* element);