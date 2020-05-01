// A Bison parser, made by GNU Bison 3.5.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 24 "parser.y"

    #include "driver.hh"
    #include "location.hh"

    #include "elements.h"


    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 57 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 148 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 60: // array_type
        value.YY_MOVE_OR_COPY< ArrayType* > (YY_MOVE (that.value));
        break;

      case 66: // binary_operator
        value.YY_MOVE_OR_COPY< BinaryOperator* > (YY_MOVE (that.value));
        break;

      case 49: // class_declaration
        value.YY_MOVE_OR_COPY< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 48: // class_declarations
        value.YY_MOVE_OR_COPY< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 53: // declaration
        value.YY_MOVE_OR_COPY< Declaration* > (YY_MOVE (that.value));
        break;

      case 52: // declarations
        value.YY_MOVE_OR_COPY< DeclarationList* > (YY_MOVE (that.value));
        break;

      case 45: // expr
        value.YY_MOVE_OR_COPY< Expression* > (YY_MOVE (that.value));
        break;

      case 64: // following_exprs
        value.YY_MOVE_OR_COPY< ExpressionList* > (YY_MOVE (that.value));
        break;

      case 57: // formals
      case 58: // following_formals
        value.YY_MOVE_OR_COPY< FormalList* > (YY_MOVE (that.value));
        break;

      case 62: // local_variable_declaration
        value.YY_MOVE_OR_COPY< LocalVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 65: // lvalue
        value.YY_MOVE_OR_COPY< Lvalue* > (YY_MOVE (that.value));
        break;

      case 47: // main_class
        value.YY_MOVE_OR_COPY< MainClass* > (YY_MOVE (that.value));
        break;

      case 55: // method_declaration
        value.YY_MOVE_OR_COPY< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 63: // method_invocation
        value.YY_MOVE_OR_COPY< MethodInvokation* > (YY_MOVE (that.value));
        break;

      case 46: // unit
        value.YY_MOVE_OR_COPY< Program* > (YY_MOVE (that.value));
        break;

      case 59: // simple_type
        value.YY_MOVE_OR_COPY< SimpleType* > (YY_MOVE (that.value));
        break;

      case 51: // statement
        value.YY_MOVE_OR_COPY< Statement* > (YY_MOVE (that.value));
        break;

      case 50: // statements
        value.YY_MOVE_OR_COPY< StatementList* > (YY_MOVE (that.value));
        break;

      case 56: // type
        value.YY_MOVE_OR_COPY< Type* > (YY_MOVE (that.value));
        break;

      case 61: // type_identifier
        value.YY_MOVE_OR_COPY< TypeIdentifier* > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
        value.YY_MOVE_OR_COPY< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 43: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 42: // "identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 60: // array_type
        value.move< ArrayType* > (YY_MOVE (that.value));
        break;

      case 66: // binary_operator
        value.move< BinaryOperator* > (YY_MOVE (that.value));
        break;

      case 49: // class_declaration
        value.move< ClassDeclaration* > (YY_MOVE (that.value));
        break;

      case 48: // class_declarations
        value.move< ClassDeclarationList* > (YY_MOVE (that.value));
        break;

      case 53: // declaration
        value.move< Declaration* > (YY_MOVE (that.value));
        break;

      case 52: // declarations
        value.move< DeclarationList* > (YY_MOVE (that.value));
        break;

      case 45: // expr
        value.move< Expression* > (YY_MOVE (that.value));
        break;

      case 64: // following_exprs
        value.move< ExpressionList* > (YY_MOVE (that.value));
        break;

      case 57: // formals
      case 58: // following_formals
        value.move< FormalList* > (YY_MOVE (that.value));
        break;

      case 62: // local_variable_declaration
        value.move< LocalVariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 65: // lvalue
        value.move< Lvalue* > (YY_MOVE (that.value));
        break;

      case 47: // main_class
        value.move< MainClass* > (YY_MOVE (that.value));
        break;

      case 55: // method_declaration
        value.move< MethodDeclaration* > (YY_MOVE (that.value));
        break;

      case 63: // method_invocation
        value.move< MethodInvokation* > (YY_MOVE (that.value));
        break;

      case 46: // unit
        value.move< Program* > (YY_MOVE (that.value));
        break;

      case 59: // simple_type
        value.move< SimpleType* > (YY_MOVE (that.value));
        break;

      case 51: // statement
        value.move< Statement* > (YY_MOVE (that.value));
        break;

      case 50: // statements
        value.move< StatementList* > (YY_MOVE (that.value));
        break;

      case 56: // type
        value.move< Type* > (YY_MOVE (that.value));
        break;

      case 61: // type_identifier
        value.move< TypeIdentifier* > (YY_MOVE (that.value));
        break;

      case 54: // variable_declaration
        value.move< VariableDeclaration* > (YY_MOVE (that.value));
        break;

      case 43: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case 42: // "identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 60: // array_type
        value.copy< ArrayType* > (that.value);
        break;

      case 66: // binary_operator
        value.copy< BinaryOperator* > (that.value);
        break;

      case 49: // class_declaration
        value.copy< ClassDeclaration* > (that.value);
        break;

      case 48: // class_declarations
        value.copy< ClassDeclarationList* > (that.value);
        break;

      case 53: // declaration
        value.copy< Declaration* > (that.value);
        break;

      case 52: // declarations
        value.copy< DeclarationList* > (that.value);
        break;

      case 45: // expr
        value.copy< Expression* > (that.value);
        break;

      case 64: // following_exprs
        value.copy< ExpressionList* > (that.value);
        break;

      case 57: // formals
      case 58: // following_formals
        value.copy< FormalList* > (that.value);
        break;

      case 62: // local_variable_declaration
        value.copy< LocalVariableDeclaration* > (that.value);
        break;

      case 65: // lvalue
        value.copy< Lvalue* > (that.value);
        break;

      case 47: // main_class
        value.copy< MainClass* > (that.value);
        break;

      case 55: // method_declaration
        value.copy< MethodDeclaration* > (that.value);
        break;

      case 63: // method_invocation
        value.copy< MethodInvokation* > (that.value);
        break;

      case 46: // unit
        value.copy< Program* > (that.value);
        break;

      case 59: // simple_type
        value.copy< SimpleType* > (that.value);
        break;

      case 51: // statement
        value.copy< Statement* > (that.value);
        break;

      case 50: // statements
        value.copy< StatementList* > (that.value);
        break;

      case 56: // type
        value.copy< Type* > (that.value);
        break;

      case 61: // type_identifier
        value.copy< TypeIdentifier* > (that.value);
        break;

      case 54: // variable_declaration
        value.copy< VariableDeclaration* > (that.value);
        break;

      case 43: // "number"
        value.copy< int > (that.value);
        break;

      case 42: // "identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 60: // array_type
        value.move< ArrayType* > (that.value);
        break;

      case 66: // binary_operator
        value.move< BinaryOperator* > (that.value);
        break;

      case 49: // class_declaration
        value.move< ClassDeclaration* > (that.value);
        break;

      case 48: // class_declarations
        value.move< ClassDeclarationList* > (that.value);
        break;

      case 53: // declaration
        value.move< Declaration* > (that.value);
        break;

      case 52: // declarations
        value.move< DeclarationList* > (that.value);
        break;

      case 45: // expr
        value.move< Expression* > (that.value);
        break;

      case 64: // following_exprs
        value.move< ExpressionList* > (that.value);
        break;

      case 57: // formals
      case 58: // following_formals
        value.move< FormalList* > (that.value);
        break;

      case 62: // local_variable_declaration
        value.move< LocalVariableDeclaration* > (that.value);
        break;

      case 65: // lvalue
        value.move< Lvalue* > (that.value);
        break;

      case 47: // main_class
        value.move< MainClass* > (that.value);
        break;

      case 55: // method_declaration
        value.move< MethodDeclaration* > (that.value);
        break;

      case 63: // method_invocation
        value.move< MethodInvokation* > (that.value);
        break;

      case 46: // unit
        value.move< Program* > (that.value);
        break;

      case 59: // simple_type
        value.move< SimpleType* > (that.value);
        break;

      case 51: // statement
        value.move< Statement* > (that.value);
        break;

      case 50: // statements
        value.move< StatementList* > (that.value);
        break;

      case 56: // type
        value.move< Type* > (that.value);
        break;

      case 61: // type_identifier
        value.move< TypeIdentifier* > (that.value);
        break;

      case 54: // variable_declaration
        value.move< VariableDeclaration* > (that.value);
        break;

      case 43: // "number"
        value.move< int > (that.value);
        break;

      case 42: // "identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 42: // "identifier"
