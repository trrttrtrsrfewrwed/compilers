#include "Program.h"

Program::Program(MainClass *main_class,
                 ClassDeclarationList *class_declarations)
    : main_class_(main_class), class_declarations_(class_declarations) {}