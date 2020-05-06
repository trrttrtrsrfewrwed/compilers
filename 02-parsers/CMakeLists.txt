project(ParserExample)
set(
    HEADERS
    ${ParserExample_SOURCE_DIR}/driver.hh
    ${ParserExample_SOURCE_DIR}/parser.hh
    )

BISON_TARGET(
    MyParser
    parser.y
    ${ParserExample_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScanner
        scanner.l
    ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    ParserExample
    main.cpp
    driver.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
        grammar/expressions/BinaryExpression.cpp
        grammar/expressions/ArrayExpression.cpp
        grammar/expressions/ArrayElementExpression.cpp
        grammar/expressions/ArrayLengthExpression.cpp
        grammar/expressions/ObjectExpression.cpp
        grammar/expressions/NotExpression.cpp
        grammar/expressions/ParenthesesExpression.cpp
        grammar/expressions/IdentExpression.cpp
        grammar/expressions/NumberExpression.cpp
        grammar/expressions/ThisExpression.cpp
        grammar/expressions/BoolExpression.cpp
        grammar/expressions/MethodInvokationExpression.cpp
        grammar/lvalues/SimpleLvalue.cpp
        grammar/lvalues/ArrayLvalue.cpp
        grammar/expressions/ExpressionList.cpp
        grammar/method_invokation/MethodInvokation.cpp
        grammar/statements/AssertStatement.cpp
        grammar/statements/LocalVariableDeclarationStatement.cpp
        grammar/statements/ScopeStatement.cpp
        grammar/statements/IfStatement.cpp
        grammar/statements/IfElseStatement.cpp
        grammar/statements/WhileStatement.cpp
        grammar/statements/SoutStatement.cpp
        grammar/statements/DefinitionStatement.cpp
        grammar/statements/ReturnStatement.cpp
        grammar/statements/MethodInvokationStatement.cpp
        grammar/main_structures/Program.cpp
        grammar/main_structures/MainClass.cpp
        grammar/declarations/ClassDeclarationList.cpp
        grammar/declarations/DeclarationList.cpp
        grammar/declarations/MethodDeclaration.cpp
        grammar/declarations/VariableDeclaration.cpp
        grammar/declarations/LocalVariableDeclaration.cpp
        grammar/declarations/ClassDeclaration.cpp
        grammar/declarations/Declaration.cpp
        grammar/formals/FormalList.cpp
        grammar/types/Type.cpp
        grammar/types/SimpleType.cpp
        grammar/types/ArrayType.cpp
        grammar/types/TypeIdentifier.cpp
        grammar/statements/Statement.cpp
        grammar/statements/StatementList.cpp
        grammar/binary_operator/BinaryOperator.cpp
        grammar/expressions/expr_info/ExprInfo.cpp
        grammar/base_elements/BaseElement.h
        visitors/Visitor.cpp
        visitors/Visitor.h
        grammar/declarations/CommonDeclaration.cpp
        visitors/PrintVisitor.cpp
        visitors/PrintVisitor.h symbol_table/ScopeLayer.cpp symbol_table/ScopeLayer.h symbol_table/Symbol.cpp symbol_table/Symbol.h object_types/BasicType.cpp object_types/BasicType.h object_types/PrimitiveType.cpp object_types/PrimitiveType.h object_types/UninitObject.cpp object_types/UninitObject.h visitors/TemplateVisitor.cpp visitors/TemplateVisitor.h visitors/SymbolTreeVisitor.cpp visitors/SymbolTreeVisitor.h symbol_table/ClassSymbolTree.cpp symbol_table/ClassSymbolTree.h object_types/ObjectType.cpp object_types/ObjectType.h object_types/MethodType.cpp object_types/MethodType.h object_types/ClassType.cpp object_types/ClassType.h object_types/VoidType.cpp object_types/VoidType.h function_mechanisms/FrameEmulator.cpp function_mechanisms/FrameEmulator.h function_mechanisms/FunctionTable.cpp function_mechanisms/FunctionTable.h objects/BasicObject.cpp objects/BasicObject.h visitors/MethodCallVisitor.cpp visitors/MethodCallVisitor.h objects/Object.cpp objects/Object.h objects/Array.cpp objects/Array.h function_mechanisms/FrameTranslator.cpp function_mechanisms/FrameTranslator.cpp function_mechanisms/FrameTranslator.h
        function_mechanisms/address/Address.h function_mechanisms/address/AddressInFrame.h function_mechanisms/address/AddressInFrame.cpp function_mechanisms/address/AddressInRegister.h function_mechanisms/address/AddressInRegister.cpp visitors/IrtreeBuildVisitor.cpp visitors/IrtreeBuildVisitor.h function_mechanisms/struct_initialization/StructInitialization.h)
target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})

set(IR_LIB "${PROJECT_NAME}IrLib")

add_subdirectory(irtree)

target_link_libraries(${CURRENT_EXECUTABLE} ${IR_LIB})