#line 114 "parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 717 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 43: // "number"
#line 114 "parser.y"
                 { yyo << yysym.value.template as < int > (); }
#line 723 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 45: // expr
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Expression* > (); }
#line 729 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 46: // unit
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Program* > (); }
#line 735 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 47: // main_class
#line 114 "parser.y"
                 { yyo << yysym.value.template as < MainClass* > (); }
#line 741 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 48: // class_declarations
#line 114 "parser.y"
                 { yyo << yysym.value.template as < ClassDeclarationList* > (); }
#line 747 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 49: // class_declaration
#line 114 "parser.y"
                 { yyo << yysym.value.template as < ClassDeclaration* > (); }
#line 753 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 50: // statements
#line 114 "parser.y"
                 { yyo << yysym.value.template as < StatementList* > (); }
#line 759 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 51: // statement
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Statement* > (); }
#line 765 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 52: // declarations
#line 114 "parser.y"
                 { yyo << yysym.value.template as < DeclarationList* > (); }
#line 771 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 53: // declaration
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Declaration* > (); }
#line 777 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 54: // variable_declaration
#line 114 "parser.y"
                 { yyo << yysym.value.template as < VariableDeclaration* > (); }
#line 783 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 55: // method_declaration
#line 114 "parser.y"
                 { yyo << yysym.value.template as < MethodDeclaration* > (); }
