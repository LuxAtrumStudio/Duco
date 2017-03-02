#include "../../classes/class_headers.hpp"
#include "trigonometricopr.hpp"
#include <math.h>
#include <vector>

double duco::trigonometric::Sin(double rad) { return (sin(rad)); }

double duco::trigonometric::Cos(double rad) { return (cos(rad)); }

double duco::trigonometric::Tan(double rad) { return (tan(rad)); }

double duco::trigonometric::Cot(double rad) { return (1.0 / tan(rad)); }

double duco::trigonometric::Sec(double rad) { return (1.0 / cos(rad)); }

double duco::trigonometric::Csc(double rad) { return (1.0 / sin(rad)); }

double duco::trigonometric::ArcSin(double val) { return (asin(val)); }

double duco::trigonometric::ArcCos(double val) { return (acos(val)); }

double duco::trigonometric::ArcTan(double val) { return (atan(val)); }

double duco::trigonometric::ArcCot(double val) { return (atan(1.0 / val)); }

double duco::trigonometric::ArcSec(double val) { return (acos(1.0 / val)); }

double duco::trigonometric::ArcCsc(double val) { return (asin(1.0 / val)); }
