#ifndef DUCO_STRUCT_EQUATION_HPP
#define DUCO_STRUCT_EQUATION_HPP
#include "../structures.hpp"
#include <string>
#include <vector>
namespace duco {
class Equation {
public:
  Equation(std::string eq);

private:
  std::vector<Term> terms;
};
}
#endif
