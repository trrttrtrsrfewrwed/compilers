#include "MethodDeclaration.h"

MethodDeclaration::MethodDeclaration(Type *return_type, std::string method_name,
                                     StatementList *method_body)
    : return_type_(return_type), method_name_(std::move(method_name)),
      method_body_(method_body) {}
MethodDeclaration::MethodDeclaration(Type *return_type, std::string method_name,
                                     FormalList *args,
                                     StatementList *method_body)
    : return_type_(return_type), method_name_(std::move(method_name)),
      args_(args), method_body_(method_body) {}

void MethodDeclaration::Accept(Visitor *visitor) {
  visitor->Visit(this);
}