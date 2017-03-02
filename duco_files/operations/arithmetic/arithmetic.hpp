#ifndef DUCO_OPERATION_ARITHMETIC
#define DUCO_OPERATION_ARITHMETIC
#include "../../constant.hpp"
namespace duco {
namespace operation {
namespace arithmetic {
double Add(double a, double b);
double Sub(double a, double b);
double Mul(double a, double b);
double Div(double a, double b);
double Round(double a, int integer = 1);
double Floor(double a, int integer = 1);
double Ceil(double a, int integer = 1);
double Pow(double a, double b);
double Root(double a, double b);
double Log(double a, double b);
double Abs(double a);
double Hypot(double a, double b);
}
}
}
#endif
