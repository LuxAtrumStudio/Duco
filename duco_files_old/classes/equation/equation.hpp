#ifndef DUCO_CLASS_EQUATION
#define DUCO_CLASS_EQUATION
#include <string>
#include <vector>
namespace duco {
namespace equation {
class Equation {
public:
  struct Term {
    int termtype = 0;
    double val = 0;
    std::string name = "";
    bool open = true;
    bool unary = false;
  };
  Equation();
  Equation(std::string eq);
  Equation(const Equation &copy);
  ~Equation();
  double SolveEquation(std::vector<std::pair<std::string, double>> vals);
  double SolveEquation(double val);
  std::vector<std::pair<std::string, double>> GetVariables();

private:
  std::string eqstr;
  std::vector<Term> terms;
  void Parse();
  void SetOrder();
  void EnterVars(std::vector<std::pair<std::string, double>> vals);
  double SolveSection(int open, int close);
  double Operation(std::string op, double val);
  double Operation(std::string op, double val1, double val2);
};
}
}
#endif
