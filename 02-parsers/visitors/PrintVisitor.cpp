#include "PrintVisitor.h"

#include "elements.h"

#include <iostream>

PrintVisitor::PrintVisitor(const std::string &filename) : stream_(filename) {}

void PrintVisitor::Visit(BinaryOperator *visited) {
  stream_ << "UNUSED!" << std::endl;
  PrintTabs();
  stream_ << "BinaryOperator:" << std::endl;
}
void PrintVisitor::Visit(ClassDeclaration *visited) {
  PrintTabs();
  stream_ << "ClassDeclaration:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "name: "  << std::endl;
  PrintTabs();
  stream_ << visited->class_name_ << std::endl;
  PrintTabs();
  stream_ << "parent: " << std::endl;
  PrintTabs();
  stream_  << visited->parent_name_ << std::endl;
  visited->fields_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ClassDeclarationList *visited) {
  PrintTabs();
  stream_ << "ClassDeclarationList:" << std::endl;
  ++num_tabs_;
  for (auto class_decl : visited->declarations_) {
    class_decl->Accept(this);
  }
  --num_tabs_;
}
void PrintVisitor::Visit(CommonDeclaration *visited) {
  stream_ << "UNUSED!" << std::endl;
  PrintTabs();
  stream_ << "CommonDeclaration:" << std::endl;
  ++num_tabs_;
  stream_ << "-no params-" << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(Declaration *visited) {
  PrintTabs();
  stream_ << "Declaration:" << std::endl;
  ++num_tabs_;
  visited->decl_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(DeclarationList *visited) {
  PrintTabs();
  stream_ << "DeclarationList:" << std::endl;
  ++num_tabs_;
  for (auto decl : visited->declarations_) {
    decl->Accept(this);
  }
  --num_tabs_;
}
void PrintVisitor::Visit(LocalVariableDeclaration *visited) {
  PrintTabs();
  stream_ << "LocalVariableDeclaration:" << std::endl;
  ++num_tabs_;
  visited->variable_declaration_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MethodDeclaration *visited) {
  PrintTabs();
  stream_ << "MethodDeclaration:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "method name: " << std::endl;
  PrintTabs();
  stream_  << visited->method_name_ << std::endl;
  PrintTabs();
  stream_ << "method body: " << std::endl;
  visited->method_body_->Accept(this);
  PrintTabs();
  stream_ << "return type: " << std::endl;
  visited->return_type_->Accept(this);
  PrintTabs();
  stream_ << "args: " << std::endl;
  visited->args_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(VariableDeclaration *visited) {
  PrintTabs();
  stream_ << "VariableDeclaration:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "variable name: "<< std::endl;
  PrintTabs();
  stream_  << visited->variable_name_ << std::endl;
  PrintTabs();
  stream_ << "type: " << std::endl;
  visited->type_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayElementExpression *visited) {
  PrintTabs();
  stream_ << "ArrayElementExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  visited->type_->Accept(this);
  PrintTabs();
  stream_ << "idx: " << std::endl;
  visited->idx_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayExpression *visited) {
  PrintTabs();
  stream_ << "ArrayElementExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  visited->type_->Accept(this);
  PrintTabs();
  stream_ << "size: " << std::endl;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayLengthExpression *visited) {
  PrintTabs();
  stream_ << "ArrayLengthExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "length: " << std::endl;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(BinaryExpression *visited) {
  PrintTabs();
  stream_ << "BinaryExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "first arg: " << std::endl;
  visited->first->Accept(this);
  PrintTabs();
  stream_ << "operation: " << std::endl;
  switch (visited->op_->get_operation()) {
  case AndOp:
    PrintTabs();
    stream_ << "&&" << std::endl;
    break;
  case OrOp:
    PrintTabs();
    stream_ << "||" << std::endl;
    break;
  case LessOp:
    PrintTabs();
    stream_ << "<" << std::endl;
    break;
  case GreaterOp:
    PrintTabs();
    stream_ << ">" << std::endl;
    break;
  case EqualOp:
    PrintTabs();
    stream_ << "==" << std::endl;
    break;
  case AddOp:
    PrintTabs();
    stream_ << "+" << std::endl;
    break;
  case SubtractOp:
    PrintTabs();
    stream_ << "-" << std::endl;
    break;
  case MultiplyOp:
    PrintTabs();
    stream_ << "*" << std::endl;
    break;
  case DivOp:
    PrintTabs();
    stream_ << "/" << std::endl;
    break;
  case ModOp:
    PrintTabs();
    stream_ << "%" << std::endl;
    break;
  }
  PrintTabs();
  stream_ << "second arg: " << std::endl;
  visited->second->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(BoolExpression *visited) {
  PrintTabs();
  stream_ << "BoolExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "value: "  << std::endl;
  PrintTabs();
  stream_ << visited->value_ << std::endl;
  --num_tabs_;
  PrintTabs();
}
void PrintVisitor::Visit(Expression *visited) {
  stream_ << "UNUSED!" << std::endl;
  PrintTabs();
  stream_ << "Expression:" << std::endl;
  ++num_tabs_;
  stream_ << "-no params-" << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(ExpressionList *visited) {
  PrintTabs();
  stream_ << "ExpressionList:" << std::endl;
  ++num_tabs_;
  for (auto expr : visited->expressions_) {
    expr->Accept(this);
  }
  --num_tabs_;
}
void PrintVisitor::Visit(IdentExpression *visited) {
  PrintTabs();
  stream_ << "IdentExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "id: " << std::endl;
  PrintTabs();
  stream_ << visited->id_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(MethodInvokationExpression *visited) {
  PrintTabs();
  stream_ << "MethodInvokationExpression:" << std::endl;
  ++num_tabs_;
  visited->method_invokation_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(NotExpression *visited) {
  PrintTabs();
  stream_ << "NotExpression:" << std::endl;
  ++num_tabs_;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(NumberExpression *visited) {
  PrintTabs();
  stream_ << "NumberExpression:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "value: "<< std::endl;
  PrintTabs();
  stream_  << visited->value_ << std::endl;
      --num_tabs_;
}
void PrintVisitor::Visit(ObjectExpression *visited) {
  PrintTabs();
  stream_ << "ObjectExpression:" << std::endl;
  ++num_tabs_;
  visited->identifier_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ParenthesesExpression *visited) {
  PrintTabs();
  stream_ << "ParenthesesExpression:" << std::endl;
  ++num_tabs_;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ThisExpression *visited) {
  PrintTabs();
  stream_ << "ThisExpression" << std::endl;
}
void PrintVisitor::Visit(FormalList *visited) {
  PrintTabs();
  stream_ << "FormalList:" << std::endl;
  ++num_tabs_;
  for (auto formal : visited->args_) {
    PrintTabs();
    stream_ << "type: " << std::endl;
    formal.first->Accept(this);
    PrintTabs();
    stream_ << "id: " << std::endl;
    PrintTabs();
    stream_ << formal.second << std::endl;
  }
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayLvalue *visited) {
  PrintTabs();
  stream_ << "ArrayLvalue:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "id: "  << std::endl;
  PrintTabs();
  stream_ << visited->id_ << std::endl;
  PrintTabs();
  stream_ << "idx: " << std::endl;
  visited->idx_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(SimpleLvalue *visited) {
  PrintTabs();
  stream_ << "SimpleLvalue:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "id: " << std::endl;
  PrintTabs();
  stream_ << visited->id_ << std::endl;
  --num_tabs_;
}
void PrintVisitor::Visit(Lvalue *visited) {
  stream_ << "UNUSED!" << std::endl;
  PrintTabs();
  stream_ << "Lvalue" << std::endl;
}
void PrintVisitor::Visit(MainClass *visited) {
  PrintTabs();
  stream_ << "MainClass:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "name: " << std::endl;
  PrintTabs();
  stream_ << visited->main_class_name_ << std::endl;
  visited->statements_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(Program *visited) {
  PrintTabs();
  stream_ << "Program is:" << std::endl;
  ++num_tabs_;
  visited->class_declarations_->Accept(this);
  visited->main_class_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MethodInvokation *visited) {
  PrintTabs();
  stream_ << "MethodInvocation:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "func name: " << std::endl;
  PrintTabs();
  stream_ << visited->func_name_ << std::endl;
  PrintTabs();
  stream_ << "args: " << std::endl;
  visited->args_->Accept(this);
  PrintTabs();
  stream_ << "object: " << std::endl;
  visited->obj_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(AssertStatement *visited) {
  PrintTabs();
  stream_ << "AssertStatement:" << std::endl;
  ++num_tabs_;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(DefinitionStatement *visited) {
  PrintTabs();
  stream_ << "DefinitionStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "lvalue: " << std::endl;
  visited->lvalue_->Accept(this);
  PrintTabs();
  stream_ << "expr: " << std::endl;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(IfElseStatement *visited) {
  PrintTabs();
  stream_ << "IfElseStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "query: " << std::endl;
  visited->query_->Accept(this);
  PrintTabs();
  stream_ << "if: " << std::endl;
  visited->if_statement_->Accept(this);
  PrintTabs();
  stream_ << "else: " << std::endl;
  visited->else_statement_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(IfStatement *visited) {
  PrintTabs();
  stream_ << "IfStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "query: " << std::endl;
  visited->query_->Accept(this);
  PrintTabs();
  stream_ << "if: " << std::endl;
  visited->if_statement_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(LocalVariableDeclarationStatement *visited) {
  PrintTabs();
  stream_ << "LocalVariableDeclarationStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "local var decl: " << std::endl;
  visited->lv_decl_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(MethodInvokationStatement *visited) {
  PrintTabs();
  stream_ << "MethodInvokationStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "method invokation: " << std::endl;
  visited->method_invokation_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ReturnStatement *visited) {
  PrintTabs();
  stream_ << "ReturnStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "return: " << std::endl;
  visited->return_expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ScopeStatement *visited) {
  PrintTabs();
  stream_ << "ScopeStatement:" << std::endl;
  ++num_tabs_;
  visited->statements_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(SoutStatement *visited) {
  PrintTabs();
  stream_ << "SoutStatement:" << std::endl;
  ++num_tabs_;
  visited->expr_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(Statement *visited) {
  stream_ << "UNUSED!" << std::endl;
  PrintTabs();
  stream_ << "Statement:" << std::endl;
}
void PrintVisitor::Visit(StatementList *visited) {
  PrintTabs();
  stream_ << "StatementList:" << std::endl;
  ++num_tabs_;
  for (auto statement : visited->statements_) {
    statement->Accept(this);
  }
  --num_tabs_;
}
void PrintVisitor::Visit(WhileStatement *visited) {
  PrintTabs();
  stream_ << "WhileStatement:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "query: " << std::endl;
  visited->query_->Accept(this);
  PrintTabs();
  stream_ << "while: " << std::endl;
  visited->while_statement_->Accept(this);
  --num_tabs_;
}
void PrintVisitor::Visit(ArrayType *visited) {
  PrintTabs();
  stream_ << "ArrayType:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  PrintTabs();
  stream_ << visited->GetType() << std::endl;
  --num_tabs_;
}

void PrintVisitor::Visit(SimpleType *visited) {
  PrintTabs();
  stream_ << "SimpleType:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  PrintTabs();
  stream_ << visited->GetType() << std::endl;
  --num_tabs_;
}

void PrintVisitor::Visit(Type *visited) {
  PrintTabs();
  stream_ << "Type:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  PrintTabs();
  stream_ << visited->type_ << std::endl;
  PrintTabs();
  stream_ << "is array: " << std::endl;
  PrintTabs();
  stream_ << visited->is_array_ << std::endl;
  --num_tabs_;
}

void PrintVisitor::Visit(TypeIdentifier *visited) {
  PrintTabs();
  stream_ << "TypeIdentifier:" << std::endl;
  ++num_tabs_;
  PrintTabs();
  stream_ << "type: " << std::endl;
  PrintTabs();
  stream_ << visited->GetTypeName() << std::endl;
  --num_tabs_;
}

void PrintVisitor::Visit(BaseElement *visited) { PrintTabs(); }

void PrintVisitor::PrintTabs() {
  for (int i = 0; i < num_tabs_; ++i) {
    stream_ << '\t';
  }
}

PrintVisitor::~PrintVisitor() { stream_.close(); }