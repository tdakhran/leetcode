#include <array>
#include <vector>

class Solution {
 public:
  int minCost(std::vector<std::vector<int>>& costs) {
    using State = std::array<int, 3>;
    State s{0};

    for (const auto& cost : costs) {
      s = {std::min(s[1], s[2]) + cost[0], std::min(s[0], s[2]) + cost[1],
           std::min(s[0], s[1]) + cost[2]};
    }

    return std::min(s[0], std::min(s[1], s[2]));
  }
};
