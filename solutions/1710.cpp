#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumUnits(std::vector<std::vector<int>> &boxTypes, int truckSize) {
    std::sort(begin(boxTypes), end(boxTypes),
              [](const auto &a, const auto &b) { return a[1] > b[1]; });
    int units = 0;
    int capacity = truckSize;
    for (auto it = begin(boxTypes); it != end(boxTypes) and capacity; ++it) {
      auto count = std::min((*it)[0], capacity);
      auto units_per_box = (*it)[1];
      units += count * units_per_box;
      capacity -= count;
    }
    return units;
  }
};
