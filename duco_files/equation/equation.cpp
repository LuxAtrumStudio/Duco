#include "../duco_headers.hpp"
#include "equation.hpp"
#include <math.h>
#include <stdarg.h>
#include <string>
#include <vector>

duco::equation::Equation::Equation(std::string str) { eqstring = str; }

duco::equation::Equation::~Equation() { eqstring = ""; }
