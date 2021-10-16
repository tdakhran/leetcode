#include <array>
#include <limits>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    std::array<int, 2> hold{std::numeric_limits<int>::min(),
                            std::numeric_limits<int>::min()};
    std::array<int, 2> sold{0};

    for (auto price : prices) {
      sold[1] = std::max(sold[1], hold[1] + price);
      hold[1] = std::max(hold[1], sold[0] - price);
      sold[0] = std::max(sold[0], hold[0] + price);
      hold[0] = std::max(hold[0], -price);
    }

    return sold[1];
  }
};
