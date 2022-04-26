#include <cmath>
#include <limits>
#include <vector>

class Solution {
 public:
  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    std::vector<int> distances(points.size(),
                               std::numeric_limits<int>::max() - 1);
    auto dist = [&points](size_t pi, size_t pj) {
      return abs(points[pi][0] - points[pj][0]) +
             abs(points[pi][1] - points[pj][1]);
    };

    int cost = 0;
    for (size_t connected = 1, cur = 0; connected < points.size();
         ++connected) {
      distances[cur] = std::numeric_limits<int>::max();
      size_t cand = cur;
      for (size_t j = 0; j < points.size(); ++j) {
        if (distances[j] != std::numeric_limits<int>::max()) {
          distances[j] = std::min(distances[j], dist(cur, j));
          if (distances[j] < distances[cand]) {
            cand = j;
          }
        }
      }

      cost += distances[cand];
      cur = cand;
    }
    return cost;
  }
};
