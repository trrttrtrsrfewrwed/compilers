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

BasicType *IrtreeBuildVisitor::GetBasicType(Type *type) {
  return symbol_tree_visitor_->GetBasicType(type);
}

void IrtreeBuildVisitor::Visit(BinaryOperator *visited) {}

void IrtreeBuildVisitor::Visit(ClassDeclaration *visited) {}

void IrtreeBuildVisitor::Visit(ClassDeclarationList *visited) {}

void IrtreeBuildVisitor::Visit(CommonDeclaration *visited) {}

void IrtreeBuildVisitor::Visit(Declaration *visited) {}

void IrtreeBuildVisitor::Visit(DeclarationList *visited) {}

void IrtreeBuildVisitor::Visit(LocalVariableDeclaration *visited) {}

void IrtreeBuildVisitor::Visit(MethodDeclaration *visited) {}

void IrtreeBuildVisitor::Visit(VariableDeclaration *visited) {
  tos_value_ = nullptr;
  if (visited->type_->is_array_) {
    current_frame_->AddLocalArray(visited->variable_name_);
  } else {
    current_frame_->AddLocalVariable(visited->variable_name_);

    auto basic_type = GetBasicType(visited->type_);
    if (basic_type->GetType() == "ObjectType") {
      auto expr =
          current_frame_->GetAddress(visited->variable_name_)->ToExpression();

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
      new IRT::BinopExpression(IRT::BinaryOperatorType::MUL,
          new IRT::BinopExpression(
                            IRT::BinaryOperatorType::PLUS,
                                 idx,
                            new IRT::ConstExpression(1)),
          new IRT::ConstExpression(4)));
  // Важно! В переменной, соотв. массиву, должен храниться указатель на первый
  // элемент массива в памяти, а не сам массив (а на самом деле в нулевой ячейке вообще длина лежит)
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

void IrtreeBuildVisitor::Visit(BoolExpression *visited) {}

void IrtreeBuildVisitor::Visit(Expression *visited) {}

void IrtreeBuildVisitor::Visit(ExpressionList *visited) {}

void IrtreeBuildVisitor::Visit(IdentExpression *visited) {
  auto address = current_frame_->GetAddress(visited->id_);

  tos_value_ = new IRT::ExpressionWrapper(address->ToExpression());
}

void IrtreeBuildVisitor::Visit(MethodInvokationExpression *visited) {}

void IrtreeBuildVisitor::Visit(NotExpression *visited) {}

void IrtreeBuildVisitor::Visit(NumberExpression *visited) {
  tos_value_ =
      new IRT::ExpressionWrapper(new IRT::ConstExpression(visited->value_));
}

void IrtreeBuildVisitor::Visit(ObjectExpression *visited) {}

void IrtreeBuildVisitor::Visit(ParenthesesExpression *visited) {}

void IrtreeBuildVisitor::Visit(ThisExpression *visited) {}

void IrtreeBuildVisitor::Visit(FormalList *visited) {}

void IrtreeBuildVisitor::Visit(ArrayLvalue *visited) {}

void IrtreeBuildVisitor::Visit(SimpleLvalue *visited) {}

void IrtreeBuildVisitor::Visit(Lvalue *visited) {}

void IrtreeBuildVisitor::Visit(MainClass *visited) {}

void IrtreeBuildVisitor::Visit(Program *visited) {}

void IrtreeBuildVisitor::Visit(MethodInvokation *visited) {}

void IrtreeBuildVisitor::Visit(AssertStatement *visited) {}

void IrtreeBuildVisitor::Visit(DefinitionStatement *visited) {
  IRT::Expression *var_expression =
      current_frame_->GetAddress(visited->lvalue_->id_)->ToExpression();

  if (visited->lvalue_->is_array_) {
    auto idx = Accept(dynamic_cast<ArrayLvalue *>(visited->lvalue_)->idx_)
                   ->ToExpression();

    IRT::Expression *offset_expression = new IRT::BinopExpression(
        IRT::BinaryOperatorType::PLUS, var_expression,
        // TODO(@trrttrtrsrfewrwed) change 4 to word size
        new IRT::BinopExpression(IRT::BinaryOperatorType::MUL,
                                 new IRT::BinopExpression(
                                     IRT::BinaryOperatorType::PLUS,
                                     idx,
                                     new IRT::ConstExpression(1)),
                                 new IRT::ConstExpression(4)));

    // Важно! В переменной, соотв. массиву, должен храниться указатель на первый
    // элемент массива в памяти, а не сам массив (а на самом деле в нулевой ячейке вообще длина лежит)
    var_expression = new IRT::MemExpression(offset_expression);
  }

  auto rvalue = Accept(visited->expr_);
  tos_value_ = new IRT::StatementWrapper(
      new IRT::MoveStatement(var_expression, rvalue->ToExpression()));
}

void IrtreeBuildVisitor::Visit(IfElseStatement *visited) {}

void IrtreeBuildVisitor::Visit(IfStatement *visited) {}

void IrtreeBuildVisitor::Visit(LocalVariableDeclarationStatement *visited) {}

void IrtreeBuildVisitor::Visit(MethodInvokationStatement *visited) {}

void IrtreeBuildVisitor::Visit(ReturnStatement *visited) {}

void IrtreeBuildVisitor::Visit(ScopeStatement *visited) {}

void IrtreeBuildVisitor::Visit(SoutStatement *visited) {}

void IrtreeBuildVisitor::Visit(Statement *visited) {}

void IrtreeBuildVisitor::Visit(StatementList *visited) {}

void IrtreeBuildVisitor::Visit(WhileStatement *visited) {}

void IrtreeBuildVisitor::Visit(ArrayType *visited) {}

void IrtreeBuildVisitor::Visit(SimpleType *visited) {}

void IrtreeBuildVisitor::Visit(Type *visited) {}

void IrtreeBuildVisitor::Visit(TypeIdentifier *visited) {}

void IrtreeBuildVisitor::Visit(BaseElement *visited) {}
