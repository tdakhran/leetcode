#include <cstdint>
#include <limits>
#include <vector>

class Solution {
 public:
  int combinationSum4(std::vector<int>& nums, int target) {
    std::vector<int64_t> dp(static_cast<size_t>(target) + 1);
    dp.front() = 1;
    for (size_t t = 1; t < dp.size(); ++t) {
      for (auto num : nums) {
        auto n = static_cast<size_t>(num);

        if (t >= n) {
          dp[t] = (dp[t] + dp[t - n]) %
                  static_cast<int64_t>(std::numeric_limits<int>::max());
        }
      }
    }
    return static_cast<int>(dp.back());
  }
};
