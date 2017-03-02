#include "operation_core.hpp"
#include "operation_headers.hpp"
#include <functional>
#include <map>
#include <pessum.h>
#include <string>

namespace duco {
namespace operation {
std::map<std::string, Method> ops;
}
}

void duco::operation::LoadArithmeticOperations() {
  Method method;
  method.Initddd(arithmetic::Add);
  ops["ADD"] = method;
  method.Initddd(arithmetic::Sub);
  ops["SUB"] = method;
  // ops["ADD"] = InitMethod(arithmetic::Add);
  // ops["SUB"] = Method(std::function<double>(double, double) >
  // arithmetic::Sub);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["ADD"] = Method(std::function<double>(double, double) >
  // arithmetic::Add);
  // ops["SUB"] = arithmetic::Sub;
  // ops["MUL"] = arithmetic::Mul;
  // ops["DIV"] = arithmetic::Div;
  // ops["ROUND"] = arithmetic::Round;
  // ops["ROUND"] = method;
  // ops["FLOOR"] = arithmetic::Floor;
  // ops["CEIL"] = arithmetic::Ceil;
  // ops["POW"] = arithmetic::Pow;
  // ops["LOG"] = arithmetic::Log;
}

void duco::operation::LoadTrigonometryOperations() {}
