#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {
    std::priority_queue<std::pair<int, size_t>> pq;

    auto distance = [](const auto &point) {
      return point[0] * point[0] + point[1] * point[1];
    };

    for (size_t pos = 0; pos < points.size(); ++pos) {
      auto d = distance(points[pos]);
      pq.push({d, pos});
      if (pq.size() > static_cast<size_t>(k)) {
        pq.pop();
      }
    }

    std::vector<std::vector<int>> result;
    while (not pq.empty()) {
      result.emplace_back(points[pq.top().second]);
      pq.pop();
    }
    return result;
  }
};
