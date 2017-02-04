#include "../duco_headers.hpp"
#include "functions.hpp"
#include <math.h>
#include <stdarg.h>
#include <string>
#include <vector>

duco::matrix::Matrix duco::matrix::Product(Matrix a, Matrix b, double alpha,
                                           double beta) {
  Matrix product;
  product.Resize(a.rows, b.cols);
  if (a.cols != b.rows) {
    LogLoc(WARNING, "Number of columns in first matrix must match number of "
                    "rows in seconed matrix",
           lmat, "Product");
    return (product);
  }
  std::vector<std::vector<double>> output;
  for (int j = 0; j < b.cols; j++) {
    std::vector<double> col;
    for (int i = 0; i < a.rows; i++) {
      double sum = 0;
      for (int k = 0; k < a.cols && k < b.rows; k++) {
        sum += a.vals[i][k] * b.vals[k][j];
      }
      product.vals[i][j] = sum;
    }
  }
  return (product);
}

duco::matrix::Matrix duco::matrix::Add(Matrix a, Matrix b, double alpha,
                                       double beta) {
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.rows != b.rows || a.cols != b.cols) {
    LogLoc(WARNING, "Matricies must be the same size for addition", lmat,
           "Add");
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.rows; i++) {
      for (int j = 0; j < a.cols; j++) {
        a.vals[i][j] += b.vals[i][j];
      }
    }
  }
  return (a);
}

duco::matrix::Matrix duco::matrix::Multiply(Matrix a, Matrix b, double alpha,
                                            double beta) {
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.rows != b.rows || a.cols != b.cols) {
    LogLoc(WARNING, "Matricies must be the same size for multiplication", lmat,
           "Multiply");
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.rows; i++) {
      for (int j = 0; j < a.cols; j++) {
        a.vals[i][j] *= b.vals[i][j];
      }
    }
  }
  return (a);
}

duco::matrix::Matrix duco::matrix::Divide(Matrix a, Matrix b, double alpha,
                                          double beta) {
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.rows != b.rows || a.cols != b.cols) {
    LogLoc(WARNING, "Matricies must be the same size for division", lmat,
           "Divide");
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.rows; i++) {
      for (int j = 0; j < a.cols; j++) {
        a.vals[i][j] /= b.vals[i][j];
      }
    }
  }
  return (a);
}
