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
        expressions/Expression.h binary_operator/BinaryOperator.h expressions/BinaryExpression.cpp expressions/BinaryExpression.h expressions/ArrayExpression.cpp expressions/ArrayExpression.h expressions/expr_info/ExprInfo.h expressions/ArrayElementExpression.cpp expressions/ArrayElementExpression.h expressions/ArrayLengthExpression.cpp expressions/ArrayLengthExpression.h expressions/ObjectExpression.cpp expressions/ObjectExpression.h expressions/NotExpression.cpp expressions/NotExpression.h expressions/ParenthesesExpression.cpp expressions/ParenthesesExpression.h expressions/IdentExpression.cpp expressions/IdentExpression.h expressions/NumberExpression.cpp expressions/NumberExpression.h expressions/ThisExpression.cpp expressions/ThisExpression.h expressions/BoolExpression.cpp expressions/BoolExpression.h expressions/MethodInvokationExpression.cpp expressions/MethodInvokationExpression.h lvalues/Lvalue.h lvalues/SimpleLvalue.cpp lvalues/SimpleLvalue.h lvalues/ArrayLvalue.cpp lvalues/ArrayLvalue.h expressions/ExpressionList.cpp expressions/ExpressionList.h method_invokation/MethodInvokation.cpp method_invokation/MethodInvokation.h statements/AssertStatement.cpp statements/AssertStatement.h statements/LocalVariableDeclarationStatement.cpp statements/LocalVariableDeclarationStatement.h statements/ScopeStatement.cpp statements/ScopeStatement.h statements/IfStatement.cpp statements/IfStatement.h statements/IfElseStatement.cpp statements/IfElseStatement.h statements/WhileStatement.cpp statements/WhileStatement.h statements/SoutStatement.cpp statements/SoutStatement.h statements/DefinitionStatement.cpp statements/DefinitionStatement.h statements/ReturnStatement.cpp statements/ReturnStatement.h statements/MethodInvokationStatement.cpp statements/MethodInvokationStatement.h main_structures/Program.cpp main_structures/Program.h main_structures/MainClass.cpp main_structures/MainClass.h declarations/ClassDeclarationList.cpp declarations/ClassDeclarationList.h declarations/DeclarationList.cpp declarations/DeclarationList.h declarations/MethodDeclaration.cpp declarations/MethodDeclaration.h declarations/VariableDeclaration.cpp declarations/VariableDeclaration.h declarations/LocalVariableDeclaration.cpp declarations/LocalVariableDeclaration.h declarations/ClassDeclaration.cpp declarations/ClassDeclaration.h declarations/Declaration.cpp declarations/Declaration.h formals/FormalList.cpp formals/FormalList.h types/Type.cpp types/Type.h types/SimpleType.cpp types/SimpleType.h types/ArrayType.cpp types/ArrayType.h types/TypeIdentifier.cpp types/TypeIdentifier.h statements/Statement.cpp statements/Statement.h)
target_include_directories(ParserExample PRIVATE ${ParserExample_SOURCE_DIR})



