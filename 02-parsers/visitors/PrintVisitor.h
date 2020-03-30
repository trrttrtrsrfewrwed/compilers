#pragma once

#include "Visitor.h"

#include <fstream>
#include <string>

class PrintVisitor: public Visitor {
public:
  PrintVisitor(const std::string& filename);
  ~PrintVisitor();
  void Visit(BinaryOperator* visited) override;
  void Visit(ClassDeclaration* visited) override;
  void Visit(ClassDeclarationList* visited) override;
  void Visit(CommonDeclaration* visited) override;
  void Visit(Declaration* visited) override;
  void Visit(DeclarationList* visited) override;
  void Visit(LocalVariableDeclaration* visited) override;
  void Visit(MethodDeclaration* visited) override;
  void Visit(VariableDeclaration* visited) override;
  void Visit(ArrayElementExpression* visited) override;
  void Visit(ArrayExpression* visited) override;
  void Visit(ArrayLengthExpression* visited) override;
  void Visit(BinaryExpression* visited) override;
  void Visit(BoolExpression* visited) override;
  void Visit(Expression* visited) override;
  void Visit(ExpressionList* visited) override;
  void Visit(IdentExpression* visited) override;
  void Visit(MethodInvokationExpression* visited) override;
  void Visit(NotExpression* visited) override;
  void Visit(NumberExpression* visited) override;
  void Visit(ObjectExpression* visited) override;
  void Visit(ParenthesesExpression* visited) override;
  void Visit(ThisExpression* visited) override;
  void Visit(FormalList* visited) override;
  void Visit(ArrayLvalue* visited) override;
  void Visit(SimpleLvalue* visited) override;
  void Visit(Lvalue* visited) override;
  void Visit(MainClass* visited) override;
  void Visit(Program* visited) override;
  void Visit(MethodInvokation* visited) override;
  void Visit(AssertStatement* visited) override;
  void Visit(DefinitionStatement* visited) override;
  void Visit(IfElseStatement* visited) override;
  void Visit(IfStatement* visited) override;
  void Visit(LocalVariableDeclarationStatement* visited) override;
  void Visit(MethodInvokationStatement* visited) override;
  void Visit(ReturnStatement* visited) override;
  void Visit(ScopeStatement* visited) override;
  void Visit(SoutStatement* visited) override;
  void Visit(Statement* visited) override;
  void Visit(StatementList* visited) override;
  void Visit(WhileStatement* visited) override;
  void Visit(ArrayType* visited) override;
  void Visit(SimpleType* visited) override;
  void Visit(Type* visited) override;
  void Visit(TypeIdentifier* visited) override;
  void Visit(BaseElement* visited) override;

private:
  void PrintTabs();
  std::ofstream stream_;
  int num_tabs_ = 0;

};