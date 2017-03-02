#include "matrix.hpp"
#include <math.h>
#include <stdarg.h>
#include <vector>

duco::matrix::Matrix::Matrix() {
  rows = 0;
  cols = 0;
}

duco::matrix::Matrix::Matrix(bool Identity, int nrow, int ncol) {
  std::vector<std::vector<double>> newvals(nrow, std::vector<double>(ncol, 0));
  vals = newvals;
  rows = nrow;
  cols = ncol;
  if (Identity == true && nrow == ncol) {
    for (int i = 0; i < nrow && i < ncol; i++) {
      vals[i][i] = 1;
    }
  }
}

duco::matrix::Matrix::Matrix(int nrow, int ncol, ...) {
  va_list ap;
  va_start(ap, ncol);
  for (int i = 0; i < nrow; i++) {
    std::vector<double> row;
    for (int j = 0; j < ncol; j++) {
      row.push_back(va_arg(ap, double));
    }
    vals.push_back(row);
  }
  rows = nrow;
  cols = ncol;
}

duco::matrix::Matrix::Matrix(std::vector<std::vector<double>> invals) {
  vals = invals;
  if (vals.size() > 0) {
    rows = vals[0].size();
  } else {
    rows = 0;
  }
  cols = vals.size();
}

duco::matrix::Matrix::Matrix(const Matrix &copy) {
  vals = copy.vals;
  rows = copy.rows;
  cols = copy.cols;
}

duco::matrix::Matrix::~Matrix() {
  vals.clear();
  rows = 0;
  cols = 0;
}

void duco::matrix::Matrix::SetVals(int nrow, int ncol, ...) {
  vals.clear();
  va_list ap;
  va_start(ap, ncol);
  for (int i = 0; i < nrow; i++) {
    std::vector<double> row;
    for (int j = 0; j < ncol; j++) {
      row.push_back(va_arg(ap, double));
    }
    vals.push_back(row);
  }
  rows = nrow;
  cols = ncol;
}

void duco::matrix::Matrix::SetVals(std::vector<std::vector<double>> invals) {
  vals.clear();
  vals = invals;
  if (vals.size() > 0) {
    rows = vals[0].size();
  } else {
    rows = 0;
  }
  cols = vals.size();
}

void duco::matrix::Matrix::PopBackRow() {
  if (rows > 0) {
    vals.pop_back();
    rows--;
  }
}

void duco::matrix::Matrix::PopBackCol() {
  if (cols > 0) {
    for (int i = 0; i < rows; i++) {
      vals[i].pop_back();
    }
    cols--;
  }
}

void duco::matrix::Matrix::PushBackRow(std::vector<double> row) {
  if (row.size() == cols || cols == 0) {
    vals.push_back(row);
    rows++;
    if (cols == 0) {
      cols = row.size();
    }
  }
}

void duco::matrix::Matrix::PushBackRow(duco::vector::Vector row) {
  if (row.GetLength() == cols || cols == 0) {
    vals.push_back(row.GetVector());
    rows++;
    if (cols == 0) {
      cols = row.GetLength();
    }
  }
}

void duco::matrix::Matrix::PushBackCol(std::vector<double> col) {
  if (col.size() == rows || rows == 0) {
    for (int i = 0; i < rows; i++) {
      vals[i].push_back(col[i]);
    }
    cols++;
    if (rows == 0) {
      rows = col.size();
    }
  }
}

void duco::matrix::Matrix::Resize(int nrow, int ncol, double val) {
  while (rows > nrow && rows > 0) {
    PopBackRow();
  }
  while (rows < nrow) {
    std::vector<double> row(cols, val);
    PushBackRow(row);
  }
  while (cols > ncol && cols > 0) {
    PopBackCol();
  }
  while (cols < ncol) {
    std::vector<double> col(rows, val);
    PushBackCol(col);
  }
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
  SetVals(newvals);
}

void duco::matrix::Matrix::SetVal(int row, int col, double val) {
  if (row < rows && row >= 0 && col < cols && col >= 0) {
    vals[row][col] = val;
  }
}

void duco::matrix::Matrix::ScalarMultiply(double val) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      vals[i][j] *= val;
    }
  }
}

double duco::matrix::Matrix::Determinate() {
  return (RecursiveDeterminate(vals));
}

double duco::matrix::Matrix::Total() {
  double total = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      total += vals[i][j];
    }
  }
  return (total);
}

double duco::matrix::Matrix::Trace() {
  double trace = 0;
  for (int i = 0; i < rows && i < cols; i++) {
    trace += vals[i][i];
  }
  return (trace);
}

int duco::matrix::Matrix::GetRows() { return (rows); }

int duco::matrix::Matrix::GetCols() { return (cols); }

std::pair<int, int> duco::matrix::Matrix::GetSize() {
  return (std::pair<int, int>(rows, cols));
}

std::vector<std::vector<double>> duco::matrix::Matrix::GetMatrix() {
  return (vals);
}

std::string duco::matrix::Matrix::GetString() {
  std::string str = "[";
  for (int i = 0; i < rows; i++) {
    str += "[";
    for (int j = 0; j < cols; j++) {
      str += std::to_string(vals[i][j]);
      if (j != cols - 1) {
        str += ",";
      }
    }
    str += "]";
    if (i != rows - 1) {
      str += ",";
    }
  }
  str += "]";
  return (str);
}

double duco::matrix::Matrix::GetVal(int row, int col) {
  if (row < rows && row >= 0 && col < cols && col >= 0) {
    return (vals[row][col]);
  } else {
    return (0);
  }
}

std::vector<duco::vector::Vector> duco::matrix::Matrix::GetVectors() {
  std::vector<duco::vector::Vector> vecs;
  for (int i = 0; i < vals.size(); i++) {
    vecs.push_back(duco::vector::Vector(vals[i]));
  }
  return (vecs);
}

double duco::matrix::Matrix::RecursiveDeterminate(
    std::vector<std::vector<double>> mat) {
  double determinate = 0;
  if (mat.size() <= 0) {
    return (determinate);
  }
  int nrow = mat[0].size(), ncol = mat.size();
  if (nrow != ncol) {
    return (determinate);
  } else if (nrow == 2 && ncol == 2) {
    determinate = (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
  } else {
    for (int i = 0; i < ncol; i++) {
      std::vector<std::vector<double>> submat;
      for (int j = 0; j < ncol; j++) {
        if (j == i) {
          j++;
          if (j == ncol) {
            break;
          }
        }
        std::vector<double> col;
        for (int k = 1; k < nrow; k++) {
          col.push_back(mat[j][k]);
        }
        submat.push_back(col);
      }
      determinate += (pow(-1, i) * mat[i][0] * RecursiveDeterminate(submat));
      submat.clear();
    }
  }
  return (determinate);
}
