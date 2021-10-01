#include <vector>

class Solution {
 public:
  int uniquePaths(size_t m, size_t n) {
    std::vector<int> dp(n, 1);
    for (size_t row = 1; row < m; ++row) {
      for (size_t col = 1; col < n; ++col) {
        dp[col] += dp[col - 1];
      }
    }
    return dp.back();
  }
};
