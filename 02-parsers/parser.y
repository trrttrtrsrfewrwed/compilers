%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include "BinaryOps.h"
    class Scanner;
    class Driver;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"


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
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> binary_operator
%nterm <int> expr
%nterm <std::string> lvalue

%printer { yyo << $$; } <*>;

%%
%start unit;
unit: main_class class_declarations {};

main_class: "class" "identifier" "{" "psvm" "(" ")" "{" statements "}" "}" {};

class_declarations:
	%empty {}
	| class_declaration {};

statements:
	%empty {}
	| statements statement {};

class_declaration: "class" "identifier" "{" declarations "}" {} |
		"class" "identifier" "extends" "identifier" "{" declarations "}" {};

declarations:
	%empty {}
	| declarations declaration {};

declaration: variable_declaration {}
 	| method_declaration {};

method_declaration: "public" type "identifier" "(" ")" "{" statements "}" {}
	| "public" type "identifier" "(" formals ")" "{" statements "}" {};

variable_declaration: type "identifier" ";" {};

formals: type "identifier" following_formals {};

following_formals:
	%empty {}
	| "," type "identifier" following_formals {};

type:
	simple_type {}
	| array_type {};

simple_type:
	"int" {}
	| "boolean" {}
	| "void" {}
	| type_identifier {};

array_type:
	simple_type "[" "]" {};

type_identifier:
	"identifier";

statement: "assert" "(" expr ")" ";" {} |
                local_variable_declaration {} |
                "{" statements "}" {} |
                "if"  "(" expr ")" statement {} |
                "if"  "(" expr ")" statement "else" statement {} |
                "while"  "(" expr ")" statement  {} |
                "sout" "(" expr ")" ";"  { std::cout << $3 << "\n"; } |
                lvalue "=" expr ";"  { driver.variables[$1] = $3; } |
                "return" expr ";"  { driver.result = $2; }|
                method_invocation ";" {};

local_variable_declaration: variable_declaration {};

method_invocation: expr "." "identifier" "(" ")" {}
		| expr "." "identifier" "(" expr following_exprs ")" {};

following_exprs:
	%empty {}
	| "," expr following_exprs {};


lvalue:
	"identifier" { $$ = $1; }
	 | "identifier" "[" expr "]" {};

expr:	expr binary_operator expr  {
		switch($2) {
			case AndOp:
				$$ = $1 && $3;
				break;
                        case OrOp:
				$$ = $1 || $3;
				break;
                        case LessOp:
                        	$$ = $1 < $3;
                        	break;
                        case GreaterOp:
                        	$$ = $1 > $3;
                        	break;
                        case EqualOp:
                        	$$ = $1 == $3;
                        	break;
                        case AddOp:
                        	$$ = $1 + $3;
                        	break;
                        case SubtractOp:
                        	$$ = $1 - $3;
                        	break;
                        case MultiplyOp:
                        	$$ = $1 * $3;
                        	break;
                        case DivOp:
                        	$$ = $1 / $3;
                        	break;
                        case ModOp:
                        	$$ = $1 % $3;
                        	break;
		}
}
	| expr "[" expr "]"  {}
	| expr "." "length" {}
	| "new" simple_type "[" expr "]" {}
	| "new" type_identifier "(" ")" {}
	| "!" expr { $$ = !($2); }
	| "(" expr ")" { $$ = $2; }
	| "identifier"  { $$ = driver.variables[$1]; }
	| "number"  { $$ = $1; }
	| "this" {}
	| "true" { $$ = 1; }
	| "false" { $$ = 0; }
	| method_invocation {};


binary_operator:
	"&&"   { $$ = AndOp; }
	|  "||"  { $$ = OrOp; }
	|  "<"   { $$ = LessOp; }
	| ">"   { $$ = GreaterOp; }
	|  "=="   { $$ = EqualOp; }
	| "+"   { $$ = AddOp; }
	|  "-"  { $$ = SubtractOp; }
	| "*"  { $$ = MultiplyOp; }
	| "/"  { $$ = DivOp; }
	| "%"  { $$ = ModOp; };

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
