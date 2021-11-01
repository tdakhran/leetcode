#include <string>
#include <vector>

class Solution {
  // from 1143. Longest Common Subsequence
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

 public:
  int minDistance(std::string word1, std::string word2) {
    return static_cast<int>(word1.size() + word2.size()) -
           2 * longestCommonSubsequence(word1, word2);
  }
};
