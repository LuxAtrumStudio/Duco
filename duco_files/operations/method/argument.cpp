#include "argument.hpp"
#include <string>

duco::operation::Argument::Argument(bool val) {
  type = 'b';
  b = val;
}

duco::operation::Argument::Argument(int val) {
  type = 'i';
  i = val;
}

duco::operation::Argument::Argument(double val) {
  type = 'd';
  d = val;
}

duco::operation::Argument::Argument(std::string val) {
  type = 's';
  s = val;
}