#line 789 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 56: // type
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Type* > (); }
#line 795 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 57: // formals
#line 114 "parser.y"
                 { yyo << yysym.value.template as < FormalList* > (); }
#line 801 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 58: // following_formals
#line 114 "parser.y"
                 { yyo << yysym.value.template as < FormalList* > (); }
#line 807 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 59: // simple_type
#line 114 "parser.y"
                 { yyo << yysym.value.template as < SimpleType* > (); }
#line 813 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 60: // array_type
#line 114 "parser.y"
                 { yyo << yysym.value.template as < ArrayType* > (); }
#line 819 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 61: // type_identifier
#line 114 "parser.y"
                 { yyo << yysym.value.template as < TypeIdentifier* > (); }
#line 825 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 62: // local_variable_declaration
#line 114 "parser.y"
                 { yyo << yysym.value.template as < LocalVariableDeclaration* > (); }
#line 831 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 63: // method_invocation
#line 114 "parser.y"
                 { yyo << yysym.value.template as < MethodInvokation* > (); }
#line 837 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 64: // following_exprs
#line 114 "parser.y"
                 { yyo << yysym.value.template as < ExpressionList* > (); }
#line 843 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 65: // lvalue
#line 114 "parser.y"
                 { yyo << yysym.value.template as < Lvalue* > (); }
#line 849 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      case 66: // binary_operator
#line 114 "parser.y"
                 { yyo << yysym.value.template as < BinaryOperator* > (); }
#line 855 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
        break;

      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, driver));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 60: // array_type
        yylhs.value.emplace< ArrayType* > ();
        break;

      case 66: // binary_operator
        yylhs.value.emplace< BinaryOperator* > ();
        break;

      case 49: // class_declaration
        yylhs.value.emplace< ClassDeclaration* > ();
        break;

      case 48: // class_declarations
        yylhs.value.emplace< ClassDeclarationList* > ();
        break;

      case 53: // declaration
        yylhs.value.emplace< Declaration* > ();
        break;

      case 52: // declarations
        yylhs.value.emplace< DeclarationList* > ();
        break;

      case 45: // expr
        yylhs.value.emplace< Expression* > ();
        break;

      case 64: // following_exprs
        yylhs.value.emplace< ExpressionList* > ();
        break;

      case 57: // formals
      case 58: // following_formals
        yylhs.value.emplace< FormalList* > ();
        break;

      case 62: // local_variable_declaration
        yylhs.value.emplace< LocalVariableDeclaration* > ();
        break;

      case 65: // lvalue
        yylhs.value.emplace< Lvalue* > ();
        break;

      case 47: // main_class
        yylhs.value.emplace< MainClass* > ();
        break;

      case 55: // method_declaration
        yylhs.value.emplace< MethodDeclaration* > ();
        break;

      case 63: // method_invocation
        yylhs.value.emplace< MethodInvokation* > ();
        break;

      case 46: // unit
        yylhs.value.emplace< Program* > ();
        break;

      case 59: // simple_type
        yylhs.value.emplace< SimpleType* > ();
        break;

      case 51: // statement
        yylhs.value.emplace< Statement* > ();
        break;

      case 50: // statements
        yylhs.value.emplace< StatementList* > ();
        break;

      case 56: // type
        yylhs.value.emplace< Type* > ();
        break;

      case 61: // type_identifier
        yylhs.value.emplace< TypeIdentifier* > ();
        break;

      case 54: // variable_declaration
        yylhs.value.emplace< VariableDeclaration* > ();
        break;

      case 43: // "number"
        yylhs.value.emplace< int > ();
        break;

      case 42: // "identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 118 "parser.y"
                                    { yylhs.value.as < Program* > () = new Program(yystack_[1].value.as < MainClass* > (), yystack_[0].value.as < ClassDeclarationList* > ()); driver.program = yylhs.value.as < Program* > (); }
