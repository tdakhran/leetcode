#include <numeric>
#include <vector>

class Solution {
 public:
  int maximumWealth(std::vector<std::vector<int>>& accounts) {
    return std::accumulate(
        std::begin(accounts), std::end(accounts), 0,
        [](int max_value, const auto& vec) {
          return std::max(max_value,
                          std::accumulate(std::begin(vec), std::end(vec), 0));
        });
  }
};
