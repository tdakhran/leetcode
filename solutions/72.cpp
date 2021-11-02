#include <numeric>
#include <string>
#include <vector>

class Solution {
 public:
  size_t minDistance(std::string word1, std::string word2) {
    if (word1.size() > word2.size()) {
      swap(word1, word2);
    }
    if (word1.empty()) {
      return word2.size();
    }
    auto dp = std::vector<size_t>(word1.size() + 1);
    std::iota(begin(dp), end(dp), 0);
    for (size_t row = 0; row < word2.size(); ++row) {
      auto cached_top_left = dp[0] = row;
      for (size_t col = 0; col < word1.size(); ++col) {
        auto next_cached_top_left = dp[col + 1];
        dp[col + 1] = std::min({
            (word1[col] != word2[row]) + cached_top_left,
            1 + dp[col + 1],
            1 + dp[col],
        });
        cached_top_left = next_cached_top_left;
      }
    }
    return dp.back();
  }
};