#line 1189 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 3:
#line 120 "parser.y"
                                                                           { yylhs.value.as < MainClass* > () = new MainClass(yystack_[8].value.as < std::string > (), yystack_[2].value.as < StatementList* > ()); }
#line 1195 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 4:
#line 123 "parser.y"
               { yylhs.value.as < ClassDeclarationList* > () = new ClassDeclarationList(); }
#line 1201 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 5:
#line 124 "parser.y"
                                               { yystack_[1].value.as < ClassDeclarationList* > ()->AddClassDeclaration(yystack_[0].value.as < ClassDeclaration* > ()); yylhs.value.as < ClassDeclarationList* > () = yystack_[1].value.as < ClassDeclarationList* > (); }
#line 1207 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 6:
#line 127 "parser.y"
               { yylhs.value.as < StatementList* > () = new StatementList(); }
#line 1213 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 7:
#line 128 "parser.y"
                               { yystack_[1].value.as < StatementList* > ()->AddStatement(yystack_[0].value.as < Statement* > ()); yylhs.value.as < StatementList* > () = yystack_[1].value.as < StatementList* > (); }
#line 1219 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 8:
#line 130 "parser.y"
                                                             { yylhs.value.as < ClassDeclaration* > () = new ClassDeclaration(yystack_[3].value.as < std::string > (), yystack_[1].value.as < DeclarationList* > ()); }
#line 1225 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 9:
#line 131 "parser.y"
                                                                                 { yylhs.value.as < ClassDeclaration* > () = new ClassDeclaration(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < DeclarationList* > ()); }
#line 1231 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 10:
#line 133 "parser.y"
                       { yylhs.value.as < DeclarationList* > () = new DeclarationList(); }
#line 1237 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 11:
#line 134 "parser.y"
                                   { yystack_[1].value.as < DeclarationList* > ()->AddDeclaration(yystack_[0].value.as < Declaration* > ()); yylhs.value.as < DeclarationList* > () = yystack_[1].value.as < DeclarationList* > (); }
#line 1243 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 12:
#line 136 "parser.y"
                                  { yylhs.value.as < Declaration* > () = new Declaration(yystack_[0].value.as < VariableDeclaration* > ()); }
#line 1249 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 13:
#line 137 "parser.y"
                             { yylhs.value.as < Declaration* > () = new Declaration(yystack_[0].value.as < MethodDeclaration* > ()); }
#line 1255 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 14:
#line 139 "parser.y"
                                                                          { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[6].value.as < Type* > (), yystack_[5].value.as < std::string > (), yystack_[1].value.as < StatementList* > ()); }
#line 1261 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 15:
#line 140 "parser.y"
                                                                        { yylhs.value.as < MethodDeclaration* > () = new MethodDeclaration(yystack_[7].value.as < Type* > (), yystack_[6].value.as < std::string > (), yystack_[4].value.as < FormalList* > (), yystack_[1].value.as < StatementList* > ()); }
#line 1267 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 16:
#line 142 "parser.y"
                                            { yylhs.value.as < VariableDeclaration* > () = new VariableDeclaration(yystack_[2].value.as < Type* > (), yystack_[1].value.as < std::string > ()); }
#line 1273 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 17:
#line 144 "parser.y"
                                             { yystack_[0].value.as < FormalList* > ()->AddFormal(yystack_[2].value.as < Type* > (), yystack_[1].value.as < std::string > ()); yylhs.value.as < FormalList* > () = yystack_[0].value.as < FormalList* > (); }
#line 1279 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 18:
#line 147 "parser.y"
               { yylhs.value.as < FormalList* > () = new FormalList(); }
#line 1285 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 19:
#line 148 "parser.y"
                                                  { yystack_[0].value.as < FormalList* > ()->AddFormal(yystack_[2].value.as < Type* > (), yystack_[1].value.as < std::string > ()); yylhs.value.as < FormalList* > () = yystack_[0].value.as < FormalList* > (); }
