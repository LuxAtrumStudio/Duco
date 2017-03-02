#include "../../classes/class_headers.hpp"
#include "../operation_headers.hpp"
#include "matrixopr.hpp"
#include <math.h>
#include <vector>

duco::matrix::Matrix duco::matrix::Multiply(Matrix a, Matrix b, double alpha,
                                            double beta) {
  Matrix product;
  product.Resize(a.GetRows(), b.GetCols(), 0.0);
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  std::vector<std::vector<double>> mata = a.GetMatrix(), matb = b.GetMatrix();
  if (a.GetCols() != b.GetRows()) {
    return (product);
  }
  std::vector<std::vector<double>> output;
  for (int j = 0; j < b.GetCols(); j++) {
    std::vector<double> col;
    for (int i = 0; i < a.GetRows(); i++) {
      double sum = 0;
      for (int k = 0; k < a.GetCols() && k < b.GetRows(); k++) {
        sum += mata[i][k] * matb[k][j];
      }
      product.SetVal(i, j, sum);
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
  if (a.GetSize() != b.GetSize()) {
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.GetRows(); i++) {
      for (int j = 0; j < a.GetCols(); j++) {
        a.SetVal(i, j, a.GetVal(i, j) + b.GetVal(i, j));
      }
    }
  }
  return (a);
}

duco::matrix::Matrix duco::matrix::ElementMultiply(Matrix a, Matrix b,
                                                   double alpha, double beta) {
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.GetSize() != b.GetSize()) {
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.GetRows(); i++) {
      for (int j = 0; j < a.GetCols(); j++) {
        a.SetVal(i, j, a.GetVal(i, j) * b.GetVal(i, j));
      }
    }
  }
  return (a);
}

duco::matrix::Matrix duco::matrix::ElementDivide(Matrix a, Matrix b,
                                                 double alpha, double beta) {
  if (alpha != 1) {
    a.ScalarMultiply(alpha);
  }
  if (beta != 1) {
    b.ScalarMultiply(beta);
  }
  if (a.GetSize() != b.GetSize()) {
    Matrix mat;
    return (mat);
  } else {
    for (int i = 0; i < a.GetRows(); i++) {
      for (int j = 0; j < a.GetCols(); j++) {
        a.SetVal(i, j, a.GetVal(i, j) / b.GetVal(i, j));
      }
    }
  }
  return (a);
}

std::pair<duco::matrix::Matrix, duco::matrix::Matrix>
duco::matrix::Rref(std::pair<Matrix, Matrix> mat) {
  std::vector<duco::vector::Vector> vecs = mat.first.GetVectors(),
                                    bvecs = mat.second.GetVectors();
  for (int i = 0; i < vecs.size() && i < vecs[0].GetLength(); i++) {
    double currentpivot = vecs[i].GetVal(i);
    if (currentpivot != 1) {
      vecs[i].ScalarMultiply(1.0 / currentpivot);
      bvecs[i].ScalarMultiply(1.0 / currentpivot);
    }
    for (int j = 0; j < vecs.size(); j++) {
      if (j != i) {
        double alpha = -1 * vecs[j].GetVal(i);
        vecs[j] = vector::Add(vecs[i], vecs[j], alpha, 1);
        bvecs[j] = vector::Add(bvecs[i], bvecs[j], alpha, 1);
      }
    }
  }
  Matrix mata, matb;
  for (int i = 0; i < vecs.size(); i++) {
    mata.PushBackRow(vecs[i]);
    matb.PushBackRow(bvecs[i]);
  }
  return (std::pair<Matrix, Matrix>(mata, matb));
}

duco::matrix::Matrix duco::matrix::Inverse(Matrix mat) {
  std::pair<Matrix, Matrix> matpair(mat,
                                    Matrix(true, mat.GetRows(), mat.GetCols()));
  matpair = Rref(matpair);
  return (matpair.second);
}
