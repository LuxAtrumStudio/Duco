#ifndef DUCO_OPERATION_MATRIX
#define DUCO_OPERATION_MATRIX
#include "../../classes/class_headers.hpp"
namespace duco {
namespace matrix {
Matrix Multiply(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix Add(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix ElementMultiply(Matrix a, Matrix b, double alpha = 1, double beta = 1);
Matrix ElementDivide(Matrix a, Matrix b, double alpha = 1, double beta = 1);

std::pair<Matrix, Matrix> Rref(std::pair<Matrix, Matrix> mat);
Matrix Inverse(Matrix mat);
}
}
#endif
