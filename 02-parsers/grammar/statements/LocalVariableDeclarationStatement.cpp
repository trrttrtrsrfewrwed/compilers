#include "LocalVariableDeclarationStatement.h"

LocalVariableDeclarationStatement::LocalVariableDeclarationStatement(
    LocalVariableDeclaration *lv_decl): lv_decl_(lv_decl) {}

void LocalVariableDeclarationStatement::Accept(Visitor *visitor) {
  visitor->Visit(this);
}