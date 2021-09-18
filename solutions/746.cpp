#include <vector>

class Solution {
 public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    auto pprev = 0;
    auto prev = 0;

    for (size_t pos = 2; pos <= cost.size(); ++pos) {
      auto nprev = std::min(pprev + cost[pos - 2], prev + cost[pos - 1]);
      pprev = prev;
      prev = nprev;
    }
    return prev;
  }
};
