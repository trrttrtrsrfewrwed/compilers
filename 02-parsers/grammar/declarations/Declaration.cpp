#include "Declaration.h"

Declaration::Declaration(VariableDeclaration *var_decl) : decl_(var_decl) {
  decl_->is_method_decl_ = false;
}

Declaration::Declaration(MethodDeclaration *method_decl) : decl_(method_decl) {
  decl_->is_method_decl_ = true;
}

void Declaration::Accept(Visitor *visitor) { visitor->Visit(this); }