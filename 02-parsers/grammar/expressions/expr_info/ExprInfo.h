#pragma once

class ExprInfo {};

ExprInfo operator+(ExprInfo e1, ExprInfo e2);

ExprInfo operator-(ExprInfo e1, ExprInfo e2);

ExprInfo operator*(ExprInfo e1, ExprInfo e2);

ExprInfo operator/(ExprInfo e1, ExprInfo e2);

ExprInfo operator&&(ExprInfo e1, ExprInfo e2);

ExprInfo operator||(ExprInfo e1, ExprInfo e2);

ExprInfo operator==(ExprInfo e1, ExprInfo e2);

ExprInfo operator<(ExprInfo e1, ExprInfo e2);

ExprInfo operator>(ExprInfo e1, ExprInfo e2);

ExprInfo operator%(ExprInfo e1, ExprInfo e2);



