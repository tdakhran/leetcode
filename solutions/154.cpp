#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    size_t lo = 0;
    size_t hi = nums.size() - 1;
    while (lo < hi) {
      size_t mi = lo + (hi - lo) / 2;
      if (nums[hi] < nums[mi]) {
        lo = mi + 1;
      } else if (nums[hi] < nums[mi]) {
        hi = mi - 1;
      } else if (nums[lo] == nums[mi]) {
        ++lo;
        --hi;
      } else {
        hi = mi;
      }
    }
    return nums[hi];
  }
};
