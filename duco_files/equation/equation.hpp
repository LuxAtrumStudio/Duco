#ifndef DUCO_EQUATION_HPP
#define DUCO_EQUATION_HPP
#include <string>
#include <vector>
namespace duco {
namespace equation {
enum TermType { VARIABLE, VALUE, OPERATOR, STRUCTURE, RELATION };
enum StructureType { OPAREN, CPAREN, OBRACKET, CBRACKET, OANGLE, CANGLE };
enum RelationType { EQUAL, NOTEQUAL, LESSTHAN, MORETHAN, ALMOSTEQUAL };
struct Term {
  TermType type;
  std::string variable;
  double value;
  std::string operatorstr;
  StructureType structuretype;
  RelationType relationtype;
};
class Equation {
public:
  std::string eqstring;
  // Constructors and destructors
  Equation(std::string str = "");
  virtual ~Equation();

  void EditEquation(std::string = "");

private:
  std::vector<Term> termstruct;
  void ParseEquation();
};
}
}
#endif
