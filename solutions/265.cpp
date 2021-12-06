#include <algorithm>
#include <array>
#include <vector>

class Solution {
 public:
  int minCostII(std::vector<std::vector<int>> &costs) {
    const size_t k = costs.front().size();
    auto states = std::vector<int>(k);
    for (const auto &cost : costs) {
      std::array<int, 2> minimums{std::numeric_limits<int>::max(),
                                  std::numeric_limits<int>::max()};
      for (auto state : states) {
        for (auto &minimum : minimums) {
          if (state < minimum) {
            std::swap(state, minimum);
          }
        }
      }
      for (size_t i = 0; i < k; ++i) {
        states[i] =
            cost[i] + (states[i] == minimums[0] ? minimums[1] : minimums[0]);
      }
    }
    return *std::min_element(begin(states), end(states));
  }
};
