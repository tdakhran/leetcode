#include <cmath>
#include <limits>
#include <vector>

class Solution {
 public:
  int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
    int result = -1;
    int smallest_distance = std::numeric_limits<int>::max();
    for (size_t pos = 0; pos < points.size(); ++pos) {
      auto x0 = points[pos][0];
      auto y0 = points[pos][1];
      if (x0 != x and y0 != y) {
        continue;
      }
      auto distance = std::abs(x - x0) + std::abs(y - y0);
      if (distance < smallest_distance) {
        smallest_distance = distance;
        result = static_cast<int>(pos);
      }
    }
    return result;
  }
};