#line 1291 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 20:
#line 151 "parser.y"
                    { yylhs.value.as < Type* > () = new Type(yystack_[0].value.as < SimpleType* > ()); }
#line 1297 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 21:
#line 152 "parser.y"
                     { yylhs.value.as < Type* > () = new Type(yystack_[0].value.as < ArrayType* > ()); }
#line 1303 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 22:
#line 155 "parser.y"
              { yylhs.value.as < SimpleType* > () = new SimpleType("int"); }
#line 1309 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 23:
#line 156 "parser.y"
                    { yylhs.value.as < SimpleType* > () = new SimpleType("boolean"); }
#line 1315 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 24:
#line 157 "parser.y"
                 { yylhs.value.as < SimpleType* > () = new SimpleType("void"); }
#line 1321 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 25:
#line 158 "parser.y"
                          { yylhs.value.as < SimpleType* > () = new SimpleType(yystack_[0].value.as < TypeIdentifier* > ()); }
#line 1327 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 26:
#line 161 "parser.y"
                            { yylhs.value.as < ArrayType* > () = new ArrayType(yystack_[2].value.as < SimpleType* > ()); }
#line 1333 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 27:
#line 164 "parser.y"
                     { yylhs.value.as < TypeIdentifier* > () = new TypeIdentifier(yystack_[0].value.as < std::string > ()); }
#line 1339 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 28:
#line 166 "parser.y"
                                     { yylhs.value.as < Statement* > () = new AssertStatement(yystack_[2].value.as < Expression* > ()); }
#line 1345 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 29:
#line 167 "parser.y"
                                           { yylhs.value.as < Statement* > () = new LocalVariableDeclarationStatement(yystack_[0].value.as < LocalVariableDeclaration* > ()); }
#line 1351 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 30:
#line 168 "parser.y"
                                   { yylhs.value.as < Statement* > () = new ScopeStatement(yystack_[1].value.as < StatementList* > ()); }
