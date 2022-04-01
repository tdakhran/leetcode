#include <vector>

class Solution {
 public:
  std::vector<int> rearrangeArray(std::vector<int>& nums) {
    for (size_t p = 1; p + 1 < nums.size(); ++p) {
      if (nums[p + 1] + nums[p - 1] == 2 * nums[p]) {
        std::swap(nums[p], nums[p + 1]);
      }
    }
    for (size_t p = nums.size(); p > 2; --p) {
      if (nums[p - 1] + nums[p - 3] == 2 * nums[p - 2]) {
        std::swap(nums[p - 2], nums[p - 1]);
      }
    }
    return nums;
  }
};
