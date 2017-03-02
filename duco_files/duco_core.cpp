#include "duco_core.hpp"
#include <pessum.h>
#include <vector>

void duco::InitializeDuco() {
  std::vector<std::string> locations = {"duco", "duco/operation",
                                        "duco/operation/arithmetic",
                                        "duco/operation/trigonometry"};
  for (int i = 0; i < locations.size(); i++) {
    pessum::logging::AddLogLocation(locations[i]);
  }
}
