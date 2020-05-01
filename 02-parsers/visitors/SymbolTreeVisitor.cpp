#include "SymbolTreeVisitor.h"
#include <grammar/expressions/ArrayElementExpression.h>
#include <grammar/expressions/ArrayExpression.h>
#include <grammar/expressions/ArrayLengthExpression.h>
#include <grammar/expressions/BinaryExpression.h>
#include <grammar/expressions/ExpressionList.h>
#include <grammar/expressions/IdentExpression.h>
#include <grammar/expressions/MethodInvokationExpression.h>
#include <grammar/expressions/NotExpression.h>
#include <grammar/expressions/ObjectExpression.h>
#include <grammar/expressions/ParenthesesExpression.h>
#include <grammar/lvalues/ArrayLvalue.h>
#include <grammar/lvalues/SimpleLvalue.h>
#include <grammar/main_structures/Program.h>
#include <grammar/statements/AssertStatement.h>
#include <grammar/statements/DefinitionStatement.h>
#include <grammar/statements/IfElseStatement.h>
#include <grammar/statements/IfStatement.h>
#include <grammar/statements/LocalVariableDeclarationStatement.h>
#include <grammar/statements/MethodInvokationStatement.h>
#include <grammar/statements/ReturnStatement.h>
#include <grammar/statements/ScopeStatement.h>
#include <grammar/statements/SoutStatement.h>
#include <grammar/statements/WhileStatement.h>
#include <object_types/PrimitiveType.h>
#include <object_types/VoidType.h>

SymbolTreeVisitor::SymbolTreeVisitor() {}

void SymbolTreeVisitor::Visit(BinaryOperator *visited) {}

BasicType *SymbolTreeVisitor::GetBasicType(Type *type) {
  if (type->type_ == "int" || type->type_ == "boolean") {
    return new PrimitiveType(static_cast<TYPE>((type->type_ == "int") ? 0 : 1),
                             type->is_array_);
  } else {
    if (classes_.find(Symbol(type->type_)) == classes_.end()) {
      throw std::runtime_error("Class does not exist");
    } else {
      // std::cout << type->type_ << "\n";
      return new ObjectType(classes_[Symbol(type->type_)], type->is_array_);
    }
  }
}

ClassType *SymbolTreeVisitor::GetClassType(MainClass *visited) {
  std::vector<std::pair<BasicType *, std::string>> fields;
  std::vector<std::pair<BasicType *, std::string>> arguments;
  fields.emplace_back(new MethodType(arguments, new VoidType()), "main");
  return new ClassType(fields, visited->main_class_name_);
}

ClassType *SymbolTreeVisitor::GetClassType(ClassDeclaration *visited) {
  std::vector<std::pair<BasicType *, std::string>> fields;
  for (auto decl : visited->fields_->declarations_) {
    if (decl->decl_->is_method_decl_) {
      auto method_decl = dynamic_cast<MethodDeclaration *>(decl->decl_);
      BasicType *return_type;
      if (method_decl->return_type_->type_ == "void") {
        return_type = new VoidType();
      } else {
        return_type = GetBasicType(method_decl->return_type_);
      }
      std::vector<std::pair<BasicType *, std::string>> arguments;
      for (const auto &arg : method_decl->args_->args_) {
        arguments.emplace_back(GetBasicType(arg.first), arg.second);
      }
      auto method_type = new MethodType(arguments, return_type);
      fields.emplace_back(
          std::make_pair(method_type, method_decl->method_name_));
    } else {
      auto variable_decl = dynamic_cast<VariableDeclaration *>(decl->decl_);
      fields.emplace_back(std::make_pair(GetBasicType(variable_decl->type_),
                                         variable_decl->variable_name_));
    }
  }
  return new ClassType(fields, visited->class_name_);
}

void SymbolTreeVisitor::Visit(ClassDeclaration *visited) {
  if (classes_.find(Symbol(visited->class_name_)) != classes_.end()) {
    throw std::runtime_error("Class already declared");
  }
  classes_symbol_trees_[Symbol(visited->class_name_)] =
      new ClassSymbolTree(new ScopeLayer);
  current_layer_ = classes_symbol_trees_[Symbol(visited->class_name_)]->root_;
  current_class_ = classes_symbol_trees_[Symbol(visited->class_name_)];

  classes_[Symbol(visited->class_name_)] = GetClassType(visited);

  visited->fields_->Accept(this);
}

