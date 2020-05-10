#include "MethodCallVisitor.h"
#include <grammar/declarations/MethodDeclaration.h>
#include <grammar/declarations/VariableDeclaration.h>
#include <grammar/expressions/ArrayElementExpression.h>
#include <grammar/expressions/ArrayExpression.h>
#include <grammar/expressions/BinaryExpression.h>
#include <grammar/expressions/BoolExpression.h>
#include <grammar/expressions/IdentExpression.h>
#include <grammar/expressions/MethodInvokationExpression.h>
#include <grammar/expressions/NotExpression.h>
#include <grammar/expressions/NumberExpression.h>
#include <grammar/expressions/ObjectExpression.h>
#include <grammar/expressions/ParenthesesExpression.h>
#include <grammar/formals/FormalList.h>
#include <grammar/lvalues/ArrayLvalue.h>
#include <grammar/main_structures/MainClass.h>
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
#include <objects/Array.h>
#include <objects/Object.h>

BasicType *MethodCallVisitor::GetBasicType(Type *type) {
  return symbol_tree_visitor_->GetBasicType(type);
}

MethodCallVisitor::MethodCallVisitor(ScopeLayer *function_scope,
                                     BasicObject *object, MethodType *type)
    : root_layer(function_scope), frame(type->argument_names_.size()),
      object_(object) {
  current_layer_ = root_layer;
  offsets_.push(0);
  SetFields(object);
}

void MethodCallVisitor::SetFields(BasicObject *object) {
  // TODO( @trrttrtrsrfewrwed) Исходя из грамматики при обращении к полям
  // объекта не нужно писать this. Непонятно, что лучше - передать в качестве
  // параметра в метод один аргумент this или все поля, пока выбран 2 вариант
  std::vector<BasicObject *> fields;
  int index = -1;
  for (const auto &field : object->GetFieldValues()) {
    fields.push_back(field.second);
    table_.CreateVariable(field.first);
    table_.Put(field.first, index);
    --index;
  }
  frame.SetFields(fields);
}

void MethodCallVisitor::SetParams(const std::vector<BasicObject *> &params) {
  frame.SetParams(params);
}

FrameEmulator &MethodCallVisitor::GetFrame() { return frame; }

void MethodCallVisitor::Visit(BinaryOperator *visited) {}

void MethodCallVisitor::Visit(ClassDeclaration *visited) {}

void MethodCallVisitor::Visit(ClassDeclarationList *visited) {}

void MethodCallVisitor::Visit(CommonDeclaration *visited) {}

void MethodCallVisitor::Visit(Declaration *visited) {}

void MethodCallVisitor::Visit(DeclarationList *visited) {}

void MethodCallVisitor::Visit(LocalVariableDeclaration *visited) {
  visited->variable_declaration_->Accept(this);
}

void MethodCallVisitor::Visit(MethodDeclaration *visited) {
  visited->args_->Accept(this);
  visited->method_body_->Accept(this);
}

void MethodCallVisitor::Visit(VariableDeclaration *visited) {
  if  (visited->type_->is_array_) {
    size_t index = frame.AllocArray(GetBasicType(visited->type_));
    table_.CreateVariable(Symbol(visited->variable_name_));
    table_.Put(Symbol(visited->variable_name_), index);
  } else {
    size_t index = frame.AllocVariable(GetBasicType(visited->type_));
    table_.CreateVariable(Symbol(visited->variable_name_));
    table_.Put(Symbol(visited->variable_name_), index);
  }
}

void MethodCallVisitor::Visit(ArrayElementExpression *visited) {
  int index = Accept(visited->idx_)->GetValue();
  tos_value_ = dynamic_cast<Array*>(Accept(visited->type_))->GetValue(index);
}

void MethodCallVisitor::Visit(ArrayExpression *visited) {
  auto array = new Array(GetBasicType(new Type(visited->type_)));
  size_t size = Accept(visited->expr_)->GetValue();
  array->SetSize(size);
  tos_value_ = array;
}

void MethodCallVisitor::Visit(ArrayLengthExpression *visited) {}

