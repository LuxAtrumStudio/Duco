#include "../duco_headers.hpp"
#include "matrix.hpp"
#include <math.h>
#include <pessum.h>
#include <stdarg.h>
#include <string>
#include <vector>

double
duco::matrix::Matrix::SubDeterminate(std::vector<std::vector<double>> matrix) {
  double det = 0;
  int nrow = matrix[0].size(), ncol = matrix.size();
  if (nrow != ncol) {
    LogLoc(WARNING, "Determinate matrix must be square", lmat,
           "SubDeterminate");
    return (0);
  } else if (nrow == 2 && ncol == 2) {
    det = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
  } else {
    for (int i = 0; i < ncol; i++) {
      std::vector<std::vector<double>> submatrix;
      for (int j = 0; j < ncol; j++) {
        if (j == i) {
          j++;
          if (j == ncol) {
            break;
          }
        }
        std::vector<double> col;
        for (int k = 1; k < nrow; k++) {
          col.push_back(matrix[j][k]);
        }
        submatrix.push_back(col);
      }
      det += (pow(-1, i) * matrix[i][0] * SubDeterminate(submatrix));
      submatrix.clear();
    }
  }
  return (det);
}

duco::matrix::Matrix::Matrix(int nrow, int ncol, ...) {
  valcount = rows * cols;
  rows = nrow;
  cols = ncol;
  va_list ap;
  va_start(ap, ncol);
  for (int i = 0; i < rows; i++) {
    std::vector<double> row;
    for (int j = 0; j < cols; j++) {
      row.push_back(va_arg(ap, double));
    }
    vals.push_back(row);
  }
}

duco::matrix::Matrix::Matrix(const Matrix &clone) {
  vals = clone.vals;
  valcount = clone.valcount;
  rows = clone.rows;
  cols = clone.cols;
}

duco::matrix::Matrix::~Matrix() {
  vals.clear();
  valcount = 0;
  rows = 0;
  cols = 0;
}

void duco::matrix::Matrix::PopBackCol() {
  if (cols > 0) {
    for (int i = 0; i < rows; i++) {
      vals[i].pop_back();
    }
    cols--;
  }
}

void duco::matrix::Matrix::PopBackRow() {
  if (rows > 0) {
    vals.pop_back();
    rows--;
  }
}

void duco::matrix::Matrix::PushBackCol(vector::Vector col) {
  if (col.length != rows) {
    LogLoc(WARNING, "Col size must be equal to matrix row count", lmat,
           "PushBackCol");
  } else if (col.length == rows) {
    for (int i = 0; i < rows; i++) {
      vals[i].push_back(col.vals[i]);
    }
    cols++;
  }
}

void duco::matrix::Matrix::PushBackCol(std::vector<double> col) {
  if (col.size() != rows) {
    LogLoc(WARNING, "Col size must be equal to matrix row count", lmat,
           "PushBackCol");
  } else if (col.size() == rows) {
    for (int i = 0; i < rows; i++) {
      vals[i].push_back(col[i]);
    }
    cols++;
  }
}

void duco::matrix::Matrix::PushBackRow(vector::Vector row) {
  if (row.length != cols) {
    LogLoc(WARNING, "Row size must be equal to matrix col count", lmat,
           "PushBackRow");
  } else if (row.length == cols) {
    vals.push_back(row.vals);
    rows++;
  }
}

void duco::matrix::Matrix::PushBackRow(std::vector<double> row) {
  if (row.size() != cols) {
    LogLoc(WARNING, "Row size must be equal to matrix col count", lmat,
           "PushBackRow");
  } else if (row.size() == cols) {
    vals.push_back(row);
    rows++;
  }
}

void duco::matrix::Matrix::Resize(int nrow, int ncol) {
  while (rows > nrow) {
    PopBackRow();
  }
  while (cols > ncol) {
    PopBackCol();
  }
  std::vector<double> row(cols, 0);
  while (rows < nrow) {
    PushBackRow(row);
  }
  std::vector<double> col(rows, 0);
  while (cols < ncol) {
    PushBackCol(col);
  }
}

void duco::matrix::Matrix::SetVals(Matrix vars) {
  vals = vars.vals;
  rows = vars.rows;
  cols = vars.cols;
  valcount = vars.valcount;
}

void duco::matrix::Matrix::SetVals(std::vector<std::vector<double>> vars) {
  vals = vars;
  rows = vars.size();
  cols = vars[0].size();
  valcount = rows * cols;
}

void duco::matrix::Matrix::Transpose() {
  std::vector<std::vector<double>> newvals;
  for (int i = 0; i < cols; i++) {
    std::vector<double> row;
    for (int j = 0; j < rows; j++) {
      row.push_back(vals[j][i]);
    }
    newvals.push_back(row);
  }
  vals = newvals;
  int trow = rows, tcol = cols;
  rows = tcol;
  cols = trow;
}

double duco::matrix::Matrix::Determinate() {
  double det = SubDeterminate(vals);
  return (det);
}

void duco::matrix::Matrix::ScalarMultiply(double val) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      vals[i][j] *= val;
    }
  }
}

double duco::matrix::Matrix::Sum() {
  double total = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      total += vals[i][j];
    }
  }
  return (total);
}

void duco::matrix::Matrix::SumCols() {
  for (int i = rows - 1; i > 0; i--) {
    for (int j = 0; j < cols; j++) {
      vals[0][j] += vals[i][j];
    }
    vals.erase(vals.begin() + i);
  }
  rows = 1;
}

void duco::matrix::Matrix::SumRows() {
  for (int i = 0; i < rows; i++) {
    for (int j = cols - 1; j > 0; j--) {
      vals[i][0] += vals[i][j];
      vals[i].erase(vals[i].begin() + j);
    }
  }
  cols = 1;
}

void duco::matrix::Matrix::VectorMultiply(vector::Vector vec, int col) {
  if (vec.length == cols && col != 1) {
    for (int j = 0; j < cols; j++) {
      for (int i = 0; i < rows; i++) {
        vals[i][j] *= vec.vals[j];
      }
    }
  } else if (vec.length == rows && col != -1) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        vals[i][j] *= vec.vals[i];
      }
    }
  } else {
    LogLoc(WARNING, "Vec size must match atleast one dymension of matrix", lmat,
           "VectorMultiply");
  }
}

void duco::matrix::Matrix::VectorMultiply(std::vector<double> vec, int col) {
  if (vec.size() == cols && col != 1) {
    for (int j = 0; j < cols; j++) {
      for (int i = 0; i < rows; i++) {
        vals[i][j] *= vec[j];
      }
    }
  } else if (vec.size() == rows && col != -1) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        vals[i][j] *= vec[i];
      }
    }
  } else {
    LogLoc(WARNING, "Vec size must match atleast one dymension of matrix", lmat,
           "VectorMultiply");
  }
}

std::vector<std::vector<double>> duco::matrix::Matrix::GetMatrix() {
  return (vals);
}

std::string duco::matrix::Matrix::String() {
  std::string str;
  for (int i = 0; i < rows; i++) {
    str += "[";
    for (int j = 0; j < cols; j++) {
      str += manipulation::ReduceDouble(vals[i][j]);
      if (j != cols - 1) {
        str += ",";
      }
    }
    str += "]";
    if (i != rows - 1) {
      str += ",";
    }
  }
  return (str);
}
