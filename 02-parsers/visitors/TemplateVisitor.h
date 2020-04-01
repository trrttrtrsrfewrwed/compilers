#pragma once

#include <base_elements/BaseElement.h>

template<typename T>
class TemplateVisitor : public Visitor {
public:
  T Accept(BaseElement* element);
protected:
  T tos_value_;

};