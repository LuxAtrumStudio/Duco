#ifndef DUCO_VECTOR_H_
#define DUCO_VECTOR_H_
#include <string>
#include <vector>
namespace duco {
namespace vec {
class Vector {
private:
  int length;
  std::vector<double> vals;

public:
  Vector(double nvars = 0, ...);
  virtual ~Vector();
  double Sum();
  std::string String();
};
}
}
#endif
