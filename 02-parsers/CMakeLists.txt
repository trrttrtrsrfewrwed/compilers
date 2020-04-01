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
        expressions/BinaryExpression.cpp
        expressions/ArrayExpression.cpp
        expressions/ArrayElementExpression.cpp
        expressions/ArrayLengthExpression.cpp
        expressions/ObjectExpression.cpp
        expressions/NotExpression.cpp
        expressions/ParenthesesExpression.cpp
        expressions/IdentExpression.cpp
        expressions/NumberExpression.cpp
        expressions/ThisExpression.cpp
        expressions/BoolExpression.cpp
        expressions/MethodInvokationExpression.cpp
        lvalues/SimpleLvalue.cpp
        lvalues/ArrayLvalue.cpp
        expressions/ExpressionList.cpp
        method_invokation/MethodInvokation.cpp
        statements/AssertStatement.cpp
        statements/LocalVariableDeclarationStatement.cpp
        statements/ScopeStatement.cpp
        statements/IfStatement.cpp
        statements/IfElseStatement.cpp
        statements/WhileStatement.cpp
        statements/SoutStatement.cpp
        statements/DefinitionStatement.cpp
        statements/ReturnStatement.cpp
        statements/MethodInvokationStatement.cpp
        main_structures/Program.cpp
        main_structures/MainClass.cpp
        declarations/ClassDeclarationList.cpp
        declarations/DeclarationList.cpp
        declarations/MethodDeclaration.cpp
        declarations/VariableDeclaration.cpp
        declarations/LocalVariableDeclaration.cpp
        declarations/ClassDeclaration.cpp
        declarations/Declaration.cpp
        formals/FormalList.cpp
        types/Type.cpp
        types/SimpleType.cpp
        types/ArrayType.cpp
        types/TypeIdentifier.cpp
        statements/Statement.cpp
        statements/StatementList.cpp
        binary_operator/BinaryOperator.cpp
        expressions/expr_info/ExprInfo.cpp
        base_elements/BaseElement.h
        visitors/Visitor.cpp
        visitors/Visitor.h
        declarations/CommonDeclaration.cpp
        visitors/PrintVisitor.cpp
        visitors/PrintVisitor.h symbol_table/ScopeLayer.cpp symbol_table/ScopeLayer.h symbol_table/Symbol.cpp symbol_table/Symbol.h objects/BasicType.cpp objects/BasicType.h objects/PrimitiveType.cpp objects/PrimitiveType.h objects/UninitObject.cpp objects/UninitObject.h visitors/TemplateVisitor.cpp visitors/TemplateVisitor.h visitors/SymbolTreeVisitor.cpp visitors/SymbolTreeVisitor.h symbol_table/ClassSymbolTree.cpp symbol_table/ClassSymbolTree.h objects/ObjectType.cpp objects/ObjectType.h objects/MethodType.cpp objects/MethodType.h objects/ClassType.cpp objects/ClassType.h)
target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})



