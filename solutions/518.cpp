#include <vector>

class Solution {
 public:
  int change(size_t amount, std::vector<int>& coins) {
    std::vector<int> dp(amount + 1);
    dp[0] = 1;
    for (auto coin : coins) {
      for (size_t coin_value = static_cast<size_t>(coin), i = 0;
           i + coin_value <= amount; ++i) {
        dp[i + coin_value] += dp[i];
      }
    }
    return dp.back();
  }
};
