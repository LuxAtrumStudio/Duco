#ifndef DUCO_OPERATION_TRIGONOMETY
#define DUCO_OPERATION_TRIGONOMETY
namespace duco {
namespace operation {
namespace trigonometry {
double ConvertAngle(double angle, bool todegree = false);
double Sin(double angle, bool degree = false);
double Cos(double angle, bool degree = false);
double Tan(double angle, bool degree = false);
double Cot(double angle, bool degree = false);
double Sec(double angle, bool degree = false);
double Csc(double angle, bool degree = false);
double ArcSin(double val, bool degree = false);
double ArcCos(double val, bool degree = false);
double ArcTan(double val, bool degree = false);
double ArcCot(double val, bool degree = false);
double ArcSec(double val, bool degree = false);
double ArcCsc(double val, bool degree = false);
double Los(double a, double anglea, double b, double angleb,
           bool degree = false);
double Loc(double a, double b, double c, double anglec, bool degree = false);
double Lot(double a, double b, double anglea, double angleb,
           bool degree = false);
}
}
}
#endif
