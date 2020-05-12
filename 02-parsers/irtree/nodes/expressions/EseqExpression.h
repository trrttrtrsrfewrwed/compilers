//
// Created by akhtyamovpavel on 4/15/20.
//


#pragma once

#include "../statements/Statement.h"
#include "Expression.h"
namespace IRT {

class EseqExpression: public Expression {
 public:
  virtual bool IsESEQ() override ;
  EseqExpression(Statement* statement, Expression* expression);
  void Accept(Visitor *visitor) override;

  Statement* statement_;
  Expression* expression_;
};

}


