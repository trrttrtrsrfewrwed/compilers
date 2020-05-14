#include "LinearizationVisitor.h"
#include "../nodes/statements/JumpConditionalStatement.h"
#include "../nodes/statements/MoveStatement.h"
#include "../nodes/statements/SeqStatement.h"
#include "BaseElements.h"
#include <iostream>

void IRT::LinearizationVisitor::Visit(IRT::ExpStatement *stmt) {
  IrtStorage elements = Accept(stmt->GetExpression());
  tos_value_.statement_ = new ExpStatement(elements.expression_);
}

void IRT::LinearizationVisitor::Visit(IRT::ConstExpression *const_expression) {
  tos_value_.expression_ = new ConstExpression(const_expression->Value());
}

void IRT::LinearizationVisitor::Visit(
    IRT::JumpConditionalStatement *jump_conditional_statement) {
  tos_value_.statement_ = new JumpConditionalStatement(
      jump_conditional_statement->operator_type_,
      Accept(jump_conditional_statement->left_operand_).expression_,
      Accept(jump_conditional_statement->right_operand_).expression_,
      jump_conditional_statement->label_true_,
      jump_conditional_statement->label_false_);
}
void IRT::LinearizationVisitor::Visit(IRT::MoveStatement *move_statement) {
  tos_value_.statement_ =
      new IRT::MoveStatement(Accept(move_statement->source_).expression_,
                             Accept(move_statement->target_).expression_);
}

void IRT::LinearizationVisitor::Visit(IRT::SeqStatement *seq_statement) {
  auto first = Accept(seq_statement->first_statement_).statement_;
  auto second = Accept(seq_statement->second_statement_).statement_;
  if (first->IsSEQ()) {
    auto seq_leaf = dynamic_cast<SeqStatement *>(first);
    tos_value_.statement_ =
        new SeqStatement(seq_leaf->first_statement_,
                         new SeqStatement(seq_leaf->second_statement_, second));
  } else {
    tos_value_.statement_ = new SeqStatement(first, second);
  }
}

void IRT::LinearizationVisitor::Visit(IRT::LabelStatement *label_statement) {
  tos_value_.statement_ = new LabelStatement(label_statement->label_);
}

void IRT::LinearizationVisitor::Visit(IRT::BinopExpression *binop_expression) {
  tos_value_.expression_ =
      new BinopExpression(binop_expression->operator_type_,
                          Accept(binop_expression->first_).expression_,
                          Accept(binop_expression->second_).expression_);
}
void IRT::LinearizationVisitor::Visit(IRT::TempExpression *temp_exression) {
  tos_value_.expression_ = new TempExpression(temp_exression->temporary_);
}
void IRT::LinearizationVisitor::Visit(IRT::MemExpression *mem_expression) {
  tos_value_.expression_ =
      new MemExpression(Accept(mem_expression->expression_).expression_);
}
void IRT::LinearizationVisitor::Visit(IRT::JumpStatement *jump_statement) {
  tos_value_.statement_ = new JumpStatement(jump_statement->label_);
}
void IRT::LinearizationVisitor::Visit(IRT::CallExpression *call_expression) {
  tos_value_.expression_ =
      new CallExpression(Accept(call_expression->function_name_).expression_,
                         Accept(call_expression->args_).expression_list_);
}

void IRT::LinearizationVisitor::Visit(IRT::ExpressionList *expression_list) {
  auto expression_list_ = new ExpressionList();

  for (auto expression: expression_list->expressions_) {
    expression_list_->Add(Accept(expression).expression_);
  }
  tos_value_.expression_list_ = expression_list_;
}

void IRT::LinearizationVisitor::Visit(IRT::NameExpression *name_expression) {
  tos_value_.expression_ = new NameExpression(name_expression->label_);
}

void IRT::LinearizationVisitor::Visit(IRT::EseqExpression *eseq_expression) {
  auto stmt = Accept(eseq_expression->statement_).statement_;
  auto expr = Accept(eseq_expression->expression_).expression_;

  tos_value_.expression_ = new EseqExpression(stmt, expr);
}

IRT::Statement *IRT::LinearizationVisitor::GetTree() {
  return tos_value_.statement_;
}