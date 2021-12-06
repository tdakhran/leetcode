#include <algorithm>
#include <array>
#include <vector>

class Solution {
 public:
  std::vector<int> shortestDistanceColor(
      std::vector<int>& colors, std::vector<std::vector<int>>& queries) {
    std::array<std::vector<int>, 3> indices;
    for (size_t pos = 0; pos < colors.size(); ++pos) {
      indices[static_cast<size_t>(colors[pos]) - 1].push_back(
          static_cast<int>(pos));
    }

    std::vector<int> responses;
    for (const auto& query : queries) {
      auto target = query[0];
      const auto& index = indices[static_cast<size_t>(query[1]) - 1];
      if (index.empty()) {
        responses.push_back(-1);
        continue;
      }

      auto it = std::upper_bound(begin(index), end(index), target);
      if (it == end(index)) {
        responses.push_back(std::abs(*prev(it) - target));
      } else if (it == begin(index)) {
        responses.push_back(std::abs(*it - target));
      } else {
        responses.push_back(
            std::min(abs(*it - target), abs(*prev(it) - target)));
      }
    }

    return responses;
  }
};
