//
// Created by timur on 05.05.2020.
//
#include "IrtreeBuildVisitor.h"
#include "elements.h"
#include <function_mechanisms/struct_initialization/StructInitialization.h>
#include <grammar/expressions/NotExpression.h>
#include <grammar/expressions/NumberExpression.h>
#include <irtree/generators/Temporary.h>
#include <irtree/nodes/ExpressionList.h>
#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/CallExpression.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>
#include <irtree/nodes/expressions/NameExpression.h>
#include <irtree/nodes/expressions/TempExpression.h>
#include <irtree/nodes/statements/JumpStatement.h>
#include <irtree/nodes/statements/LabelStatement.h>
#include <irtree/nodes/statements/MoveStatement.h>
#include <irtree/nodes/statements/SeqStatement.h>
#include <irtree/tree_wrapper/ExpressionWrapper.h>
#include <irtree/tree_wrapper/StatementWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/AndConditionalWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/NegateConditionalWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/OrConditionalWrapper.h>
#include <irtree/tree_wrapper/conditional_wrappers/RelativeConditionalWrapper.h>
#include <irtree/types/BinaryOperatorType.h>
#include <irtree/types/LogicOperatorType.h>
#include <object_types/VoidType.h>

BasicType *IrtreeBuildVisitor::GetBasicType(Type *type) {
  return symbol_tree_visitor_->GetBasicType(type);
}

void IrtreeBuildVisitor::Visit(BinaryOperator *visited) {}

void IrtreeBuildVisitor::Visit(ClassDeclaration *visited) {
  current_tree_ =
      symbol_tree_visitor_->classes_symbol_trees_[visited->class_name_];
  current_class_name_ = visited->class_name_;
  visited->fields_->Accept(this);
}

void IrtreeBuildVisitor::Visit(ClassDeclarationList *visited) {
  for (auto class_decl : visited->declarations_) {
    class_decl->Accept(this);
  }
}

void IrtreeBuildVisitor::Visit(CommonDeclaration *visited) {
}

void IrtreeBuildVisitor::Visit(Declaration *visited) {
  visited->decl_->Accept(this);
}

void IrtreeBuildVisitor::Visit(DeclarationList *visited) {
  for (auto field : visited->declarations_) {
    if (field->decl_->is_method_decl_) {
      while (!offsets_.empty()) {
        offsets_.pop();
      }
      dynamic_cast<MethodDeclaration*>(field->decl_)->Accept(this);
    }
  }
}

void IrtreeBuildVisitor::Visit(LocalVariableDeclaration *visited) {}

void IrtreeBuildVisitor::Visit(FormalList *visited) {
  current_frame_->AddArgumentAddress("this");
  for (auto param : visited->args_) {
    current_frame_->AddArgumentAddress(param.second);
  }
}

void IrtreeBuildVisitor::Visit(MethodDeclaration *visited) {
  current_layer_ = current_tree_->GetMethodScopeByName(visited->method_name_);
  offsets_.push(0);
  // build new frame
  std::string full_method_name =
      current_class_name_ + "::" + visited->method_name_;

  current_frame_ = new IRT::FrameTranslator(
      full_method_name, symbol_tree_visitor_->classes_[current_class_name_]);
  frame_translator_[full_method_name] = current_frame_;

  visited->args_->Accept(this);

  current_frame_->AddReturnAddress();

  BasicType* basic_type;

  if (visited->return_type_->type_ == "void") {
    basic_type = new VoidType();
  } else {
    basic_type = GetBasicType(visited->return_type_);
  }
  /*IRT::Statement *return_value_init = nullptr;
  if (basic_type->GetType() == "ObjectType") {
    auto expr = current_frame_->GetAddress("::return_value");

    IRT::Expression *value = CreateStruct(GetBasicType(visited->return_type_));
    return_value_init = new IRT::MoveStatement(expr, value);
  }*/

  auto statements_ir = Accept(visited->method_body_);

  IRT::Statement *func_start =
      new IRT::LabelStatement(IRT::Label(full_method_name));
  /*if (return_value_init) {
    func_start = new IRT::SeqStatement(func_start, return_value_init);
  }*/

  if (statements_ir) {

    tos_value_ = new IRT::StatementWrapper(
        new IRT::SeqStatement(func_start, statements_ir->ToStatement()));
  } else {
    throw std::runtime_error(
        "Missing function body is not allowed in Mini-Java");
  }

  method_trees_.emplace(full_method_name, tos_value_->ToStatement());
}