void MethodCallVisitor::Visit(BinaryExpression *visited) {
  auto left = Accept(visited->first);
  auto right = Accept(visited->second);
  TYPE result_type;
  try {
    auto primitive_left_type = dynamic_cast<PrimitiveType *>(left->GetType());
    auto primitive_right_type = dynamic_cast<PrimitiveType *>(right->GetType());
    TYPE left_type = primitive_left_type->type_;
    TYPE right_type = primitive_right_type->type_;
    if ((left_type != 0 && left_type != 1) ||
        (right_type != 0 && right_type != 1)) {
      throw std::runtime_error("");
    }
    if (left_type == 1 && right_type == 1) {
      result_type = static_cast<TYPE>(1);
    } else {
      result_type = static_cast<TYPE>(0);
    }
  } catch (...) {
    throw std::runtime_error(
        "trying to execute binary operation with non primitive objects\n");
  }
  int result = 0;
  switch (visited->op_->get_operation()) {
  case AndOp:
    result = left->GetValue() && right->GetValue();
    break;
  case OrOp:
    result = left->GetValue() || right->GetValue();
    break;
  case LessOp:
    result = left->GetValue() < right->GetValue();
    break;
  case GreaterOp:
    result = left->GetValue() > right->GetValue();
    break;
  case EqualOp:
    result = left->GetValue() == right->GetValue();
    break;
  case AddOp:
    result = left->GetValue() + right->GetValue();
    break;
  case SubtractOp:
    result = left->GetValue() - right->GetValue();
    break;
  case MultiplyOp:
    result = left->GetValue() * right->GetValue();
    break;
  case DivOp:
    result = left->GetValue() / right->GetValue();
    break;
  case ModOp:
    result = left->GetValue() % right->GetValue();
    break;
  default:
    throw std::runtime_error("Exception in BinaryExpression::eval()");
  }
  tos_value_ = new Object(new PrimitiveType(result_type, false), result);
}

void MethodCallVisitor::Visit(BoolExpression *visited) {
  tos_value_ = new Object(new PrimitiveType(static_cast<TYPE>(1), false),
                               visited->value_);
}

void MethodCallVisitor::Visit(ExpressionList *visited) {
  // logic is realized in Visit(MethodInvokation*)
}

void MethodCallVisitor::Visit(IdentExpression *visited) {
  int index = table_.Get(Symbol(visited->id_));
  tos_value_ = frame.Get(index);
}

void MethodCallVisitor::Visit(MethodInvokationExpression *visited) {
  tos_value_ = Accept(visited->method_invokation_);
}

void MethodCallVisitor::Visit(NotExpression *visited) {
  int not_value;
  if (Accept(visited->expr_)) {
    not_value = 0;
  } else {
    not_value = 1;
  }
  tos_value_ = new Object(new PrimitiveType(static_cast<TYPE>(0), false),
                               not_value);
}

void MethodCallVisitor::Visit(NumberExpression *visited) {
  tos_value_ = new Object(new PrimitiveType(static_cast<TYPE>(0), false),
                               visited->value_);
}

void MethodCallVisitor::Visit(ObjectExpression *visited) {
  tos_value_ = new Object(new ObjectType(
      symbol_tree_visitor_->classes_[visited->identifier_->GetTypeName()]));
}

void MethodCallVisitor::Visit(ParenthesesExpression *visited) {
  tos_value_ = Accept(visited->expr_);
}

void MethodCallVisitor::Visit(ThisExpression *visited) { tos_value_ = object_; }

void MethodCallVisitor::Visit(FormalList *visited) {
  int index = -(int)frame.GetFieldsSize() - 1;
  for (const auto &param : visited->args_) {
    table_.CreateVariable(Symbol(param.second));
    table_.Put(Symbol(param.second), index);
    --index;
  }
}

void MethodCallVisitor::Visit(ArrayLvalue *visited) {
  tos_value_ = Accept(visited->idx_);
}

void MethodCallVisitor::Visit(SimpleLvalue *visited) {}

void MethodCallVisitor::Visit(Lvalue *visited) {}

void MethodCallVisitor::Visit(MainClass *visited) {
  visited->statements_->Accept(this);
}

void MethodCallVisitor::Visit(Program *visited) {}

void MethodCallVisitor::Visit(MethodInvokation *visited) {
  std::cout << "Function called " << visited->func_name_ << std::endl;
  BasicObject *object = Accept(visited->obj_);
  ScopeLayer *scope;
  MethodType *func_type;
  ClassSymbolTree *tree;
  try {
    auto *obj_type = dynamic_cast<ObjectType *>(object->GetType());
    tree = symbol_tree_visitor_->classes_symbol_trees_[obj_type->GetTypeName()];
    scope = tree->GetMethodScopeByName(visited->func_name_);


    // Printing Function Scope into file lol.txt
    auto stream_ = std::ofstream("lol.txt");
    scope->PrintLayer(stream_, 0);
    //

    for (size_t i = 0; i < obj_type->field_names_.size(); ++i) {
      if (obj_type->field_names_[i] == visited->func_name_) {
        func_type = dynamic_cast<MethodType *>(obj_type->field_types_[i]);
        break;
      }
    }
  } catch (...) {
    throw std::runtime_error("there is no such function\n");
  }

  std::vector<BasicObject *> params;

  for (auto param : visited->args_->expressions_) {
    params.push_back(Accept(param));
  }

  MethodCallVisitor new_visitor(scope, object, func_type);

  new_visitor.SetParams(params);

  new_visitor.GetFrame().SetParentFrame(&frame);

  new_visitor.symbol_tree_visitor_ = symbol_tree_visitor_;

  new_visitor.Visit(tree->GetMethodBodyByName(visited->func_name_));

  tos_value_ = frame.GetReturnValue();
}

