// A Bison parser, made by GNU Bison 3.5.2.

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
#line 21 "parser.y"

    #include "driver.hh"
    #include "location.hh"


    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }

#line 55 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"


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
#line 146 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"


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
      case 40: // "number"
      case 45: // binary_operator
      case 46: // expr
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case 39: // "identifier"
      case 47: // lvalue
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
      case 40: // "number"
      case 45: // binary_operator
      case 46: // expr
        value.move< int > (YY_MOVE (that.value));
        break;

      case 39: // "identifier"
      case 47: // lvalue
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
      case 40: // "number"
      case 45: // binary_operator
      case 46: // expr
        value.copy< int > (that.value);
        break;

      case 39: // "identifier"
      case 47: // lvalue
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
      case 40: // "number"
      case 45: // binary_operator
      case 46: // expr
        value.move< int > (that.value);
        break;

      case 39: // "identifier"
      case 47: // lvalue
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
      case 39: // "identifier"
#line 86 "parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 387 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
        break;

      case 40: // "number"
#line 86 "parser.y"
                 { yyo << yysym.value.template as < int > (); }
#line 393 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
        break;

      case 45: // binary_operator
#line 86 "parser.y"
                 { yyo << yysym.value.template as < int > (); }
#line 399 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
        break;

      case 46: // expr
#line 86 "parser.y"
                 { yyo << yysym.value.template as < int > (); }
#line 405 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
        break;

      case 47: // lvalue
#line 86 "parser.y"
                 { yyo << yysym.value.template as < std::string > (); }
#line 411 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
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
      case 40: // "number"
      case 45: // binary_operator
      case 46: // expr
        yylhs.value.emplace< int > ();
        break;

      case 39: // "identifier"
      case 47: // lvalue
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
#line 90 "parser.y"
                                    {}
#line 663 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 3:
#line 92 "parser.y"
                                                                           {}
#line 669 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 4:
#line 95 "parser.y"
               {}
#line 675 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 5:
#line 96 "parser.y"
                            {}
#line 681 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 6:
#line 99 "parser.y"
               {}
#line 687 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 7:
#line 100 "parser.y"
                               {}
#line 693 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 8:
#line 102 "parser.y"
                                                             {}
#line 699 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 9:
#line 103 "parser.y"
                                                                                 {}
#line 705 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 10:
#line 106 "parser.y"
               {}
#line 711 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 11:
#line 107 "parser.y"
                                   {}
#line 717 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 12:
#line 109 "parser.y"
                                  {}
#line 723 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 13:
#line 110 "parser.y"
                             {}
#line 729 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 14:
#line 112 "parser.y"
                                                                          {}
#line 735 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 15:
#line 113 "parser.y"
                                                                        {}
#line 741 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 16:
#line 115 "parser.y"
                                            {}
#line 747 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 17:
#line 117 "parser.y"
                                             {}
#line 753 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 18:
#line 120 "parser.y"
               {}
#line 759 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 19:
#line 121 "parser.y"
                                                  {}
#line 765 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 20:
#line 124 "parser.y"
                    {}
#line 771 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 21:
#line 125 "parser.y"
                     {}
#line 777 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 22:
#line 128 "parser.y"
              {}
#line 783 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 23:
#line 129 "parser.y"
                    {}
#line 789 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 24:
#line 130 "parser.y"
                 {}
#line 795 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 25:
#line 131 "parser.y"
                          {}
#line 801 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 26:
#line 134 "parser.y"
                            {}
#line 807 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 28:
#line 139 "parser.y"
                                     {}
#line 813 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 29:
#line 140 "parser.y"
                                           {}
#line 819 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 30:
#line 141 "parser.y"
                                   {}
#line 825 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 31:
#line 142 "parser.y"
                                             {}
#line 831 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 32:
#line 143 "parser.y"
                                                              {}
#line 837 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 33:
#line 144 "parser.y"
                                                 {}
#line 843 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 34:
#line 145 "parser.y"
                                         { std::cout << yystack_[2].value.as < int > () << "\n"; }
#line 849 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 35:
#line 146 "parser.y"
                                     { driver.variables[yystack_[3].value.as < std::string > ()] = yystack_[1].value.as < int > (); }
#line 855 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 36:
#line 147 "parser.y"
                                   { driver.result = yystack_[1].value.as < int > (); }