#line 1357 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 31:
#line 169 "parser.y"
                                             { yylhs.value.as < Statement* > () = new IfStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1363 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 32:
#line 170 "parser.y"
                                                              { yylhs.value.as < Statement* > () = new IfElseStatement(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < Statement* > (), yystack_[0].value.as < Statement* > ()); }
#line 1369 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 33:
#line 171 "parser.y"
                                                 { yylhs.value.as < Statement* > () = new WhileStatement(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Statement* > ()); }
#line 1375 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 34:
#line 172 "parser.y"
                                         { yylhs.value.as < Statement* > () = new SoutStatement(yystack_[2].value.as < Expression* > ()); }
#line 1381 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 35:
#line 173 "parser.y"
                                     { yylhs.value.as < Statement* > () = new DefinitionStatement(yystack_[3].value.as < Lvalue* > (), yystack_[1].value.as < Expression* > ()); }
#line 1387 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 36:
#line 174 "parser.y"
                                   { yylhs.value.as < Statement* > () = new ReturnStatement(yystack_[1].value.as < Expression* > ()); }
#line 1393 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 37:
#line 175 "parser.y"
                                      { yylhs.value.as < Statement* > () = new MethodInvokationStatement(yystack_[1].value.as < MethodInvokation* > ()); }
#line 1399 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 38:
#line 177 "parser.y"
                                                 { yylhs.value.as < LocalVariableDeclaration* > () = new LocalVariableDeclaration(yystack_[0].value.as < VariableDeclaration* > ()); }
#line 1405 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 39:
#line 179 "parser.y"
                                                 { yylhs.value.as < MethodInvokation* > () = new MethodInvokation(yystack_[4].value.as < Expression* > (), yystack_[2].value.as < std::string > ()); }
#line 1411 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 40:
#line 180 "parser.y"
                                                                     { yylhs.value.as < MethodInvokation* > () = new MethodInvokation(yystack_[6].value.as < Expression* > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < Expression* > (), yystack_[1].value.as < ExpressionList* > ()); }
#line 1417 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 41:
#line 183 "parser.y"
               { yylhs.value.as < ExpressionList* > () = new ExpressionList(); }
#line 1423 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 42:
#line 184 "parser.y"
                                   { yystack_[0].value.as < ExpressionList* > ()->AddExpression(yystack_[1].value.as < Expression* > ()); yylhs.value.as < ExpressionList* > () = yystack_[0].value.as < ExpressionList* > (); }
#line 1429 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 43:
#line 188 "parser.y"
                     { yylhs.value.as < Lvalue* > () = new SimpleLvalue(yystack_[0].value.as < std::string > ()); }
#line 1435 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 44:
#line 189 "parser.y"
                                     {
	 yylhs.value.as < Lvalue* > () = new ArrayLvalue(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Expression* > ());
	  }
#line 1443 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 45:
#line 193 "parser.y"
                                   {
		yylhs.value.as < Expression* > () = new BinaryExpression(yystack_[2].value.as < Expression* > (), yystack_[0].value.as < Expression* > (), yystack_[1].value.as < BinaryOperator* > ());
}
#line 1451 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 46:
#line 196 "parser.y"
                             {
		yylhs.value.as < Expression* > () = new ArrayElementExpression(yystack_[3].value.as < Expression* > (), yystack_[1].value.as < Expression* > ());
	}
#line 1459 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 47:
#line 199 "parser.y"
                            {
		yylhs.value.as < Expression* > () = new ArrayLengthExpression(yystack_[2].value.as < Expression* > ());
	}
#line 1467 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 48:
#line 202 "parser.y"
                                         {
		yylhs.value.as < Expression* > () = new ArrayExpression(yystack_[3].value.as < SimpleType* > (), yystack_[1].value.as < Expression* > ());
	}
#line 1475 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 49:
#line 205 "parser.y"
                                        {
		yylhs.value.as < Expression* > () = new ObjectExpression(yystack_[2].value.as < TypeIdentifier* > ());
	}
#line 1483 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 50:
#line 208 "parser.y"
                   { yylhs.value.as < Expression* > () = new NotExpression(yystack_[0].value.as < Expression* > ()); }
#line 1489 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 51:
#line 209 "parser.y"
                       { yylhs.value.as < Expression* > () = new ParenthesesExpression(yystack_[1].value.as < Expression* > ()); }
#line 1495 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 52:
#line 210 "parser.y"
                        { yylhs.value.as < Expression* > () = new IdentExpression(yystack_[0].value.as < std::string > ()); }
#line 1501 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 53:
#line 211 "parser.y"
                    { yylhs.value.as < Expression* > () = new NumberExpression(yystack_[0].value.as < int > ()); }
#line 1507 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 54:
#line 212 "parser.y"
                 { yylhs.value.as < Expression* > () = new ThisExpression("this"); }
#line 1513 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 55:
#line 213 "parser.y"
                 { yylhs.value.as < Expression* > () = new BoolExpression("true"); }
#line 1519 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 56:
#line 214 "parser.y"
                  { yylhs.value.as < Expression* > () = new BoolExpression("false"); }
#line 1525 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 57:
#line 215 "parser.y"
                            { yylhs.value.as < Expression* > () = new MethodInvokationExpression(yystack_[0].value.as < MethodInvokation* > ()); }
#line 1531 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 58:
#line 219 "parser.y"
               { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(AndOp); }
#line 1537 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 59:
#line 220 "parser.y"
                 { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(OrOp); }
#line 1543 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 60:
#line 221 "parser.y"
                 { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(LessOp); }
#line 1549 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 61:
#line 222 "parser.y"
                { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(GreaterOp); }
#line 1555 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 62:
#line 223 "parser.y"
                  { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(EqualOp); }
#line 1561 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 63:
#line 224 "parser.y"
                { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(AddOp); }
#line 1567 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 64:
#line 225 "parser.y"
                { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(SubtractOp); }
#line 1573 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 65:
#line 226 "parser.y"
               { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(MultiplyOp); }
#line 1579 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 66:
#line 227 "parser.y"
               { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(DivOp); }
#line 1585 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;

  case 67:
#line 228 "parser.y"
               { yylhs.value.as < BinaryOperator* > () = new BinaryOperator(ModOp); }
#line 1591 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"
    break;


#line 1595 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -55;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
     -12,   -35,     9,   -55,    10,   -55,   -10,    15,   -22,   -55,
     -15,    14,    25,   -55,   -19,    36,    29,    55,   -55,   -55,
     -55,   -55,   -55,    43,   -55,   -55,   -55,   -55,    26,    28,
     -55,   -55,   -55,   107,    35,    54,    46,    60,    50,    51,
      22,   -55,   -55,    43,   -55,   -55,    77,    53,    56,    22,
      22,    37,   -55,   446,   -55,   -55,   -55,    76,    78,    57,
     -55,   -55,   -55,    22,    22,   -55,   274,   -55,    58,    59,
     148,   -55,    22,    22,   446,   371,    22,   -18,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    22,    22,
     -55,    22,    -3,   386,   401,   -55,    22,    63,   -55,   416,
     431,   -55,   323,   -55,    61,   339,   446,   295,    93,    64,
      67,    91,    95,   355,   -55,   255,   255,   -55,     8,   -55,
     -55,   -55,    82,   113,   -55,   -55,   -55,   102,   -55,   -55,
     308,   189,    43,   -55,   -55,   255,    22,    88,   -55,    85,
     230,   -55,   308,   -55,    82,   -55,   -55,   -55
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     4,     0,     1,     2,     0,     0,     5,
       0,     0,     0,    10,     0,     0,     0,     0,     6,     8,
      22,    23,    24,     0,    27,    11,    12,    13,     0,    20,
      21,    25,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,     0,    54,     6,     0,     0,     0,     0,
       0,    52,    53,     0,     7,    38,    29,    57,     0,     0,
      16,    26,     9,     0,     0,    52,     0,    57,     0,    25,
       0,     3,     0,     0,    50,     0,     0,     0,    58,    59,
      60,    61,    62,    64,    63,    65,    66,    67,     0,     0,
      37,     0,     0,     0,     0,    36,     0,     0,    30,     0,
       0,    51,     0,    47,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,    44,     0,    46,
      35,     6,    18,     0,    34,    28,    48,    31,    33,    39,
      41,     0,     0,    17,     6,     0,     0,     0,    14,     0,
       0,    32,    41,    40,    18,    15,    42,    19
  };

  const signed char
  parser::yypgoto_[] =
  {
     -55,   -36,   -55,   -55,   -55,   -55,   -43,   -54,    96,   -55,
     -11,   -55,   -23,   -55,   -14,    89,   -55,    92,   -55,   -32,
      -8,   -55,   -55
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    53,     2,     3,     6,     9,    33,    54,    16,    25,
      55,    27,    28,   110,   133,    29,    30,    31,    56,    67,
     137,    58,    89
  };

  const short
  parser::yytable_[] =
  {
      34,    57,    70,   103,    66,    26,     1,     4,     8,     5,
      20,    21,    22,    74,    75,    41,    42,    43,    44,    10,
      11,     7,    12,    17,   104,    13,    26,    93,    94,    41,
      42,    43,    44,    14,    49,   108,    99,   100,    57,    24,
     102,    19,    20,    21,    22,    50,   129,    18,    49,    23,
      65,    52,   105,   106,   -43,   107,    20,    21,    22,    50,
     113,   127,   128,    15,    65,    52,    32,    36,    35,   109,
      60,    24,    62,    20,    21,    22,    76,    59,   131,   -27,
      23,   141,   130,    57,    57,    24,    61,    63,    64,    71,
      72,   140,    90,    73,    92,    91,    97,    96,   118,    57,
     142,   114,    24,    57,   121,   123,   122,   124,    57,   139,
      38,   125,    39,    40,    41,    42,    43,    44,    45,    46,
      20,    21,    22,   132,   134,   135,   143,   144,    37,    47,
     147,    48,    68,    49,   146,    69,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,    51,
      52,    38,     0,    39,    40,    41,    42,    43,    44,    45,
      98,    20,    21,    22,     0,     0,     0,     0,     0,     0,
      47,     0,    48,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,     0,     0,
      51,    52,    38,     0,    39,    40,    41,    42,    43,    44,
      45,   138,    20,    21,    22,     0,     0,     0,     0,     0,
       0,    47,     0,    48,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
       0,    51,    52,    38,     0,    39,    40,    41,    42,    43,
      44,    45,   145,    20,    21,    22,     0,     0,     0,     0,
       0,     0,    47,     0,    48,     0,    49,     0,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    50,    20,    21,
      22,     0,    51,    52,     0,     0,     0,    47,     0,    48,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,    50,     0,     0,     0,     0,    51,    52,    77,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,   120,     0,    88,     0,     0,     0,     0,     0,     0,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,    77,    88,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,    88,    77,   136,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,    88,   117,    77,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,    88,   119,
      77,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    88,   126,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,   101,
      88,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,   111,    88,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,   112,
      88,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,   115,    88,    77,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,   116,
      88,    77,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,    88
  };

  const short
  parser::yycheck_[] =
  {
      23,    33,    45,    21,    40,    16,    18,    42,    18,     0,
      13,    14,    15,    49,    50,     7,     8,     9,    10,     4,
      42,    11,    37,    42,    42,    11,    37,    63,    64,     7,
       8,     9,    10,    19,    26,    38,    72,    73,    70,    42,
      76,    12,    13,    14,    15,    37,    38,    11,    26,    20,
      42,    43,    88,    89,    17,    91,    13,    14,    15,    37,
      96,   115,   116,    38,    42,    43,    11,    39,    42,    92,
      16,    42,    12,    13,    14,    15,    39,    42,   121,    42,
      20,   135,   118,   115,   116,    42,    40,    37,    37,    12,
      37,   134,    16,    37,    37,    17,    37,    39,    37,   131,
     136,    38,    42,   135,    11,    38,    42,    16,   140,   132,
       3,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    41,    11,    23,    38,    42,    32,    22,
     144,    24,    43,    26,   142,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    42,
      43,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      42,    43,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    42,    43,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,    -1,    26,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    37,    13,    14,
      15,    -1,    42,    43,    -1,    -1,    -1,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    16,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    25,    39,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    25,    41,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    40,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    40,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    40,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39
  };

  const signed char
  parser::yystos_[] =
  {
       0,    18,    46,    47,    42,     0,    48,    11,    18,    49,
       4,    42,    37,    11,    19,    38,    52,    42,    11,    12,
      13,    14,    15,    20,    42,    53,    54,    55,    56,    59,
      60,    61,    11,    50,    56,    42,    39,    52,     3,     5,
       6,     7,     8,     9,    10,    11,    12,    22,    24,    26,
      37,    42,    43,    45,    51,    54,    62,    63,    65,    42,
      16,    40,    12,    37,    37,    42,    45,    63,    59,    61,
      50,    12,    37,    37,    45,    45,    39,    25,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    39,    66,
      16,    17,    37,    45,    45,    16,    39,    37,    12,    45,
      45,    38,    45,    21,    42,    45,    45,    45,    38,    56,
      57,    38,    38,    45,    38,    38,    38,    40,    37,    40,
      16,    11,    42,    38,    16,    16,    40,    51,    51,    38,
      45,    50,    41,    58,    11,    23,    41,    64,    12,    56,
      50,    51,    45,    38,    42,    12,    64,    58
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    46,    47,    48,    48,    50,    50,    49,    49,
      52,    52,    53,    53,    55,    55,    54,    57,    58,    58,
      56,    56,    59,    59,    59,    59,    60,    61,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    62,    63,
      63,    64,    64,    65,    65,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    10,     0,     2,     0,     2,     5,     7,
       0,     2,     1,     1,     8,     9,     3,     3,     0,     4,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     1,
       3,     5,     7,     5,     5,     4,     3,     2,     1,     5,
       7,     0,     3,     1,     4,     3,     4,     3,     5,     4,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"sout\"", "\"psvm\"",
  "\"assert\"", "\"return\"", "\"true\"", "\"false\"", "\"new\"",
  "\"this\"", "\"{\"", "\"}\"", "\"int\"", "\"boolean\"", "\"void\"",
  "\";\"", "\"=\"", "\"class\"", "\"extends\"", "\"public\"", "\"length\"",
  "\"if\"", "\"else\"", "\"while\"", "\".\"", "\"!\"", "\"&&\"", "\"||\"",
  "\"<\"", "\">\"", "\"==\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\",\"", "\"identifier\"",
  "\"number\"", "$accept", "expr", "unit", "main_class",
  "class_declarations", "class_declaration", "statements", "statement",
  "declarations", "declaration", "variable_declaration",
  "method_declaration", "type", "formals", "following_formals",
  "simple_type", "array_type", "type_identifier",
  "local_variable_declaration", "method_invocation", "following_exprs",
  "lvalue", "binary_operator", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   118,   118,   120,   123,   124,   127,   128,   130,   131,
     133,   134,   136,   137,   139,   140,   142,   144,   147,   148,
     151,   152,   155,   156,   157,   158,   161,   164,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   177,   179,
     180,   183,   184,   188,   189,   193,   196,   199,   202,   205,
     208,   209,   210,   211,   212,   213,   214,   215,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2145 "/home/timur/CLionProjects/untitled9/02-parsers/parser.cpp"

#line 238 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
