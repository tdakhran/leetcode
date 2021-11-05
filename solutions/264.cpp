#include <array>
#include <limits>
#include <vector>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(static_cast<size_t>(n),
                        std::numeric_limits<int>::max());
    dp.front() = 1;

    std::array<std::pair<int, size_t>, 3> mult{{{2, 0}, {3, 0}, {5, 0}}};
    for (size_t pos = 1; pos < dp.size(); ++pos) {
      for (auto &[m, prev_pos] : mult) {
        dp[pos] = std::min(dp[pos], m * dp[prev_pos]);
      }
      for (auto &[m, prev_pos] : mult) {
        if (dp[pos] == m * dp[prev_pos]) {
          ++prev_pos;
        }
      }
    }
    return dp.back();
  }
};