void SymbolTreeVisitor::Visit(ClassDeclarationList *visited) {
  for (auto class_declaration : visited->declarations_) {
    class_declaration->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(CommonDeclaration *visited) {}
void SymbolTreeVisitor::Visit(Declaration *visited) {}

void SymbolTreeVisitor::Visit(DeclarationList *visited) {
  for (auto declaration : visited->declarations_) {
    declaration->decl_->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(LocalVariableDeclaration *visited) {
  visited->variable_declaration_->Accept(this);
}
void SymbolTreeVisitor::Visit(MethodDeclaration *visited) {
  BasicType *return_type;
  if (visited->return_type_->type_ == "void") {
    return_type = new VoidType();
  } else {
    return_type = GetBasicType(visited->return_type_);
  }

  std::vector<std::pair<BasicType *, std::string>> arguments;
  for (const auto &arg : visited->args_->args_) {
    arguments.emplace_back(GetBasicType(arg.first), arg.second);
  }
  auto method_type = new MethodType(arguments, return_type);
  current_layer_->DeclareMethod(Symbol(visited->method_name_), method_type);

  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;

  visited->args_->Accept(this);
  visited->method_body_->Accept(this);

  current_class_->AddMapping(Symbol(visited->method_name_), new_layer, visited);

  current_layer_ = current_layer_->GetParent();

  // TODO(?)
  // functions_[Symbol(function->name_)] = function;
}

void SymbolTreeVisitor::Visit(VariableDeclaration *visited) {
  // std::cout << "Declaring var " << visited->variable_name_ << std::endl;
  if (visited->type_->type_ == "int" || visited->type_->type_ == "boolean") {
    current_layer_->DeclarePrimitive(Symbol(visited->variable_name_),
                                     visited->type_);
  } else {
    auto find_result = classes_.find(Symbol(visited->type_->type_));
    if (find_result == classes_.end()) {
      throw std::runtime_error("Class does not exist");
    } else {
      ClassType *type = find_result->second;
      current_layer_->DeclareObject(Symbol(visited->variable_name_), type,
                                    visited->type_->is_array_);
    }
  }
}
void SymbolTreeVisitor::Visit(ArrayElementExpression *visited) {
  visited->type_->Accept(this);
  visited->idx_->Accept(this);
}
void SymbolTreeVisitor::Visit(ArrayExpression *visited) {
  CheckType(visited->type_->GetType());
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(ArrayLengthExpression *visited) {
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(BinaryExpression *visited) {
  visited->first->Accept(this);
  visited->second->Accept(this);
}

void SymbolTreeVisitor::Visit(BoolExpression *visited) {
}
void SymbolTreeVisitor::Visit(Expression *visited) {
}
void SymbolTreeVisitor::Visit(ExpressionList *visited) {
  for (auto expr: visited->expressions_) {
    expr->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(IdentExpression *visited) {
  CheckName(visited->id_);
}
void SymbolTreeVisitor::Visit(MethodInvokationExpression *visited) {
  visited->method_invokation_->Accept(this);
}
void SymbolTreeVisitor::Visit(NotExpression *visited) {
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(NumberExpression *visited) {
}
void SymbolTreeVisitor::Visit(ObjectExpression *visited) {
  CheckType(visited->identifier_->GetTypeName());
}
void SymbolTreeVisitor::Visit(ParenthesesExpression *visited) {
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(ThisExpression *visited) {
}

void SymbolTreeVisitor::Visit(FormalList *visited) {
  for (const auto &arg : visited->args_) {
    if (arg.first->type_ == "int" || arg.first->type_ == "boolean") {
      current_layer_->DeclarePrimitive(Symbol(arg.second), arg.first);
    } else {
      if (classes_.find(Symbol(arg.first->type_)) == classes_.end()) {
        throw std::runtime_error("Class does not exist");
      } else {
        current_layer_->DeclareObject(Symbol(arg.second),
                                      classes_[Symbol(arg.first->type_)],
                                      arg.first->is_array_);
      }
    }
  }
}
void SymbolTreeVisitor::Visit(ArrayLvalue *visited) {
  CheckName(visited->id_);
  auto type = current_layer_->Get(Symbol(visited->id_));
  if (type->GetType() != "ObjectType" &&
      type->GetType() != "PrimitiveType") {
    throw std::runtime_error("Object has non object type\n");
  }
  if (type->GetType() == "ObjectType") {
    auto obj_type = std::dynamic_pointer_cast<ObjectType>(type);
    if (!obj_type->is_array_) {
      throw std::runtime_error("trying [] from non array\n");
    }
  }
  if (type->GetType() == "PrimitiveType") {
    auto obj_type = std::dynamic_pointer_cast<PrimitiveType>(type);
    if (!obj_type->is_array_) {
      throw std::runtime_error("trying [] from non array\n");
    }
  }
  visited->idx_->Accept(this);
}
void SymbolTreeVisitor::Visit(SimpleLvalue *visited) {
  CheckName(visited->id_);
}
void SymbolTreeVisitor::Visit(Lvalue *visited) {
}

void SymbolTreeVisitor::Visit(MainClass *visited) {
  if (classes_.find(Symbol(visited->main_class_name_)) != classes_.end()) {
    throw std::runtime_error("Class already declared");
  }
  classes_symbol_trees_[Symbol(visited->main_class_name_)] =
      new ClassSymbolTree(new ScopeLayer);
  current_layer_ =
      classes_symbol_trees_[Symbol(visited->main_class_name_)]->root_;
  current_class_ = classes_symbol_trees_[Symbol(visited->main_class_name_)];
  classes_[Symbol(visited->main_class_name_)] = GetClassType(visited);

  main_Class_ = visited;
  main_name_ = visited->main_class_name_;

  visited->statements_->Accept(this);
}

void SymbolTreeVisitor::Visit(Program *visited) {
  visited->class_declarations_->Accept(this);
  visited->main_class_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvokation *visited) {
  visited->obj_->Accept(this);
  visited->args_->Accept(this);
}
void SymbolTreeVisitor::Visit(AssertStatement *visited) {
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(DefinitionStatement *visited) {
  visited->lvalue_->Accept(this);
  visited->expr_->Accept(this);
}

void SymbolTreeVisitor::Visit(IfElseStatement *visited) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->if_statement_->Accept(this);
  current_layer_ = current_layer_->GetParent();

  new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->else_statement_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(IfStatement *visited) {
  // TODO(is new scope necessary?)
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->if_statement_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(LocalVariableDeclarationStatement *visited) {
  visited->lv_decl_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvokationStatement *visited) {
  visited->method_invokation_->Accept(this);
}
void SymbolTreeVisitor::Visit(ReturnStatement *visited) {
  visited->return_expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(ScopeStatement *visited) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->statements_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}
void SymbolTreeVisitor::Visit(SoutStatement *visited) {
  visited->expr_->Accept(this);
}
void SymbolTreeVisitor::Visit(Statement *visited) {}
void SymbolTreeVisitor::Visit(StatementList *visited) {
  for (auto statement : visited->statements_) {
    statement->Accept(this);
  }
}
void SymbolTreeVisitor::Visit(WhileStatement *visited) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->while_statement_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(ArrayType *visited) {}
void SymbolTreeVisitor::Visit(SimpleType *visited) {}
void SymbolTreeVisitor::Visit(Type *visited) {}
void SymbolTreeVisitor::Visit(TypeIdentifier *visited) {}
void SymbolTreeVisitor::Visit(BaseElement *visited) {}
ClassSymbolTree *SymbolTreeVisitor::GetMain() { return current_class_; }

void SymbolTreeVisitor::PrintTree(const std::string &filename) {
  stream_ = std::ofstream(filename);

  for (auto root : classes_symbol_trees_) {
    stream_ << "Class: " << root.first.GetName() << std::endl;
    stream_ << "---------Info-----------" << std::endl;
    if (classes_.find(root.first) != classes_.end()) {
      classes_[root.first]->Print(stream_, 0);
    } else {
      stream_ << "MainClass" << std::endl;
    }
    stream_ << "-------Info-end---------" << std::endl;
    root.second->PrintTree(stream_);
  }

  stream_.close();
}
void SymbolTreeVisitor::CheckType(std::string type) {
  if (type != "boolean" && type != "int" &&
      (classes_.find(Symbol(type)) == classes_.end())) {
    throw std::runtime_error("type check failde\n");
  }
}

void SymbolTreeVisitor::CheckName(std::string name) {
  // throws exception
  current_layer_->Get(Symbol(name));
}
MainClass* SymbolTreeVisitor::GetMainClass() {
  return main_Class_;
}

Symbol SymbolTreeVisitor::GetMainName() {
  return main_name_;
}