#line 861 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 37:
#line 148 "parser.y"
                                      {}
#line 867 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 38:
#line 150 "parser.y"
                                                 {}
#line 873 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 39:
#line 152 "parser.y"
                                                 {}
#line 879 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 40:
#line 153 "parser.y"
                                                                     {}
#line 885 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 41:
#line 156 "parser.y"
               {}
#line 891 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 42:
#line 157 "parser.y"
                                   {}
#line 897 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 43:
#line 161 "parser.y"
                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 903 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 44:
#line 162 "parser.y"
                                     {}
#line 909 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 45:
#line 164 "parser.y"
                                   {
		switch(yystack_[1].value.as < int > ()) {
			case AndOp:
				yylhs.value.as < int > () = yystack_[2].value.as < int > () && yystack_[0].value.as < int > ();
				break;
                        case OrOp:
				yylhs.value.as < int > () = yystack_[2].value.as < int > () || yystack_[0].value.as < int > ();
				break;
                        case LessOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () < yystack_[0].value.as < int > ();
                        	break;
                        case GreaterOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () > yystack_[0].value.as < int > ();
                        	break;
                        case EqualOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () == yystack_[0].value.as < int > ();
                        	break;
                        case AddOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () + yystack_[0].value.as < int > ();
                        	break;
                        case SubtractOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () - yystack_[0].value.as < int > ();
                        	break;
                        case MultiplyOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () * yystack_[0].value.as < int > ();
                        	break;
                        case DivOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () / yystack_[0].value.as < int > ();
                        	break;
                        case ModOp:
                        	yylhs.value.as < int > () = yystack_[2].value.as < int > () % yystack_[0].value.as < int > ();
                        	break;
		}
}
#line 948 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 46:
#line 198 "parser.y"
                             {}
#line 954 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 47:
#line 199 "parser.y"
                            {}
#line 960 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 48:
#line 200 "parser.y"
                                         {}
#line 966 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 49:
#line 201 "parser.y"
                                        {}
#line 972 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 50:
#line 202 "parser.y"
                   { yylhs.value.as < int > () = !(yystack_[0].value.as < int > ()); }
#line 978 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 51:
#line 203 "parser.y"
                       { yylhs.value.as < int > () = yystack_[1].value.as < int > (); }
#line 984 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 52:
#line 204 "parser.y"
                        { yylhs.value.as < int > () = driver.variables[yystack_[0].value.as < std::string > ()]; }
