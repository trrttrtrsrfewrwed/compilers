#include "DefinitionStatement.h"

DefinitionStatement::DefinitionStatement(Lvalue *lvalue, Expression *expr)
    : lvalue_(lvalue), expr_(expr) {}