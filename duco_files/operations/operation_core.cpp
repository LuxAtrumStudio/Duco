#include "operation_core.hpp"
#include "operation_headers.hpp"
#include <functional>
#include <map>
#include <pessum.h>
#include <string>

namespace duco {
namespace operation {
std::map<std::string, std::function<double(double, double)>> ops;
}
}

void duco::operation::LoadArithmeticOperations() {
  ops["ADD"] = arithmetic::Add;
  ops["SUB"] = arithmetic::Sub;
  ops["MUL"] = arithmetic::Mul;
  ops["DIV"] = arithmetic::Div;
  ops["ROUND"] = arithmetic::Round;
  ops["FLOOR"] = arithmetic::Floor;
  ops["CEIL"] = arithmetic::Ceil;
  ops["POW"] = arithmetic::Pow;
  ops["LOG"] = arithmetic::Log;
}
