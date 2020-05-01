%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <iostream>
    #include "BinaryOps.h"
    class Scanner;
    class Driver;

    #include "forward_decl.h"
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "elements.h"


    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
	END 0 "end of file"
        SOUT "sout"
        PSVM "psvm"
        ASSERT "assert"
        RETURN "return"
        TRUE "true"
        FALSE "false"
        NEW "new"
        THIS "this"
        LBRACE "{"
        RBRACE "}"
        INT "int"
        BOOLEAN "boolean"
        VOID "void"
        SEMICOLON ";"
        ASSIGN "="
        CLASS "class"
        EXTENDS "extends"
        PUBLIC "public"
        LENGTH "length"
        IF "if"
        ELSE "else"
        WHILE "while"
        DOT "."
        NOT "!"
        AND "&&"
        OR "||"
        LESS "<"
        GREATER ">"
        EQUAL "=="
        MINUS "-"
        PLUS "+"
        STAR "*"
        SLASH "/"
        PERCENT "%"
        LPAREN "("
        RPAREN ")"
        LSQUARE "["
        RSQUARE "]"
        COMMA ","
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <Expression*> expr
%nterm <Program*> unit
%nterm <MainClass*> main_class
%nterm <ClassDeclarationList*> class_declarations
%nterm <ClassDeclaration*> class_declaration
%nterm <StatementList*> statements
%nterm <Statement*> statement
%nterm <DeclarationList*> declarations
%nterm <Declaration*> declaration
%nterm <VariableDeclaration*> variable_declaration
%nterm <MethodDeclaration*> method_declaration
%nterm <Type*> type
%nterm <FormalList*> formals
%nterm <FormalList*> following_formals
%nterm <SimpleType*> simple_type
%nterm <ArrayType*> array_type
%nterm <TypeIdentifier*> type_identifier
%nterm <LocalVariableDeclaration*> local_variable_declaration
%nterm <MethodInvokation*> method_invocation
%nterm <ExpressionList*> following_exprs
%nterm <Lvalue*> lvalue
%nterm <BinaryOperator*> binary_operator


%printer { yyo << $$; } <*>;

%%
%start unit;
unit: main_class class_declarations { $$ = new Program($1, $2); driver.program = $$; };

main_class: "class" "identifier" "{" "psvm" "(" ")" "{" statements "}" "}" { $$ = new MainClass($2, $8); };

class_declarations:
	%empty { $$ = new ClassDeclarationList(); }
	| class_declarations class_declaration { $1->AddClassDeclaration($2); $$ = $1; };

statements:
	%empty { $$ = new StatementList(); }
	| statements statement { $1->AddStatement($2); $$ = $1; };

class_declaration: "class" "identifier" "{" declarations "}" { $$ = new ClassDeclaration($2, $4); } |
		"class" "identifier" "extends" "identifier" "{" declarations "}" { $$ = new ClassDeclaration($2, $4, $6); };

declarations:	%empty { $$ = new DeclarationList(); }
	| declarations declaration { $1->AddDeclaration($2); $$ = $1; };

declaration: variable_declaration { $$ = new Declaration($1); }
 	| method_declaration { $$ = new Declaration($1); };

method_declaration: "public" type "identifier" "(" ")" "{" statements "}" { $$ = new MethodDeclaration($2, $3, $7); }
	| "public" type "identifier" "(" formals ")" "{" statements "}" { $$ = new MethodDeclaration($2, $3, $5, $8); };

variable_declaration: type "identifier" ";" { $$ = new VariableDeclaration($1, $2); };

formals: type "identifier" following_formals { $3->AddFormal($1, $2); $$ = $3; };

following_formals:
	%empty { $$ = new FormalList(); }
	| "," type "identifier" following_formals { $4->AddFormal($2, $3); $$ = $4; };

type:
	simple_type { $$ = new Type($1); }
	| array_type { $$ = new Type($1); };

simple_type:
	"int" { $$ = new SimpleType("int"); }
	| "boolean" { $$ = new SimpleType("boolean"); }
	| "void" { $$ = new SimpleType("void"); }
	| type_identifier { $$ = new SimpleType($1); };

array_type:
	simple_type "[" "]" { $$ = new ArrayType($1); };

type_identifier:
	"identifier" { $$ = new TypeIdentifier($1); };

statement: "assert" "(" expr ")" ";" { $$ = new AssertStatement($3); } |
                local_variable_declaration { $$ = new LocalVariableDeclarationStatement($1); } |
                "{" statements "}" { $$ = new ScopeStatement($2); } |
                "if"  "(" expr ")" statement { $$ = new IfStatement($3, $5); } |
                "if"  "(" expr ")" statement "else" statement { $$ = new IfElseStatement($3, $5, $7); } |
                "while"  "(" expr ")" statement  { $$ = new WhileStatement($3, $5); } |
                "sout" "(" expr ")" ";"  { $$ = new SoutStatement($3); } |
                lvalue "=" expr ";"  { $$ = new DefinitionStatement($1, $3); } |
                "return" expr ";"  { $$ = new ReturnStatement($2); }|
                method_invocation ";" { $$ = new MethodInvokationStatement($1); };

local_variable_declaration: variable_declaration { $$ = new LocalVariableDeclaration($1); };

method_invocation: expr "." "identifier" "(" ")" { $$ = new MethodInvokation($1, $3); }
		| expr "." "identifier" "(" expr following_exprs ")" { $$ = new MethodInvokation($1, $3, $5, $6); };

following_exprs:
	%empty { $$ = new ExpressionList(); }
	| "," expr following_exprs { $3->AddExpression($2); $$ = $3; };


lvalue:
	"identifier" { $$ = new SimpleLvalue($1); }
	 | "identifier" "[" expr "]" {
	 $$ = new ArrayLvalue($1, $3);
	  };

expr:	expr binary_operator expr  {
		$$ = new BinaryExpression($1, $3, $2);
}
	| expr "[" expr "]"  {
		$$ = new ArrayElementExpression($1, $3);
	}
	| expr "." "length" {
		$$ = new ArrayLengthExpression($1);
	}
	| "new" simple_type "[" expr "]" {
		$$ = new ArrayExpression($2, $4);
	}
	| "new" type_identifier "(" ")" {
		$$ = new ObjectExpression($2);
	}
	| "!" expr { $$ = new NotExpression($2); }
	| "(" expr ")" { $$ = new ParenthesesExpression($2); }
	| "identifier"  { $$ = new IdentExpression($1); }
	| "number"  { $$ = new NumberExpression($1); }
	| "this" { $$ = new ThisExpression("this"); }
	| "true" { $$ = new BoolExpression("true"); }
	| "false" { $$ = new BoolExpression("false"); }
	| method_invocation { $$ = new MethodInvokationExpression($1); };


binary_operator:
	"&&"   { $$ = new BinaryOperator(AndOp); }
	|  "||"  { $$ = new BinaryOperator(OrOp); }
	|  "<"   { $$ = new BinaryOperator(LessOp); }
	| ">"   { $$ = new BinaryOperator(GreaterOp); }
	|  "=="   { $$ = new BinaryOperator(EqualOp); }
	| "+"   { $$ = new BinaryOperator(AddOp); }
	|  "-"  { $$ = new BinaryOperator(SubtractOp); }
	| "*"  { $$ = new BinaryOperator(MultiplyOp); }
	| "/"  { $$ = new BinaryOperator(DivOp); }
	| "%"  { $$ = new BinaryOperator(ModOp); };

%left "||";
%left "&&";
%left "==";
%left ">" "<";
%left "+" "-";
%left "*" "/" "%";


%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
