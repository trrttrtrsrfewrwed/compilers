#include "SymbolTreeVisitor.h"
#include <main_structures/Program.h>
#include <objects/PrimitiveType.h>
#include <statements/IfElseStatement.h>
#include <statements/IfStatement.h>
#include <statements/LocalVariableDeclarationStatement.h>
#include <statements/ScopeStatement.h>
#include <statements/WhileStatement.h>

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
      return new ObjectType(classes_[Symbol(type->type_)], type->is_array_);
    }
  }
}

ClassType *SymbolTreeVisitor::GetClassType(ClassDeclaration *visited) {
  std::vector<std::pair<BasicType *, std::string>> fields;
  for (auto decl : visited->fields_->declarations_) {
    if (decl->decl_->is_method_decl_) {
      auto method_decl = dynamic_cast<MethodDeclaration *>(decl->decl_);
      auto return_type = GetBasicType(method_decl->return_type_);

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
  return new ClassType(fields);
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
void SymbolTreeVisitor::Visit(CommonDeclaration *visited) {
}
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
  auto return_type = GetBasicType(visited->return_type_);

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

  current_class_->AddMapping(Symbol(visited->method_name_), new_layer);

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
void SymbolTreeVisitor::Visit(ArrayElementExpression *visited) {}
void SymbolTreeVisitor::Visit(ArrayExpression *visited) {}
void SymbolTreeVisitor::Visit(ArrayLengthExpression *visited) {}
void SymbolTreeVisitor::Visit(BinaryExpression *visited) {}
void SymbolTreeVisitor::Visit(BoolExpression *visited) {}
void SymbolTreeVisitor::Visit(Expression *visited) {}
void SymbolTreeVisitor::Visit(ExpressionList *visited) {}
void SymbolTreeVisitor::Visit(IdentExpression *visited) {}
void SymbolTreeVisitor::Visit(MethodInvokationExpression *visited) {}
void SymbolTreeVisitor::Visit(NotExpression *visited) {}
void SymbolTreeVisitor::Visit(NumberExpression *visited) {}
void SymbolTreeVisitor::Visit(ObjectExpression *visited) {}
void SymbolTreeVisitor::Visit(ParenthesesExpression *visited) {}
void SymbolTreeVisitor::Visit(ThisExpression *visited) {}
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
void SymbolTreeVisitor::Visit(ArrayLvalue *visited) {}
void SymbolTreeVisitor::Visit(SimpleLvalue *visited) {}
void SymbolTreeVisitor::Visit(Lvalue *visited) {}

void SymbolTreeVisitor::Visit(MainClass *visited) {
  if (classes_.find(Symbol(visited->main_class_name_)) != classes_.end()) {
    throw std::runtime_error("Class already declared");
  }
  classes_symbol_trees_[Symbol(visited->main_class_name_)] =
      new ClassSymbolTree(new ScopeLayer);
  current_layer_ =
      classes_symbol_trees_[Symbol(visited->main_class_name_)]->root_;
  current_class_  = classes_symbol_trees_[Symbol(visited->main_class_name_)];

  // TODO(Если нужно, захардкодить СlassType для MainClass'a)
  // classes_[Symbol(visited->main_class_name_)] = GetClassType(visited);

  visited->statements_->Accept(this);
}

void SymbolTreeVisitor::Visit(Program *visited) {
  visited->class_declarations_->Accept(this);
  visited->main_class_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvokation *visited) {}
void SymbolTreeVisitor::Visit(AssertStatement *visited) {}
void SymbolTreeVisitor::Visit(DefinitionStatement *visited) {}

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
  //TODO(is new scope necessary?)
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->if_statement_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}

void SymbolTreeVisitor::Visit(LocalVariableDeclarationStatement *visited) {
  visited->lv_decl_->Accept(this);
}

void SymbolTreeVisitor::Visit(MethodInvokationStatement *visited) {}
void SymbolTreeVisitor::Visit(ReturnStatement *visited) {}
void SymbolTreeVisitor::Visit(ScopeStatement *visited) {
  auto new_layer = new ScopeLayer(current_layer_);

  current_layer_ = new_layer;
  visited->statements_->Accept(this);
  current_layer_ = current_layer_->GetParent();
}
void SymbolTreeVisitor::Visit(SoutStatement *visited) {}
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

  for (auto root: classes_symbol_trees_) {
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
