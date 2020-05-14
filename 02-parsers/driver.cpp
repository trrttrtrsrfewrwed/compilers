#include "driver.hh"
#include "parser.hh"
#include <irtree/visitors/DoubleCallEliminateVisitor.h>
#include <irtree/visitors/EseqLiftVisitor.h>
#include <irtree/visitors/LinearizationVisitor.h>
#include <irtree/visitors/PrintVisitor.h>
#include <object_types/VoidType.h>
#include <visitors/IrtreeBuildVisitor.h>
#include <visitors/MethodCallVisitor.h>
#include <visitors/PrintVisitor.h>
#include <visitors/SymbolTreeVisitor.h>

Driver::Driver()
    : trace_parsing(false), trace_scanning(false), scanner(*this),
      parser(scanner, *this) {
  variables["one"] = 1;
  variables["two"] = 2;
}

int Driver::parse(const std::string &f) {
  file = f;
  location.initialize(&file);
  scan_begin();
  parser.set_debug_level(trace_parsing);
  int res = parser();

  std::cout << program << std::endl;
  scan_end();
  return res;
}

void Driver::scan_begin() {
  scanner.set_debug(trace_scanning);
  if (file.empty() || file == "-") {
  } else {
    stream.open(file);
    std::cout << file << std::endl;
    scanner.yyrestart(&stream);
  }
}

int Driver::Evaluate() {
  SymbolTreeVisitor visitor;
  visitor.Visit(program);

  std::cout << "Symbol tree built" << std::endl;

  visitor.PrintTree("\"symbol_tree.txt\"");

  std::cout << "tree printed\n";

  ClassType *type = visitor.classes_[Symbol(visitor.GetMainName())];
  ObjectType *obj_type = new ObjectType(type, false);
  BasicObject *object = new Object(obj_type);
  std::vector<std::pair<BasicType *, std::string>> arguments;
  MethodCallVisitor main_visitor(visitor.GetMain()->root_, object,
                                 new MethodType(arguments, new VoidType()));
  main_visitor.SetSymbolTreeVisitor(&visitor);
  main_visitor.Visit(visitor.GetMainClass());

  IrtreeBuildVisitor irt_build_visitor;
  irt_build_visitor.SetSymbolTreeVisitor(&visitor);

  irt_build_visitor.Visit(program);

  IrtMapping methods = irt_build_visitor.GetTrees();

  for (auto func_view = methods.begin(); func_view != methods.end(); ++func_view) {
    IRT::PrintVisitor print_visitor_irt(func_view->first + "_irt.txt");
    methods[func_view->first]->Accept(&print_visitor_irt);

    IRT::DoubleCallEliminateVisitor call_eliminate_visitor;
    methods[func_view->first]->Accept(&call_eliminate_visitor);

    auto stmt_result = call_eliminate_visitor.GetTree();

    IRT::PrintVisitor print_visitor_two(func_view->first + "_without_double_call.txt");
    stmt_result->Accept(&print_visitor_two);

    IRT::EseqLiftVisitor eseq_lift_visitor;
    methods[func_view->first]->Accept(&eseq_lift_visitor);

    stmt_result = eseq_lift_visitor.GetTree();

    IRT::PrintVisitor print_visitor_three(func_view->first + "_with_lifted_eseq.txt");
    stmt_result->Accept(&print_visitor_three);

    IRT::LinearizationVisitor linearization_visitor;
    methods[func_view->first]->Accept(&linearization_visitor);

    for (size_t i = 0; i < 4; ++i) {
      stmt_result = linearization_visitor.GetTree();

      stmt_result->Accept(&linearization_visitor);
    }

    IRT::PrintVisitor print_visitor_four(func_view->first + "_with_seq_right_order.txt");
    stmt_result->Accept(&print_visitor_four);
  }
  return 0;
}

void Driver::PrintTree(const std::string &filename) {
  PrintVisitor visitor(filename);
  visitor.Visit(program);
}

void Driver::scan_end() { stream.close(); }
