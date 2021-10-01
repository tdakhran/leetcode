#include <string>
#include <vector>

class Solution {
 public:
  int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<int> dp(text2.size() + 1);
    for (auto value : text1) {
      auto prev = 0;
      for (size_t j = 0; j < text2.size(); ++j) {
        auto tmp = dp[j + 1];
        dp[j + 1] =
            std::max(dp[j + 1], std::max(dp[j], prev + (value == text2[j])));
        prev = tmp;
      }
    }
    return dp.back();
  }
};
