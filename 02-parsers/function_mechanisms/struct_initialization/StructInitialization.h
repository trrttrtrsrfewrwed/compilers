#pragma once

#include <irtree/generators/Temporary.h>
#include <irtree/nodes/ExpressionList.h>
#include <irtree/nodes/expressions/CallExpression.h>
#include <irtree/nodes/expressions/ConstExpression.h>
#include <irtree/nodes/expressions/EseqExpression.h>
#include <irtree/nodes/expressions/NameExpression.h>
#include <irtree/nodes/expressions/TempExpression.h>
#include <irtree/nodes/expressions/BinopExpression.h>
#include <irtree/nodes/expressions/MemExpression.h>
#include <irtree/nodes/statements/SeqStatement.h>
#include <irtree/nodes/statements/MoveStatement.h>
#include <irtree/types/BinaryOperatorType.h>
#include <object_types/BasicType.h>

IRT::Expression *CreateStruct(BasicType *type) {
  auto* irt_expressions = new IRT::ExpressionList();
  irt_expressions->Add(new IRT::ConstExpression(type->GetSize()));

  IRT::Temporary tmp;
  return new IRT::EseqExpression(
      new IRT::MoveStatement(new IRT::TempExpression(tmp),
                             new IRT::CallExpression(
                                 new IRT::NameExpression(IRT::Label("malloc")),
                                 irt_expressions)),
      new IRT::TempExpression(tmp)
  );
}

IRT::Expression *CreateArray(IRT::Expression* size) {
  auto* irt_expressions = new IRT::ExpressionList();
  // TODO (@trrttrtrsrfewrwed) change 4 to word size
  irt_expressions->Add(new IRT::BinopExpression(
      IRT::BinaryOperatorType::MUL,
      new IRT::ConstExpression(4),
      new IRT::BinopExpression(
          IRT::BinaryOperatorType::PLUS,
          size,
          new IRT::ConstExpression(1)
      )));

  IRT::Temporary tmp;
  return new IRT::EseqExpression(
         new IRT::SeqStatement(
      new IRT::MoveStatement(new IRT::TempExpression(tmp),
                             new IRT::CallExpression(
                                 new IRT::NameExpression(IRT::Label("malloc")),
                                 irt_expressions)),
      new IRT::MoveStatement(new IRT::MemExpression(new IRT::TempExpression(tmp)), size)
                                 ),
      new IRT::TempExpression(tmp)
  );
}