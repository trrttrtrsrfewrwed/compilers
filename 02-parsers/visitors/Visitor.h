#pragma once
#include "forward_decl.h"

class Visitor {
public:
  virtual void Visit(BinaryOperator* visited) = 0;
  virtual void Visit(ClassDeclaration* visited) = 0;
  virtual void Visit(ClassDeclarationList* visited) = 0;
  virtual void Visit(CommonDeclaration* visited) = 0;
  virtual void Visit(Declaration* visited) = 0;
  virtual void Visit(DeclarationList* visited) = 0;
  virtual void Visit(LocalVariableDeclaration* visited) = 0;
  virtual void Visit(MethodDeclaration* visited) = 0;
  virtual void Visit(VariableDeclaration* visited) = 0;
  virtual void Visit(ArrayElementExpression* visited) = 0;
  virtual void Visit(ArrayExpression* visited) = 0;
  virtual void Visit(ArrayLengthExpression* visited) = 0;
  virtual void Visit(BinaryExpression* visited) = 0;
  virtual void Visit(BoolExpression* visited) = 0;
  virtual void Visit(Expression* visited) = 0;
  virtual void Visit(ExpressionList* visited) = 0;
  virtual void Visit(IdentExpression* visited) = 0;
  virtual void Visit(MethodInvokationExpression* visited) = 0;
  virtual void Visit(NotExpression* visited) = 0;
  virtual void Visit(NumberExpression* visited) = 0;
  virtual void Visit(ObjectExpression* visited) = 0;
  virtual void Visit(ParenthesesExpression* visited) = 0;
  virtual void Visit(ThisExpression* visited) = 0;
  virtual void Visit(FormalList* visited) = 0;
  virtual void Visit(ArrayLvalue* visited) = 0;
  virtual void Visit(SimpleLvalue* visited) = 0;
  virtual void Visit(Lvalue* visited) = 0;
  virtual void Visit(MainClass* visited) = 0;
  virtual void Visit(Program* visited) = 0;
  virtual void Visit(MethodInvokation* visited) = 0;
  virtual void Visit(AssertStatement* visited) = 0;
  virtual void Visit(DefinitionStatement* visited) = 0;
  virtual void Visit(IfElseStatement* visited) = 0;
  virtual void Visit(IfStatement* visited) = 0;
  virtual void Visit(LocalVariableDeclarationStatement* visited) = 0;
  virtual void Visit(MethodInvokationStatement* visited) = 0;
  virtual void Visit(ReturnStatement* visited) = 0;
  virtual void Visit(ScopeStatement* visited) = 0;
  virtual void Visit(SoutStatement* visited) = 0;
  virtual void Visit(Statement* visited) = 0;
  virtual void Visit(StatementList* visited) = 0;
  virtual void Visit(WhileStatement* visited) = 0;
  virtual void Visit(ArrayType* visited) = 0;
  virtual void Visit(SimpleType* visited) = 0;
  virtual void Visit(Type* visited) = 0;
  virtual void Visit(TypeIdentifier* visited) = 0;
  virtual void Visit(BaseElement* visited) = 0;
};
