#include <vector>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    size_t lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
      size_t mi = lo + (hi - lo) / 2;
      if (nums[mi] > nums[mi + 1]) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return static_cast<int>(lo);
  }
};
