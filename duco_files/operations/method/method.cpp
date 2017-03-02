#include "method.hpp"
#include <functional>
#include <pessum.h>
#include <stdarg.h>

duco::operation::Method::Method() {}

duco::operation::Method::~Method() { TermMethod(); }

void duco::operation::Method::TermMethod() {
  functiontype = "";
  dd.~function();
  ddd.~function();
  ddi.~function();
  ddb.~function();
  dddddb.~function();
}

void duco::operation::Method::Initdd(std::function<double(double)> func) {
  if (functiontype != "") {
    TermMethod();
  }
  functiontype = "dd";
  dd = func;
}

void duco::operation::Method::Initddd(
    std::function<double(double, double)> func) {
  if (functiontype != "") {
    TermMethod();
  }
  functiontype = "ddd";
  ddd = func;
}

void duco::operation::Method::Initddi(std::function<double(double, int)> func) {
  if (functiontype != "") {
    TermMethod();
  }
  functiontype = "ddi";
  ddi = func;
}

void duco::operation::Method::Initddb(
    std::function<double(double, bool)> func) {
  if (functiontype != "") {
    TermMethod();
  }
  functiontype = "ddb";
  ddb = func;
}

void duco::operation::Method::Initdddddb(
    std::function<double(double, double, double, double, bool)> func) {
  if (functiontype != "") {
    TermMethod();
  }
  functiontype = "dddddb";
  dddddb = func;
}

std::string duco::operation::Method::GetType() { return (functiontype); }

double duco::operation::Method::RunDoubleFunction(int argcount, ...) {
  bool good = true;
  if (functiontype[0] != 'd') {
    pessum::logging::Log("warning", "Function does not return a double but a " +
                                        GetVarType(functiontype[0]),
                         "duc/ope/met", "RunDoubleFunction(1)");
    good = false;
  }
  if (argcount != functiontype.size() - 1 && good == true) {
    pessum::logging::Log(
        "warning",
        "Functions requiers " + std::to_string(functiontype.size() - 1) +
            " but was only provided " + std::to_string(argcount),
        "duc/ope/met", "RunDoubleFunction(2)");
    good = false;
  } else if (good == true) {
    std::vector<Argument> args;
    va_list ap;
    va_start(ap, argcount);
    for (int i = 1; i <= argcount; i++) {
      if (functiontype[i] == 'b') {
        args.push_back(Argument(va_arg(ap, int)));
      } else if (functiontype[i] == 'i') {
        args.push_back(Argument(va_arg(ap, int)));
      } else if (functiontype[i] == 'd') {
        args.push_back(Argument(va_arg(ap, double)));
      }
    }
    va_end(ap);
    return (RunDoubleFunction(args));
  }
  return (0.0);
}

double duco::operation::Method::RunDoubleFunction(std::vector<Argument> args) {
  bool good = true;
  if (functiontype[0] != 'd') {
    pessum::logging::Log("warning", "Function does not return a double but a " +
                                        GetVarType(functiontype[0]),
                         "duc/ope/met", "RunDoubleFunction(1)");
    good = false;
  }
  if (args.size() != functiontype.size() - 1 && good == true) {
    pessum::logging::Log(
        "warning",
        "Functions requires " + std::to_string(functiontype.size() - 1) +
            " but was only provided " + std::to_string(args.size()),
        "duc/ope/met", "RunDoubleFunction(1)");
    good = false;
  } else if (good == true) {
    for (int i = 0; i < args.size(); i++) {
      if (args[i].type != functiontype[i + 1]) {
        pessum::logging::Log(
            "warning", "For argument " + std::to_string(i) + " expected a " +
                           GetVarType(functiontype[i + 1]) +
                           " but was provided " + GetVarType(args[i].type),
            "duc/ope/met", "RunDoubleFunction(1)");
        good = false;
        break;
      }
    }
  }
  if (good == true) {
    if (functiontype == "dd") {
      return (dd(args[0].d));
    } else if (functiontype == "ddd") {
      return (ddd(args[0].d, args[1].d));
    } else if (functiontype == "ddi") {
      return (ddi(args[0].d, args[1].i));
    } else if (functiontype == "ddb") {
      return (ddb(args[0].d, args[1].b));
    } else if (functiontype == "dddddb") {
      return (dddddb(args[0].d, args[1].d, args[2].d, args[3].d, args[4].b));
    } else {
      pessum::logging::Log("warning", "Unrecognized function type indicator " +
                                          functiontype,
                           "duc/ope/met", "RunDoubleFunction(1)");
    }
  }
  return (0.0);
}

std::string duco::operation::Method::GetVarType(char var) {
  if (var == 'b') {
    return ("bool");
  } else if (var == 'i') {
    return ("int");
  } else if (var == 'd') {
    return ("double");
  } else if (var == 's') {
    return ("string");
  }
  return ("none");
}
