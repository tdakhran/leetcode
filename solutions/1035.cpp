#include <vector>

class Solution {
 public:
  int maxUncrossedLines(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> dp(nums2.size() + 1);
    for (auto value : nums1) {
      auto prev = 0;
      for (size_t j = 0; j < nums2.size(); ++j) {
        auto tmp = dp[j + 1];
        dp[j + 1] =
            std::max(dp[j + 1], std::max(dp[j], prev + (value == nums2[j])));
        prev = tmp;
      }
    }
    return dp.back();
  }
};