void IrtreeBuildVisitor::Visit(VariableDeclaration *visited) {
  tos_value_ = nullptr;
  if (visited->type_->is_array_) {
    current_frame_->AddLocalArray(visited->variable_name_);
  } else {
    current_frame_->AddLocalVariable(visited->variable_name_);

    auto basic_type = GetBasicType(visited->type_);
    if (basic_type->GetType() == "ObjectType") {
      auto expr = current_frame_->GetAddress(visited->variable_name_);

      IRT::Expression *value = CreateStruct(GetBasicType(visited->type_));
      tos_value_ =
          new IRT::StatementWrapper(new IRT::MoveStatement(expr, value));
    }
  }
}

void IrtreeBuildVisitor::Visit(ArrayElementExpression *visited) {
  IRT::Expression *var_expression = Accept(visited->type_)->ToExpression();

  auto idx = Accept(visited->idx_)->ToExpression();

  IRT::Expression *offset_expression = new IRT::BinopExpression(
      IRT::BinaryOperatorType::PLUS, var_expression,
      // TODO(@trrttrtrsrfewrwed) change 4 to word size
      new IRT::BinopExpression(
          IRT::BinaryOperatorType::MUL,
          new IRT::BinopExpression(IRT::BinaryOperatorType::PLUS, idx,
                                   new IRT::ConstExpression(1)),
          new IRT::ConstExpression(4)));
  // Важно! В переменной, соотв. массиву, должен храниться указатель на первый
  // элемент массива в памяти, а не сам массив (а на самом деле в нулевой ячейке
  // вообще длина лежит)
  tos_value_ =
      new IRT::ExpressionWrapper(new IRT::MemExpression(offset_expression));
}

void IrtreeBuildVisitor::Visit(ArrayExpression *visited) {
  tos_value_ = new IRT::ExpressionWrapper(
      CreateArray(Accept(visited->expr_)->ToExpression()));
}

void IrtreeBuildVisitor::Visit(ArrayLengthExpression *visited) {
  auto arr = Accept(visited->expr_)->ToExpression();
  // размер сохранен в начале массива (в первом машинном слове)
  tos_value_ = new IRT::ExpressionWrapper(new IRT::MemExpression(arr));
}

void IrtreeBuildVisitor::Visit(BinaryExpression *visited) {
  auto lhs = Accept(visited->first);
  auto rhs = Accept(visited->second);

  switch (visited->op_->get_operation()) {
  case LessOp:
  case GreaterOp:
  case EqualOp:
    IRT::LogicOperatorType logic_operator_type;
    switch (visited->op_->get_operation()) {
    case LessOp:
      logic_operator_type = IRT::LogicOperatorType::LT;
      break;
    case GreaterOp:
      logic_operator_type = IRT::LogicOperatorType::GT;
      break;
    case EqualOp:
      logic_operator_type = IRT::LogicOperatorType::EQ;
      break;
    default:
      break;
    }
    tos_value_ = new IRT::RelativeConditionalWrapper(
        logic_operator_type, lhs->ToExpression(), rhs->ToExpression());
    break;
  case AndOp:
    tos_value_ = new IRT::AndConditionalWrapper(lhs, rhs);
    break;
  case OrOp:
    tos_value_ = new IRT::OrConditionalWrapper(lhs, rhs);
    break;
  case AddOp:
  case SubtractOp:
  case MultiplyOp:
  case DivOp:
  case ModOp:
    IRT::BinaryOperatorType binary_operator_type;
    switch (visited->op_->get_operation()) {
    case AddOp:
      binary_operator_type = IRT::BinaryOperatorType::PLUS;
      break;
    case SubtractOp:
      binary_operator_type = IRT::BinaryOperatorType::MINUS;
      break;
    case MultiplyOp:
      binary_operator_type = IRT::BinaryOperatorType::MUL;
      break;
    case DivOp:
      binary_operator_type = IRT::BinaryOperatorType::DIV;
      break;
    case ModOp:
      binary_operator_type = IRT::BinaryOperatorType::MOD;
      break;
    default:
      break;
    }
    tos_value_ = new IRT::ExpressionWrapper(new IRT::BinopExpression(
        binary_operator_type, lhs->ToExpression(), rhs->ToExpression()));
    break;
  default:
    throw std::runtime_error("Exception in BinaryExpression::eval()");
  }
}

