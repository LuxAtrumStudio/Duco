#ifndef DUCO_STRUCT_TERM_HPP
#define DUCO_STRUCT_TERM_HPP
#include <string>
namespace duco {
enum TermType { VAR, OPP, CONST };
struct Term {
  TermType type;
  std::string name;
  long double value;
};
}
#endif
