#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices, int fee) {
    int buy = 0;
    int sell = -prices.front();
    for (auto p : prices) {
      buy = std::max(buy, sell + p - fee);
      sell = std::max(sell, buy - p);
    }
    return buy;
  }
};
