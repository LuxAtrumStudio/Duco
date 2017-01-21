#ifndef DUCO_VECTOR_FUNCTIONS_H_
#define DUCO_VECTOR_FUNCTIONS_H_
#include "vector.hpp"
namespace duco {
namespace vector {
double Dot(Vector a, Vector);
Vector Cross(Vector a, Vector b);
Vector Add(Vector a, Vector b, double alpha = 1, double beta = 1);
double Angle(Vector a, Vector b);
Vector Multiply(Vector a, Vector b, double alpha = 1, double beta = 1);
Vector Divide(Vector a, Vector b, double alpha = 1, double beta = 1);
}
}
#endif
