#include <vector>

class Solution {
 public:
  int findNumberOfLIS(std::vector<int>& nums) {
    auto n = nums.size();
    if (n < 2) {
      return static_cast<int>(n);
    }
    int longest = 0;
    std::vector<int> lengths(n);
    std::vector<int> count(n, 1);

    for (size_t j = 0; j < n; ++j) {
      for (size_t i = 0; i < j; ++i) {
        if (nums[i] < nums[j]) {
          if (lengths[i] >= lengths[j]) {
            lengths[j] = lengths[i] + 1;
            longest = std::max(longest, lengths[j]);
            count[j] = count[i];
          } else if (lengths[i] + 1 == lengths[j]) {
            count[j] += count[i];
          }
        }
      }
    }

    int result = 0;
    for (size_t i = 0; i < n; ++i) {
      if (lengths[i] == longest) {
        result += count[i];
      }
    }
    return result;
  }
};
