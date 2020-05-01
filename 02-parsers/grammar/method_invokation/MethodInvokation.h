#pragma once

#include <grammar/expressions/Expression.h>
#include <grammar/expressions/ExpressionList.h>
#include <string>
class MethodInvokation: public BaseElement{
public:
  MethodInvokation(Expression *obj, std::string func_name);
  MethodInvokation(Expression *obj, std::string func_name,
                   Expression *first_arg, ExpressionList *following_args);
  void Accept(Visitor* visitor);
  Expression* obj_;
  std::string func_name_;
  ExpressionList* args_;
};
