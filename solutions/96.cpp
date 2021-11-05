#include <vector>

class Solution {
 public:
  int numTrees(int n) {
    std::vector<int> dp(static_cast<size_t>(n + 1));
    dp.front() = 1;
    for (size_t pos = 1; pos < dp.size(); ++pos) {
      for (size_t root = 0; root < pos; ++root) {
        dp[pos] += dp[root] * dp[pos - root - 1];
      }
    }
    return dp.back();
  }
};