void MethodCallVisitor::Visit(AssertStatement *visited) {
  if (!Accept(visited->expr_)->GetValue()) {
   throw std::runtime_error("Assertion failed\n");
  }
}

void MethodCallVisitor::Visit(DefinitionStatement *visited) {
  BasicObject *value = Accept(visited->expr_);
  if (visited->lvalue_->is_array_) {
    int idx = Accept(visited->lvalue_)->GetValue();
    int index = table_.Get(Symbol(visited->lvalue_->id_));
    dynamic_cast<Array*>(frame.Get(index))->SetValueAtIndex(idx, value);
  }
  else {
    int index = table_.Get(Symbol(visited->lvalue_->id_));
    frame.Set(index, value);
  }
}

void MethodCallVisitor::Visit(IfElseStatement *visited) {
  BasicObject* query_result = Accept(visited->query_);
  if (query_result->GetValue() == 1) {
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();
    visited->if_statement_->Accept(this);
    offsets_.pop();
    size_t index = offsets_.top();
    offsets_.pop();
    offsets_.push(index + 2); // skip else child
    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
  } else {
    int value = offsets_.top();

    offsets_.push(0);

    current_layer_ = current_layer_->GetChild(value + 1); // else layer
    frame.AllocScope();
    table_.BeginScope();
    visited->else_statement_->Accept(this);
    offsets_.pop();
    offsets_.pop();
    offsets_.push(value + 2);

    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
  }
}

void MethodCallVisitor::Visit(IfStatement *visited) {
  BasicObject* query_result = Accept(visited->query_);
  if (query_result->GetValue() == 1) {
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();
    visited->if_statement_->Accept(this);
    offsets_.pop();
    size_t index = offsets_.top();
    offsets_.pop();
    offsets_.push(index + 1);
    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
  }
}

void MethodCallVisitor::Visit(LocalVariableDeclarationStatement *visited) {
  visited->lv_decl_->Accept(this);
}

void MethodCallVisitor::Visit(MethodInvokationStatement *visited) {
  // TODO we don't update tos_value in this case. It s a big question
  // if this invokation has any influence or not. I don't remember it
  visited->method_invokation_->Accept(this);
}

void MethodCallVisitor::Visit(ReturnStatement *visited) {
  if (frame.HasParent()) {
    frame.SetParentReturnValue(Accept(visited->return_expr_));
  }
  returned_ = true;
}

void MethodCallVisitor::Visit(ScopeStatement *visited) {
  current_layer_ = current_layer_->GetChild(offsets_.top());

  offsets_.push(0);
  frame.AllocScope();
  table_.BeginScope();
  visited->statements_->Accept(this);

  offsets_.pop();
  size_t index = offsets_.top();

  offsets_.pop();
  offsets_.push(index + 1);

  current_layer_ = current_layer_->GetParent();
  frame.DeallocScope();
  table_.EndScope();
}

void MethodCallVisitor::Visit(SoutStatement *visited) {
  auto value = Accept(visited->expr_);

  // TODO(@trrttrtrsrfewrwed it was said that we can only print integers,
  // but I can print other objects too)
  std::cout << value->GetValue() << std::endl;
}

void MethodCallVisitor::Visit(Statement *visited) {}

void MethodCallVisitor::Visit(StatementList *visited) {
  for (auto statement : visited->statements_) {
    if (!returned_) {
      statement->Accept(this);
    }
  }
}

void MethodCallVisitor::Visit(WhileStatement *visited) {
  while (Accept(visited->query_)->GetValue()) {
    current_layer_ = current_layer_->GetChild(offsets_.top());
    offsets_.push(0);
    frame.AllocScope();
    table_.BeginScope();
    visited->while_statement_->Accept(this);
    offsets_.pop();
    //size_t index = offsets_.top();
    //offsets_.pop();
    //offsets_.push(index);
    current_layer_ = current_layer_->GetParent();
    frame.DeallocScope();
    table_.EndScope();
  }
  size_t index = offsets_.top();
  offsets_.pop();
  offsets_.push(index + 1);
}

void MethodCallVisitor::Visit(ArrayType *visited) {}

void MethodCallVisitor::Visit(SimpleType *visited) {}

void MethodCallVisitor::Visit(Type *visited) {}

void MethodCallVisitor::Visit(TypeIdentifier *visited) {}

void MethodCallVisitor::Visit(BaseElement *visited) {}

void MethodCallVisitor::Visit(Expression *expression) {}
void MethodCallVisitor::SetSymbolTreeVisitor(
    SymbolTreeVisitor *symbol_tree_visitor) {
  symbol_tree_visitor_ = symbol_tree_visitor;
}
