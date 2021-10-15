#include <limits>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int buy = std::numeric_limits<int>::min();
    int sell = 0, prev_sell = 0;
    for (auto price : prices) {
      auto prev_buy = buy;
      buy = std::max(prev_sell - price, buy);
      prev_sell = sell;
      sell = std::max(prev_buy + price, sell);
    }

    return sell;
  }
};
