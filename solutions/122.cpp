#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    for (size_t pos = 1; pos < prices.size(); ++pos) {
      max_profit += std::max(prices[pos] - prices[pos - 1], 0);
    }
    return max_profit;
  }
};