void IrtreeBuildVisitor::Visit(BoolExpression *visited) {
  tos_value_ =
      new IRT::ExpressionWrapper(new IRT::ConstExpression(visited->value_));
}

void IrtreeBuildVisitor::Visit(Expression *visited) {}

void IrtreeBuildVisitor::Visit(ExpressionList *visited) {}

void IrtreeBuildVisitor::Visit(IdentExpression *visited) {
  auto address = current_frame_->GetAddress(visited->id_);

  tos_value_ = new IRT::ExpressionWrapper(address);
}

void IrtreeBuildVisitor::Visit(MethodInvokationExpression *visited) {
  visited->method_invokation_->Accept(this);
}

void IrtreeBuildVisitor::Visit(MethodInvokation *visited) {
  IRT::ExpressionList *irt_expressions = new IRT::ExpressionList();

  // adding "this"
  irt_expressions->Add(Accept(visited->obj_)->ToExpression());

  for (auto it : visited->args_->expressions_) {
    irt_expressions->Add(Accept(it)->ToExpression());
  }

  std::string obj_type = resolver_.Accept(visited->obj_);
  tos_value_ = new IRT::ExpressionWrapper(new IRT::CallExpression(
      new IRT::NameExpression(IRT::Label(obj_type + "::" + visited->func_name_)), irt_expressions));
}

void IrtreeBuildVisitor::Visit(NotExpression *visited) {
  auto wrapper = Accept(visited->expr_);

  tos_value_ = new IRT::NegateConditionalWrapper(
      wrapper
  );
}

void IrtreeBuildVisitor::Visit(NumberExpression *visited) {
  tos_value_ =
      new IRT::ExpressionWrapper(new IRT::ConstExpression(visited->value_));
}

void IrtreeBuildVisitor::Visit(ObjectExpression *visited) {
  auto obj_type = new ObjectType(
      symbol_tree_visitor_->classes_[visited->identifier_->GetTypeName()],
      false);
  tos_value_ = new IRT::ExpressionWrapper(CreateStruct(obj_type));
}

void IrtreeBuildVisitor::Visit(ParenthesesExpression *visited) {
  tos_value_ = Accept(visited->expr_);
}

void IrtreeBuildVisitor::Visit(ThisExpression *visited) {
  tos_value_ = new IRT::ExpressionWrapper(current_frame_->GetAddress("this"));
}

void IrtreeBuildVisitor::Visit(ArrayLvalue *visited) {
  // logic is implemented in variable declaration
}

void IrtreeBuildVisitor::Visit(SimpleLvalue *visited) {}

void IrtreeBuildVisitor::Visit(Lvalue *visited) {}

void IrtreeBuildVisitor::Visit(MainClass *visited) {
  while (!offsets_.empty()) {
    offsets_.pop();
  }
  offsets_.push(0);
  current_layer_ =
      symbol_tree_visitor_->classes_symbol_trees_[visited->main_class_name_]
          ->root_;

  current_class_name_ = visited->main_class_name_;

  std::string full_method_name = current_class_name_ + "::" + "main";
  current_frame_ = new IRT::FrameTranslator(
      full_method_name, symbol_tree_visitor_->classes_[current_class_name_]);
  frame_translator_[full_method_name] = current_frame_;

  auto statements_ir = Accept(visited->statements_);

  IRT::Statement *func_start =
      new IRT::LabelStatement(IRT::Label(full_method_name));

  if (statements_ir) {
    tos_value_ = new IRT::StatementWrapper(
        new IRT::SeqStatement(func_start, statements_ir->ToStatement()));
  } else {
    throw std::runtime_error(
        "Missing function body is not allowed in Mini-Java");
  }

  method_trees_.emplace(full_method_name, tos_value_->ToStatement());
}

