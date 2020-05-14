#include "EseqLiftVisitor.h"

#include "BaseElements.h"

bool isCommute(IRT::Statement *stmt, IRT::Expression *exp) {
  if (stmt->IsEXP()) {
    auto exp_stmt = dynamic_cast<IRT::ExpStatement *>(stmt);
    return exp_stmt->GetExpression()->IsCONST() || exp->IsCONST() ||
           exp->IsNAME();
  } else {
    return exp->IsCONST() || exp->IsNAME();
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::ExpStatement *stmt) {
  auto expr = Accept(stmt->GetExpression()).expression_;
  if (expr->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression*>(expr);
    tos_value_.statement_ = eseq_leaf->statement_;
  } else {
    tos_value_.statement_ = new ExpStatement(expr);
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::ConstExpression *const_expression) {
  tos_value_.expression_ = new ConstExpression(const_expression->Value());
}

void IRT::EseqLiftVisitor::Visit(
    IRT::JumpConditionalStatement *jump_conditional_statement) {
  auto first = Accept(jump_conditional_statement->left_operand_).expression_;
  auto second = Accept(jump_conditional_statement->right_operand_).expression_;

  if (first->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(first);
    tos_value_.statement_ = new SeqStatement(
        eseq_leaf->statement_,
        new JumpConditionalStatement(jump_conditional_statement->operator_type_,
                                     eseq_leaf->expression_, second,
                                     jump_conditional_statement->label_true_,
                                     jump_conditional_statement->label_false_));
  } else if (second->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(second);

    if (isCommute(eseq_leaf->statement_, first)) {
      tos_value_.statement_ = new SeqStatement(
          eseq_leaf->statement_,
          new JumpConditionalStatement(
              jump_conditional_statement->operator_type_, first,
              eseq_leaf->expression_, jump_conditional_statement->label_true_,
              jump_conditional_statement->label_false_));
    } else {
      Temporary temp;
      tos_value_.statement_ = new SeqStatement(
          new MoveStatement(new TempExpression(temp), first),
          new SeqStatement(eseq_leaf->statement_,
                           new JumpConditionalStatement(
                               jump_conditional_statement->operator_type_,
                               new TempExpression(temp), eseq_leaf->expression_,
                               jump_conditional_statement->label_true_,
                               jump_conditional_statement->label_false_)));
    }
  } else {
    tos_value_.statement_ = new JumpConditionalStatement(
        jump_conditional_statement->operator_type_, first, second,
        jump_conditional_statement->label_true_,
        jump_conditional_statement->label_false_);
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::MoveStatement *move_statement) {
  auto source = Accept(move_statement->source_).expression_;
  auto target = Accept(move_statement->target_).expression_;
  if (source->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(source);
    tos_value_.statement_ =
        new SeqStatement(eseq_leaf->statement_,
                         new MoveStatement(eseq_leaf->expression_, target));
  } else if (target->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(target);
    tos_value_.statement_ =
        new SeqStatement(eseq_leaf->statement_,
                         new MoveStatement(source, eseq_leaf->expression_));
  } else {
    tos_value_.statement_ = new MoveStatement(source, target);
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::SeqStatement *seq_statement) {
  tos_value_.statement_ =
      new SeqStatement(Accept(seq_statement->first_statement_).statement_,
                       Accept(seq_statement->second_statement_).statement_);
}

void IRT::EseqLiftVisitor::Visit(IRT::LabelStatement *label_statement) {
  // ESEQ не может быть в поддереве LabelStatement, т к LabelStatement всегда
  // лист
  tos_value_.statement_ = new LabelStatement(label_statement->label_);
}

void IRT::EseqLiftVisitor::Visit(IRT::BinopExpression *binop_expression) {
  auto first = Accept(binop_expression->first_).expression_;
  auto second = Accept(binop_expression->second_).expression_;
  if (first->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<IRT::EseqExpression *>(first);
    tos_value_.expression_ =
        new EseqExpression(eseq_leaf->statement_,
                           new BinopExpression(binop_expression->operator_type_,
                                               eseq_leaf->expression_, second));
  } else if (second->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<IRT::EseqExpression *>(second);
    if (isCommute(eseq_leaf->statement_, first)) {
      tos_value_.expression_ = new EseqExpression(
          eseq_leaf->statement_,
          new BinopExpression(binop_expression->operator_type_, first,
                              eseq_leaf->expression_));
    } else {
      Temporary temp;
      auto stmt = new MoveStatement(new TempExpression(temp), first);
      tos_value_.expression_ = new EseqExpression(
          stmt, new EseqExpression(
                    eseq_leaf->statement_,
                    new BinopExpression(binop_expression->operator_type_,
                                        new TempExpression(temp),
                                        eseq_leaf->expression_)));
    }
  } else {
    tos_value_.expression_ = new BinopExpression(binop_expression->operator_type_,
        first, second);
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::TempExpression *temp_exression) {
  tos_value_.expression_ = new TempExpression(temp_exression->temporary_);
}

void IRT::EseqLiftVisitor::Visit(IRT::MemExpression *mem_expression) {
  auto expr = Accept(mem_expression->expression_).expression_;
  if (expr->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(expr);
    tos_value_.expression_ = new EseqExpression(
        eseq_leaf->statement_, new MemExpression(eseq_leaf->expression_));
  } else {
    tos_value_.expression_ = new MemExpression(expr);
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::JumpStatement *jump_statement) {
  // ESEQ не может быть в поддереве JumpStatement, т к JumpStatement всегда лист
  tos_value_.statement_ = new JumpStatement(jump_statement->label_);
}

void IRT::EseqLiftVisitor::Visit(IRT::CallExpression *call_expression) {
  auto expression_list = new ExpressionList();
  for (auto arg : call_expression->args_->expressions_) {
    expression_list->Add(Accept(arg).expression_);
  }

  if (call_expression->function_name_->IsESEQ()) {
    auto eseq_leaf =
        dynamic_cast<EseqExpression *>(call_expression->function_name_);
    tos_value_.expression_ = new EseqExpression(
        eseq_leaf->statement_,
        new CallExpression(eseq_leaf->expression_, expression_list));
    return;
  }

  int first_eseq = -1;
  for (size_t i = 0; i < expression_list->expressions_.size(); ++i) {
    if (expression_list->expressions_[i]->IsESEQ()) {
      first_eseq = i;
      break;
    }
  }
  if (first_eseq == -1) {
    tos_value_.expression_ = new CallExpression(
        Accept(call_expression->function_name_).expression_, expression_list);
    return;
  } else {
    auto eseq_leaf = dynamic_cast<EseqExpression *>(
        expression_list->expressions_[first_eseq]);
    std::vector<Temporary> temps;
    Temporary empty("empty");
    for (int i = 0; i < first_eseq - 1; ++i) {
      if (!isCommute(eseq_leaf->statement_, expression_list->expressions_[i])) {
        temps.emplace_back();
      } else {
        temps.push_back(empty);
      }
    }
    for (size_t i = first_eseq; i < expression_list->expressions_.size(); ++i) {
      temps.push_back(empty);
    }
    auto new_stmt = eseq_leaf->statement_;
    for (int i = expression_list->expressions_.size() - 1; i >= 0; --i) {
      if (temps[i].ToString() != "empty") {
        new_stmt = new SeqStatement(
            new MoveStatement(new TempExpression(temps[i]),
                              expression_list->expressions_[i]),
            new_stmt);
      }
    }
    auto new_expr_list = new ExpressionList();
    for (size_t i = 0; i < expression_list->expressions_.size(); ++i) {
      if (i == first_eseq) {
        new_expr_list->Add(eseq_leaf->expression_);
      } else {
        if (temps[i].ToString() != "empty") {
          new_expr_list->Add(new TempExpression(temps[i]));
        } else {
          new_expr_list->Add(expression_list->expressions_[i]);
        }
      }
    }
    tos_value_.expression_ = new EseqExpression(
        new_stmt,
        new CallExpression(Accept(call_expression->function_name_).expression_,
                           new_expr_list));
  }
}

void IRT::EseqLiftVisitor::Visit(IRT::ExpressionList *expression_list) {
  // logic is implemented in call expr
}
void IRT::EseqLiftVisitor::Visit(IRT::NameExpression *name_expression) {
  tos_value_.expression_ = new NameExpression(name_expression->label_);
}

void IRT::EseqLiftVisitor::Visit(IRT::EseqExpression *eseq_expression) {
  auto stmt = Accept(eseq_expression->statement_).statement_;
  auto expr = Accept(eseq_expression->expression_).expression_;
  if (expr->IsESEQ()) {
    auto eseq_leaf = dynamic_cast<IRT::EseqExpression *>(expr);
    tos_value_.expression_ = new EseqExpression(
        new SeqStatement(stmt, eseq_leaf->statement_), eseq_leaf->expression_);
  } else {
    tos_value_.expression_ = new EseqExpression(stmt, expr);
  }
}

IRT::Statement *IRT::EseqLiftVisitor::GetTree() {
  return tos_value_.statement_;
}
