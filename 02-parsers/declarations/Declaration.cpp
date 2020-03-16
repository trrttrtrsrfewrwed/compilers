#include "Declaration.h"

Declaration::Declaration(VariableDeclaration *var_decl): decl_(var_decl) {}

Declaration::Declaration(MethodDeclaration *method_decl): decl_(method_decl) {}