void IrtreeBuildVisitor::Visit(Program *visited) {
  visited->class_declarations_->Accept(this);
  visited->main_class_->Accept(this);
}

void IrtreeBuildVisitor::Visit(AssertStatement *visited) {
  auto* irt_expressions = new IRT::ExpressionList();
  irt_expressions->Add(Accept(visited->expr_)->ToExpression());
  tos_value_ = new IRT::ExpressionWrapper(new IRT::CallExpression(
      new IRT::NameExpression(IRT::Label("assert")),
      irt_expressions));;
}

void IrtreeBuildVisitor::Visit(DefinitionStatement *visited) {
  IRT::Expression *var_expression =
      current_frame_->GetAddress(visited->lvalue_->id_);

  if (visited->lvalue_->is_array_) {
    auto idx = Accept(dynamic_cast<ArrayLvalue *>(visited->lvalue_)->idx_)
                   ->ToExpression();

    IRT::Expression *offset_expression = new IRT::BinopExpression(
        IRT::BinaryOperatorType::PLUS, var_expression,
        // TODO(@trrttrtrsrfewrwed) change 4 to word size
        new IRT::BinopExpression(
            IRT::BinaryOperatorType::MUL,
            new IRT::BinopExpression(IRT::BinaryOperatorType::PLUS, idx,
                                     new IRT::ConstExpression(1)),
            new IRT::ConstExpression(4)));

    // Важно! В переменной, соотв. массиву, должен храниться указатель на первый
    // элемент массива в памяти, а не сам массив (а на самом деле в нулевой
    // ячейке вообще длина лежит)
    var_expression = new IRT::MemExpression(offset_expression);
  }

  auto rvalue = Accept(visited->expr_);
  tos_value_ = new IRT::StatementWrapper(
      new IRT::MoveStatement(var_expression, rvalue->ToExpression()));
}

void IrtreeBuildVisitor::Visit(IfElseStatement *visited) {
  auto if_cond_expression = Accept(visited->query_);
  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  current_frame_->SetupScope();
  auto true_stmt = Accept(visited->if_statement_);
  offsets_.pop();
  size_t index = offsets_.top();
  offsets_.pop();
  offsets_.push(index + 1);
  current_layer_ = current_layer_->GetParent();
  current_frame_->TearDownScope();

  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  current_frame_->SetupScope();
  auto false_stmt = Accept(visited->else_statement_);
  offsets_.pop();
  index = offsets_.top();
  offsets_.pop();
  offsets_.push(index + 1);
  current_layer_ = current_layer_->GetParent();
  current_frame_->TearDownScope();

  IRT::Label label_true;
  IRT::Label label_false;
  IRT::Label label_join;

  IRT::Statement* suffix = new IRT::LabelStatement(label_join);

  IRT::Label* result_true = &label_join;
  IRT::Label* result_false = &label_join;

  if (false_stmt) {
    result_false = &label_false;
    suffix = new IRT::SeqStatement(
        new IRT::LabelStatement(label_false),
        new IRT::SeqStatement(false_stmt->ToStatement(), suffix)
    );

    if (true_stmt) {
      suffix = new IRT::SeqStatement(
          new IRT::JumpStatement(label_join),
          suffix
      );
    }
  }

  if (true_stmt) {
    result_true = &label_true;
    suffix = new IRT::SeqStatement(
        new IRT::LabelStatement(label_true),
        new IRT::SeqStatement(true_stmt->ToStatement(), suffix)
    );
  }

  tos_value_ = new IRT::StatementWrapper(
      new IRT::SeqStatement(
          if_cond_expression->ToConditional(*result_true, *result_false),
          suffix
      )
  );
}

void IrtreeBuildVisitor::Visit(IfStatement *visited) {
  auto if_cond_expression = Accept(visited->query_);

  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  current_frame_->SetupScope();
  auto true_stmt = Accept(visited->if_statement_);
  offsets_.pop();
  size_t index = offsets_.top();
  offsets_.pop();
  offsets_.push(index + 1);
  current_layer_ = current_layer_->GetParent();
  current_frame_->TearDownScope();

  IRT::Label label_true;
  IRT::Label label_join;

  IRT::Statement* suffix = new IRT::LabelStatement(label_join);

  IRT::Label* result_true = &label_join;
  IRT::Label* result_false = &label_join;

  if (true_stmt) {
    result_true = &label_true;
    suffix = new IRT::SeqStatement(
        new IRT::LabelStatement(label_true),
        new IRT::SeqStatement(true_stmt->ToStatement(),
            new IRT::SeqStatement(new IRT::JumpStatement(label_join),
                suffix))
    );
  }

  tos_value_ = new IRT::StatementWrapper(
      new IRT::SeqStatement(
          if_cond_expression->ToConditional(*result_true, *result_false),
          suffix
      )
  );
}

