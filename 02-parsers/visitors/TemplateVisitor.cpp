#include "TemplateVisitor.h"
#include <objects/BasicObject.h>

template<typename T>
T TemplateVisitor<T>::Accept(BaseElement * element) {
  element->Accept(this);
  return tos_value_;
}

template BasicObject* TemplateVisitor<BasicObject*>::Accept(BaseElement* element);