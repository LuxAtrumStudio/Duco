#ifndef DUCO_OPERATION_VECTOR
#define DUCO_OPERATION_VECTOR
#include "../../classes/class_headers.hpp"
namespace duco {
namespace vector {
double Dot(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector Cross(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector Add(Vector a, Vector b, double alpha = 1, double beta = 1);
double Angle(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector ElementMultiply(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector ElementDivide(Vector a, Vector b, double alpha = 1, double beta = 1);
}
}
#endif
