#ifndef DUCO_VECTOR_H_
#define DUCO_VECTOR_H_
#include <string>
#include <vector>
namespace duco {
namespace vector {
class Vector {
private:
public:
  int length;
  std::vector<double> vals;
  Vector(double nvars = 0, ...);
  virtual ~Vector();
  double Sum();
  void ScalarMultiply(double val);
  std::string String();
};
}
}
#endif
