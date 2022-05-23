#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int findMaxForm(std::vector<std::string>& strs, size_t m, size_t n) {
    auto dp = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));
    for (const auto& str : strs) {
      size_t ones = static_cast<size_t>(std::count(begin(str), end(str), '1'));
      size_t zeros = str.size() - ones;
      for (size_t i0 = m; i0 + 1 > zeros; --i0) {
        for (size_t i1 = n; i1 + 1 > ones; --i1) {
          dp[i0][i1] = std::max(dp[i0][i1], dp[i0 - zeros][i1 - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
