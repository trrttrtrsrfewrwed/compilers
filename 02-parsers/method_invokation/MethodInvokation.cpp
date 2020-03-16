#include "MethodInvokation.h"

MethodInvokation::MethodInvokation(Expression *obj, std::string func_name)
    : obj_(obj), func_name_(std::move(func_name)) {
  args_ = new ExpressionList();
}

MethodInvokation::MethodInvokation(Expression *obj, std::string func_name,
                                   Expression *first_arg,
                                   ExpressionList *following_args)
    : obj_(obj), func_name_(std::move(func_name)) {
  args_ = following_args;
  args_->AddExpression(first_arg);
}