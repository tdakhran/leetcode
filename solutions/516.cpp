#include <string>
#include <vector>

class Solution {
 public:
  // LCS between string and reversed
  int longestPalindromeSubseq(std::string s) {
    auto dp = std::vector<int>(s.size() + 1);

    for (size_t row = 1; row < dp.size(); ++row) {
      int cached_top_left = 0;
      for (size_t col = 1; col < dp.size(); ++col) {
        int next_cached_top_left = dp[col];
        dp[col] = s[row - 1] == s[s.size() - col]
                      ? 1 + cached_top_left
                      : std::max(dp[col], dp[col - 1]);
        cached_top_left = next_cached_top_left;
      }
    }
    return dp.back();
  }
};
