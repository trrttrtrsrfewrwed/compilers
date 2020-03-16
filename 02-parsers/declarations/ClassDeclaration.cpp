#include "ClassDeclaration.h"

ClassDeclaration::ClassDeclaration(std::string class_name,
                                   DeclarationList *fields): class_name_(std::move(class_name)), fields_(fields) {}
ClassDeclaration::ClassDeclaration(std::string class_name,
                                   std::string parent_name,
                                   DeclarationList *fields): class_name_(std::move(class_name)), parent_name_(std::move(parent_name)), fields_(fields) {}