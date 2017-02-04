#include "../duco_headers.hpp"
#include "manipulation.hpp"
#include <string>

std::string duco::manipulation::ReduceDouble(double val, int length) {
  std::string str = std::to_string(val);
  if (length == -1) {
    for (int i = str.size() - 1; i >= 0; i--) {
      if (str[i] != '0' && str[i] != '.') {
        i = -1;
      } else if (str[i] == '.') {
        str.pop_back();
        i = -1;
      } else {
        str.pop_back();
      }
    }
  } else {
    for (int i = str.size() - 1; i > length; i--) {
      str.pop_back();
    }
  }
  return (str);
}
