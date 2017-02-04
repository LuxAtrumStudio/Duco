#include "../duco_headers.hpp"
#include "trigonometry.hpp"
#include <math.h>
#include <string>

double duco::trigonometry::Sin(double rad) { return (sin(rad)); }

double duco::trigonometry::Cos(double rad) { return (cos(rad)); }

double duco::trigonometry::Tan(double rad) { return (tan(rad)); }

double duco::trigonometry::Cot(double rad) { return (1.0 / tan(rad)); }

double duco::trigonometry::Sec(double rad) { return (1.0 / cos(rad)); }

double duco::trigonometry::Csc(double rad) { return (1.0 / sin(rad)); }

double duco::trigonometry::ArcSin(double val) { return (asin(val)); }

double duco::trigonometry::ArcCos(double val) { return (acos(val)); }

double duco::trigonometry::ArcTan(double val) { return (atan(val)); }

double duco::trigonometry::ArcCot(double val) { return (atan(1.0 / val)); }

double duco::trigonometry::ArcSec(double val) { return (acos(1.0 / val)); }

double duco::trigonometry::ArcCsc(double val) { return (asin(1.0 / val)); }
