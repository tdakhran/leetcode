#include <vector>

class Solution {
 public:
  int maxCoins(std::vector<int>& nums) {
    const auto n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    const size_t len = 502;
    auto dp = std::vector<std::vector<int>>(len, std::vector<int>(len));

    for (size_t l = 1; l <= n; l++) {
      for (size_t i = 1; i + l - 1 <= n; i++) {
        size_t j = i + l - 1;  // j - i == l - 1
        for (size_t k = i; k <= j; k++) {
          dp[i][j] = std::max(
              dp[i][j], dp[i][k - 1] + nums[i - 1] * nums[k] * nums[j + 1] +
                            dp[k + 1][j]);
        }
      }
    }
    return dp[1][n];
  }
};
