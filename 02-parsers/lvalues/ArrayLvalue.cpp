#include "ArrayLvalue.h"

ArrayLvalue::ArrayLvalue(std::string id, Expression *idx)
    : id_(std::move(id)), idx_(idx) {}