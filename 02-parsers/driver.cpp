#include "driver.hh"
#include "parser.hh"
#include <visitors/PrintVisitor.h>
#include <visitors/SymbolTreeVisitor.h>

Driver::Driver() :
    trace_parsing(false),
    trace_scanning(false),
    scanner(*this), parser(scanner, *this) {
    variables["one"] = 1;
    variables["two"] = 2;
}


int Driver::parse(const std::string& f) {
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
  if (file.empty () || file == "-") {
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
  return 0;
}

void Driver::PrintTree(const std::string& filename) {
  PrintVisitor visitor(filename);
  visitor.Visit(program);
}


void Driver::scan_end()
{
    stream.close();
}

