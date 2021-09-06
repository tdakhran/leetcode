#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = 10'000;
    for (auto price : prices) {
      max_profit = std::max(max_profit, price - min_price);
      min_price = std::min(min_price, price);
    }
    return max_profit;
  }
};
