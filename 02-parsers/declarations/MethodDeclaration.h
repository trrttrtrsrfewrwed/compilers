#pragma once
#include "CommonDeclaration.h"
#include "formals/FormalList.h"
#include "statements/StatementList.h"
#include "types/Type.h"
#include <string>

class MethodDeclaration: public CommonDeclaration {
public:
  MethodDeclaration(Type* return_type, std::string method_name, StatementList* method_body);
  MethodDeclaration(Type* return_type, std::string method_name, FormalList* args, StatementList* method_body);
private:
  Type* return_type_;
  std::string method_name_;
  StatementList* method_body_;
  FormalList* args_;
};