void IrtreeBuildVisitor::Visit(LocalVariableDeclarationStatement *visited) {
  visited->lv_decl_->variable_declaration_->Accept(this);
}

void IrtreeBuildVisitor::Visit(MethodInvokationStatement *visited) {
  visited->method_invokation_->Accept(this);
}

void IrtreeBuildVisitor::Visit(ReturnStatement *visited) {
  auto return_expr = Accept(visited->return_expr_);
  tos_value_ = new IRT::StatementWrapper(
      new IRT::MoveStatement(
          current_frame_->GetReturnValueAddress(),
          return_expr->ToExpression()
      )
  );
}

void IrtreeBuildVisitor::Visit(ScopeStatement *visited) {
  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);

  current_frame_->SetupScope();

  tos_value_ = Accept(visited->statements_);

  offsets_.pop();
  size_t index = offsets_.top();

  offsets_.pop();
  offsets_.push(index + 1);

  current_layer_ = current_layer_->GetParent();
  current_frame_->TearDownScope();
}

void IrtreeBuildVisitor::Visit(SoutStatement *visited) {
  auto* irt_expressions = new IRT::ExpressionList();
  irt_expressions->Add(Accept(visited->expr_)->ToExpression());
  tos_value_ = new IRT::ExpressionWrapper(new IRT::CallExpression(
      new IRT::NameExpression(IRT::Label("print")),
      irt_expressions));
}

void IrtreeBuildVisitor::Visit(Statement *visited) {
  std::cout << "In simple statement\n";
}

void IrtreeBuildVisitor::Visit(StatementList *visited) {
  if (visited->statements_.empty()) {
    tos_value_ = nullptr;
    return;
  }

  if (visited->statements_.size() == 1) {
    tos_value_ = Accept(visited->statements_[0]);
  } else {
    std::vector<IRT::Statement *> statements;
    statements.reserve(visited->statements_.size());
    //    size_t index = 0;
    for (auto statement : visited->statements_) {
      auto stmt = Accept(statement);

      if (stmt) {
        statements.push_back(stmt->ToStatement());
      }
    }
    IRT::Statement *suffix = statements.back();

    for (int index = static_cast<int>(statements.size()) - 2; index >= 0;
         --index) {
      suffix = new IRT::SeqStatement(statements.at(index), suffix);
    }
    tos_value_ = new IRT::StatementWrapper(suffix);
  }
}

void IrtreeBuildVisitor::Visit(WhileStatement *visited) {
  auto if_cond_expression = Accept(visited->query_);

  current_layer_ = current_layer_->GetChild(offsets_.top());
  offsets_.push(0);
  current_frame_->SetupScope();
  auto while_stmt = Accept(visited->while_statement_);
  offsets_.pop();
  size_t index = offsets_.top();
  offsets_.pop();
  offsets_.push(index + 1);
  current_layer_ = current_layer_->GetParent();
  current_frame_->TearDownScope();

  IRT::Label label_choose;
  IRT::Label label_body;
  IRT::Label label_join;

  IRT::Statement* suffix = new IRT::LabelStatement(label_join);

  IRT::Label* result_true = &label_join;

  if (while_stmt) {
    result_true = &label_body;
    suffix = new IRT::SeqStatement(
        new IRT::LabelStatement(label_body),
        new IRT::SeqStatement(
            while_stmt->ToStatement(),
            new IRT::SeqStatement(new IRT::JumpStatement(label_choose),
                                                    suffix))
    );
  }

  tos_value_ = new IRT::StatementWrapper(
      new IRT::SeqStatement(
          new IRT::LabelStatement(label_choose),
          new IRT::SeqStatement(
          if_cond_expression->ToConditional(*result_true, label_join),
          suffix)
      )
  );
}

