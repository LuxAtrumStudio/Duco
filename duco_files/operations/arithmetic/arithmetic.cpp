#include "arithmetic.hpp"
#include <cmath>
#include <iostream>
#include <pessum.h>

double duco::operation::arithmetic::Add(double a, double b) { return (a + b); }

double duco::operation::arithmetic::Sub(double a, double b) { return (a - b); }

double duco::operation::arithmetic::Mul(double a, double b) { return (a * b); }

double duco::operation::arithmetic::Div(double a, double b) {
  if (b != 0) {
    return (a / b);
  } else if (b == 0) {
    pessum::logging::Log("warning", "Cannot divide by 0", "duc/ope/ari", "Div");
  }
  return (0.0);
}

double duco::operation::arithmetic::Round(double a, double integer) {
  a *= pow(10, floor(integer));
  if (fmod(a, 0.5) == 0) {
    if (fmod(a + 0.5, 2) == 0) {
      a += 0.5;
    } else {
      a -= 0.5;
    }
  } else {
    a += 0.5;
    a = floor(a);
  }
  a /= pow(10, floor(integer));
  return (a);
}

double duco::operation::arithmetic::Floor(double a, double integer) {
  a *= pow(10, floor(integer));
  a = floor(a);
  a /= pow(10, floor(integer));
  return (a);
}

double duco::operation::arithmetic::Ceil(double a, double integer) {
  a *= pow(10, floor(integer));
  a = ceil(a);
  a /= pow(10, floor(integer));
  return (a);
}

double duco::operation::arithmetic::Pow(double a, double b) {
  a = pow(a, b);
  return (a);
}

double duco::operation::arithmetic::Log(double a, double b) {
  if (a == 0 || b == 0) {
    pessum::logging::Log("warning", "Input is out of domain", "duc/ope/ari",
                         "Log");
  } else if (a < 0 || b < 0) {
    pessum::logging::Log("warning", "Input results in nonreal answer",
                         "duc/ope/ari", "Log");
  } else {
    a = (log(a) / log(b));
  }
  return (a);
}
