#ifndef DUCO_OPERATION_ARGUMENT_HPP
#define DUCO_OPERATION_ARGUMENT_HPP
#include <string>
namespace duco {
namespace operation {
struct Argument {
  Argument(bool val);
  Argument(int val);
  Argument(double val);
  Argument(std::string val);
  char type = ' ';
  bool b;
  int i;
  double d;
  std::string s;
};
}
}
#endif
