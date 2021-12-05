#include <algorithm>
#include <vector>

class Solution {
 public:
  int findMinArrowShots(std::vector<std::vector<int>> &points) {
    std::sort(begin(points), end(points), [](const auto &a, const auto &b) {
      return a[1] < b[1] or (a[1] == b[1] and a[0] < b[0]);
    });

    int count = 0;
    for (auto it = begin(points); it != end(points);) {
      ++count;
      auto &element = *it++;
      while (it != end(points)) {
        const auto &point = *it;
        if (point[1] < element[0] or point[0] > element[1]) {
          break;
        }
        ++it;
      }
    }

    return count;
  }
};
