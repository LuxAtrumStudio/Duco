#ifndef DUCO_CLASS_VECTOR
#define DUCO_CLASS_VECTOR
#include <string>
#include <vector>
namespace duco {
namespace vector {
class Vector {
public:
  // Constructors and destructor
  Vector();
  Vector(int nvars, ...);
  Vector(std::vector<double> invals);
  Vector(const Vector &copy);
  ~Vector();
  // Data manipulation
  void SetVals(int nvars, ...);
  void SetVals(std::vector<double> invals);
  void PopBack();
  void PushBack(double val);
  void Resize(int nvars, double val = 0);
  // Internal functions
  void ScalarMultiply(double val);
  void Pow(double val);
  // Returning functions
  double Total();
  double Magnitude();
  // Data returning functions
  int GetLength();
  std::vector<double> GetVector();
  std::string GetString();

private:
  int length;
  std::vector<double> vals;
};
}
}
#endif
