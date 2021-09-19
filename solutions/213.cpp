#include <vector>

class Solution {
  int rob(const std::vector<int>& nums, size_t start, size_t end) {
    int last = 0;
    int prelast = 0;
    for (size_t pos = start; pos < end; ++pos) {
      int new_prelast = std::max(last, prelast);
      int new_last = nums[pos] + prelast;
      prelast = new_prelast;
      last = new_last;
    }
    return std::max(prelast, last);
  }

 public:
  int rob(std::vector<int>& nums) {
    if (nums.size() < 2) {
      return nums[0];
    }
    return std::max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }
};