void IrtreeBuildVisitor::Visit(ArrayType *visited) {}

void IrtreeBuildVisitor::Visit(SimpleType *visited) {}

void IrtreeBuildVisitor::Visit(Type *visited) {}

void IrtreeBuildVisitor::Visit(TypeIdentifier *visited) {}

void IrtreeBuildVisitor::Visit(BaseElement *visited) {}

IrtMapping IrtreeBuildVisitor::GetTrees() {
  return method_trees_;
}
void IrtreeBuildVisitor::SetSymbolTreeVisitor(
    SymbolTreeVisitor *symbol_tree_visitor) {
  symbol_tree_visitor_ = symbol_tree_visitor;
}

/// TypeResolver

void IrtreeBuildVisitor::TypeResolver::Visit(ArrayElementExpression *visited) {
  tos_value_ = Accept(visited->type_);
}
void IrtreeBuildVisitor::TypeResolver::Visit(ArrayExpression *visited) {
  tos_value_ = visited->type_->type_;
}
void IrtreeBuildVisitor::TypeResolver::Visit(ArrayLengthExpression *visited) {
  tos_value_ = int_;
}
void IrtreeBuildVisitor::TypeResolver::Visit(BoolExpression *visited) {
  tos_value_ = boolean_;
}
void IrtreeBuildVisitor::TypeResolver::Visit(BinaryExpression *visited) {
  tos_value_ = Accept(visited->first);
}
void IrtreeBuildVisitor::TypeResolver::Visit(IdentExpression *visited) {
  auto basic_type = main_->current_layer_->Get(visited->id_);
  tos_value_ = basic_type->GetTypeName();
}
void IrtreeBuildVisitor::TypeResolver::Visit(
    MethodInvokationExpression *visited) {
  std::string func_name = visited->method_invokation_->func_name_;
  std::string obj_type = Accept(visited->method_invokation_->obj_);
  auto class_type = main_->symbol_tree_visitor_->classes_[obj_type];
  BasicType *return_type = nullptr;
  for (size_t i = 0; i < class_type->field_names_.size(); ++i) {
    if (class_type->field_names_[i] == func_name) {
      return_type =
          dynamic_cast<MethodType *>(class_type->field_types_[i])->return_type_;
      break;
    }
  }
  if (return_type == nullptr) {
    throw std::runtime_error("return type unresolved");
  }

  tos_value_ = return_type->GetTypeName();
}
void IrtreeBuildVisitor::TypeResolver::Visit(NotExpression *visited) {
  tos_value_ = Accept(visited->expr_);
}
void IrtreeBuildVisitor::TypeResolver::Visit(ObjectExpression *visited) {
  tos_value_ = visited->identifier_->GetTypeName();
}
void IrtreeBuildVisitor::TypeResolver::Visit(NumberExpression *visited) {
  tos_value_ = int_;
}
void IrtreeBuildVisitor::TypeResolver::Visit(ParenthesesExpression *visited) {
  tos_value_ = Accept(visited->expr_);
}

void IrtreeBuildVisitor::TypeResolver::Visit(ThisExpression *visited) {
  tos_value_ = main_->current_class_name_;
}

IrtreeBuildVisitor::TypeResolver::TypeResolver(IrtreeBuildVisitor *main)
    : main_(main) {}

///trash
void IrtreeBuildVisitor::TypeResolver::Visit(BinaryOperator *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ClassDeclaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ClassDeclarationList *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(CommonDeclaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Declaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(DeclarationList *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(
    LocalVariableDeclaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(MethodDeclaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(VariableDeclaration *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Expression *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ExpressionList *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(FormalList *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ArrayLvalue *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(SimpleLvalue *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Lvalue *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(MainClass *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Program *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(MethodInvokation *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(AssertStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(DefinitionStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(IfElseStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(IfStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(
    LocalVariableDeclarationStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(
    MethodInvokationStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ReturnStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ScopeStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(SoutStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Statement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(StatementList *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(WhileStatement *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(ArrayType *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(SimpleType *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(Type *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(TypeIdentifier *visited) {}
void IrtreeBuildVisitor::TypeResolver::Visit(BaseElement *visited) {}
