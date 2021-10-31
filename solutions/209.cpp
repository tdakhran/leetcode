#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    size_t result = nums.size() + 1;
    int sum = 0;
    for (size_t lo = 0, hi = 0; hi < nums.size(); ++hi) {
      sum += nums[hi];
      while (sum >= target) {
        result = std::min(result, hi + 1 - lo);
        sum -= nums[lo++];
      }
    }
    return result <= nums.size() ? static_cast<int>(result) : 0;
  }
};