#line 990 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 53:
#line 205 "parser.y"
                    { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 996 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 54:
#line 206 "parser.y"
                 {}
#line 1002 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 55:
#line 207 "parser.y"
                 { yylhs.value.as < int > () = 1; }
#line 1008 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 56:
#line 208 "parser.y"
                  { yylhs.value.as < int > () = 0; }
#line 1014 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 57:
#line 209 "parser.y"
                            {}
#line 1020 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 58:
#line 213 "parser.y"
               { yylhs.value.as < int > () = AndOp; }
#line 1026 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 59:
#line 214 "parser.y"
                 { yylhs.value.as < int > () = OrOp; }
#line 1032 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 60:
#line 215 "parser.y"
                 { yylhs.value.as < int > () = LessOp; }
#line 1038 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 61:
#line 216 "parser.y"
                { yylhs.value.as < int > () = GreaterOp; }
#line 1044 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 62:
#line 217 "parser.y"
                  { yylhs.value.as < int > () = EqualOp; }
#line 1050 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 63:
#line 218 "parser.y"
                { yylhs.value.as < int > () = AddOp; }
#line 1056 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 64:
#line 219 "parser.y"
                { yylhs.value.as < int > () = SubtractOp; }
#line 1062 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 65:
#line 220 "parser.y"
               { yylhs.value.as < int > () = MultiplyOp; }
#line 1068 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 66:
#line 221 "parser.y"
               { yylhs.value.as < int > () = DivOp; }
#line 1074 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;

  case 67:
#line 222 "parser.y"
               { yylhs.value.as < int > () = ModOp; }
#line 1080 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"
    break;


#line 1084 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"

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


  const signed char parser::yypact_ninf_ = -105;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
     -13,   -33,    11,    -2,    32,  -105,    -8,  -105,  -105,    41,
      60,    17,  -105,    16,    18,     5,    59,    63,  -105,  -105,
    -105,  -105,    48,  -105,  -105,  -105,  -105,    36,    39,  -105,
    -105,  -105,  -105,    45,    69,    43,    53,   100,    52,  -105,
    -105,  -105,    54,    56,    20,  -105,  -105,    48,  -105,  -105,
      78,    57,    58,    20,    20,    30,  -105,   460,    79,  -105,
    -105,  -105,    81,    38,    20,    20,  -105,   268,  -105,    74,
      62,   138,  -105,    20,    20,   460,   362,    20,   -17,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    20,
      20,    20,  -105,    90,    80,    82,   378,   394,  -105,    20,
      85,  -105,   410,   426,  -105,   305,  -105,    83,   324,   460,
     289,  -105,   106,    84,   103,   111,   343,  -105,   252,   252,
    -105,     0,  -105,  -105,   176,  -105,    48,  -105,  -105,  -105,
    -105,   105,  -105,  -105,   442,  -105,   214,    91,   252,    20,
      93,  -105,    84,  -105,   442,  -105,  -105,  -105
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     4,     0,     1,     0,     2,     5,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     8,    22,
      23,    24,     0,    27,    11,    13,    12,     0,    20,    21,
      25,    10,     6,     0,     0,     0,     0,     0,     0,    16,
      26,     9,     0,     0,     0,    55,    56,     0,    54,     6,
       0,     0,     0,     0,     0,    52,    53,     0,     0,    38,
       7,    29,    57,     0,     0,     0,    52,     0,    57,     0,
      25,     0,     3,     0,     0,    50,     0,     0,     0,    58,
      59,    60,    61,    62,    64,    63,    65,    66,    67,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    36,     0,
       0,    30,     0,     0,    51,     0,    47,     0,     0,    45,
       0,     6,     0,    18,     0,     0,     0,    49,     0,     0,
      44,     0,    46,    35,     0,     6,     0,    17,    34,    28,
      48,    31,    33,    39,    41,    14,     0,     0,     0,     0,
       0,    15,    18,    32,    41,    40,    19,    42
  };

  const signed char
  parser::yypgoto_[] =
  {
    -105,  -105,   -41,  -105,  -105,  -105,  -105,   -47,  -105,    98,
    -105,  -105,     6,  -105,   -10,   -22,    86,  -105,    87,  -104,
    -105,   -36,    -9
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,    90,    57,    58,     2,     3,     7,    37,     8,    15,
      24,    25,    59,    94,   127,    27,    28,    29,    30,    60,
      61,    68,   140
  };

  const short
  parser::yytable_[] =
  {
      33,    62,    71,    67,   106,     1,     4,    45,    46,    47,
      48,     5,    75,    76,   131,   132,     6,    18,    19,    20,
      21,    26,   107,    96,    97,    22,    53,    45,    46,    47,
      48,    10,   102,   103,   143,    62,   105,    54,   133,    66,
      56,    95,    26,     9,    23,    11,    53,   -43,   108,   109,
     110,    19,    20,    21,    14,    16,    17,    54,   116,    66,
      56,    19,    20,    21,   124,    41,    19,    20,    21,   -27,
      31,    12,    77,    22,    32,    34,    93,    23,   136,    13,
     134,    35,    62,    62,    38,    39,    40,    23,    62,    63,
      72,    64,    23,    65,    73,    74,    91,    92,   144,   100,
      62,   111,    62,    42,   137,    43,    44,    45,    46,    47,
      48,    49,    50,    19,    20,    21,    99,   125,   112,   128,
     121,   113,    51,   117,    52,   126,    53,   129,   138,    36,
     142,   145,   146,    69,    70,   147,     0,    54,     0,    55,
      56,    42,     0,    43,    44,    45,    46,    47,    48,    49,
     101,    19,    20,    21,     0,     0,     0,     0,     0,     0,
      51,     0,    52,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,    55,    56,    42,
       0,    43,    44,    45,    46,    47,    48,    49,   135,    19,
      20,    21,     0,     0,     0,     0,     0,     0,    51,     0,
      52,     0,    53,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,    55,    56,    42,     0,    43,
      44,    45,    46,    47,    48,    49,   141,    19,    20,    21,
       0,     0,     0,     0,     0,     0,    51,     0,    52,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,    55,    56,    42,     0,    43,    44,    45,
      46,    47,    48,    49,     0,    19,    20,    21,     0,     0,
       0,     0,     0,     0,    51,     0,    52,     0,    53,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,    54,
       0,    55,    56,    78,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,   123,     0,     0,     0,     0,
      89,     0,     0,     0,    78,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
      78,    89,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,    89,   120,    78,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,    89,   122,    78,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,    89,   130,    78,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
     104,     0,     0,    78,    89,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,   114,     0,     0,    78,
      89,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     0,   115,     0,     0,    78,    89,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,   118,     0,
       0,    78,    89,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,   119,     0,     0,    78,    89,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,   139,    89,    78,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,    89
  };

  const short
  parser::yycheck_[] =
  {
      22,    37,    49,    44,    21,    18,    39,     7,     8,     9,
      10,     0,    53,    54,   118,   119,    18,    12,    13,    14,
      15,    15,    39,    64,    65,    20,    26,     7,     8,     9,
      10,    39,    73,    74,   138,    71,    77,    37,    38,    39,
      40,    63,    36,    11,    39,     4,    26,    17,    89,    90,
      91,    13,    14,    15,    37,    39,    38,    37,    99,    39,
      40,    13,    14,    15,   111,    12,    13,    14,    15,    39,
      11,    11,    42,    20,    11,    39,    38,    39,   125,    19,
     121,    42,   118,   119,    39,    16,    43,    39,   124,    37,
      12,    37,    39,    37,    37,    37,    17,    16,   139,    37,
     136,    11,   138,     3,   126,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    42,    11,    38,    16,
      37,    39,    22,    38,    24,    41,    26,    16,    23,    31,
      39,    38,   142,    47,    47,   144,    -1,    37,    -1,    39,
      40,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    40,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    40,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    40,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    37,
      -1,    39,    40,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    16,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      25,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    -1,    -1,    25,    42,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    -1,    -1,    25,
      42,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    -1,    -1,    25,    42,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    -1,
      -1,    25,    42,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    -1,    -1,    25,    42,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    41,    42,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    18,    48,    49,    39,     0,    18,    50,    52,    11,
      39,     4,    11,    19,    37,    53,    39,    38,    12,    13,
      14,    15,    20,    39,    54,    55,    56,    59,    60,    61,
      62,    11,    11,    59,    39,    42,    53,    51,    39,    16,
      43,    12,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    22,    24,    26,    37,    39,    40,    46,    47,    56,
      63,    64,    65,    37,    37,    37,    39,    46,    65,    60,
      62,    51,    12,    37,    37,    46,    46,    42,    25,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    42,
      45,    17,    16,    38,    57,    59,    46,    46,    16,    42,
      37,    12,    46,    46,    38,    46,    21,    39,    46,    46,
      46,    11,    38,    39,    38,    38,    46,    38,    38,    38,
      43,    37,    43,    16,    51,    11,    41,    58,    16,    16,
      43,    63,    63,    38,    46,    12,    51,    59,    23,    41,
      66,    12,    39,    63,    46,    38,    58,    66
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    44,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    57,    58,    58,
      59,    59,    60,    60,    60,    60,    61,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      65,    66,    66,    47,    47,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,    10,     0,     1,     0,     2,     5,     7,
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
  "\"(\"", "\")\"", "\"identifier\"", "\"number\"", "\",\"", "\"[\"",
  "\"]\"", "$accept", "binary_operator", "expr", "lvalue", "unit",
  "main_class", "class_declarations", "statements", "class_declaration",
  "declarations", "declaration", "method_declaration",
  "variable_declaration", "formals", "following_formals", "type",
  "simple_type", "array_type", "type_identifier", "statement",
  "local_variable_declaration", "method_invocation", "following_exprs", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    90,    90,    92,    95,    96,    99,   100,   102,   103,
     106,   107,   109,   110,   112,   113,   115,   117,   120,   121,
     124,   125,   128,   129,   130,   131,   134,   137,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   150,   152,
     153,   156,   157,   161,   162,   164,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222
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
#line 1637 "/home/timur/CLionProjects/CompilersCourse/02-parsers/parser.cpp"

#line 232 "parser.y"


void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
