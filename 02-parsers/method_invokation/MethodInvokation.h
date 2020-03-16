#pragma once

#include <expressions/Expression.h>
#include <expressions/ExpressionList.h>
#include <string>
class MethodInvokation {
public:
  MethodInvokation(Expression *obj, std::string func_name);
  MethodInvokation(Expression *obj, std::string func_name,
                   Expression *first_arg, ExpressionList *following_args);
private:
  Expression* obj_;
  std::string func_name_;
  ExpressionList* args_;
};
