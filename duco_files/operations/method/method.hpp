#ifndef DUCO_OPERATION_METHOD_HPP
#define DUCO_OPERATION_METHOD_HPP
#include "argument.hpp"
#include <functional>
#include <string>
#include <vector>
namespace duco {
namespace operation {
class Method {
public:
  Method();
  ~Method();
  void TermMethod();
  void Initdd(std::function<double(double)> func);
  void Initddd(std::function<double(double, double)> func);
  void Initddi(std::function<double(double, int)> func);
  void Initddb(std::function<double(double, bool)> func);
  void
  Initdddddb(std::function<double(double, double, double, double, bool)> func);
  std::string GetType();
  double RunDoubleFunction(std::vector<Argument> args);
  double RunDoubleFunction(int argcount, ...);
  std::function<double(double)> dd;
  std::function<double(double, double)> ddd;
  std::function<double(double, int)> ddi;
  std::function<double(double, bool)> ddb;
  std::function<double(double, double, double, double, bool)> dddddb;

private:
  std::string functiontype = "";
  std::string GetVarType(char var);
};
}
}
#endif
