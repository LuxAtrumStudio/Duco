#include "operation_core.hpp"
#include "operation_headers.hpp"
#include <map>
#include <string>

namespace duco {
std::map<std::string, std::function<double(double)>> unaryopmap;
std::map<std::string, std::function<double(double, double)>> binaryopmap;
}

void duco::LoadOperMap() {
  unaryopmap["SIN"] = trigonometric::Sin;
  unaryopmap["COS"] = trigonometric::Cos;
  unaryopmap["TAN"] = trigonometric::Tan;
  unaryopmap["COT"] = trigonometric::Cot;
  unaryopmap["SEC"] = trigonometric::Sec;
  unaryopmap["CSC"] = trigonometric::Csc;
  unaryopmap["ARCSIN"] = trigonometric::ArcSin;
  unaryopmap["ARCCOS"] = trigonometric::ArcCos;
  unaryopmap["ARCTAN"] = trigonometric::ArcTan;
  unaryopmap["ARCCOT"] = trigonometric::ArcCot;
  unaryopmap["ARCSEC"] = trigonometric::ArcSec;
  unaryopmap["ARCCSC"] = trigonometric::ArcCsc;

  binaryopmap["ADD"] = arithmetic::Add;
  binaryopmap["SUB"] = arithmetic::Sub;
  binaryopmap["MUL"] = arithmetic::Mul;
  binaryopmap["DIV"] = arithmetic::Div;
}
