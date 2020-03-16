#include "Type.h"

Type::Type(SimpleType *type): type_(type->GetType()), is_array_(false) {}

Type::Type(ArrayType *type): type_(type->GetType()), is_array_(true) {}