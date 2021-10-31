#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                         int k) {
    std::priority_queue<std::pair<int, std::vector<int>>> pq;

    auto distance = [](const auto &point) {
      return point[0] * point[0] + point[1] * point[1];
    };

    for (auto &point : points) {
      auto d = distance(point);
      pq.push({d, std::move(point)});
      if (pq.size() > static_cast<size_t>(k)) {
        pq.pop();
      }
    }

    std::vector<std::vector<int>> result;
    while (not pq.empty()) {
      result.emplace_back(std::move(pq.top().second));
      pq.pop();
    }
    return result;
  }
};
