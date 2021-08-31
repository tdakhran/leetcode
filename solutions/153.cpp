#include <vector>

class Solution {
 public:
  int findMin(std::vector<int>& nums) {
    size_t lo = 0;
    size_t hi = nums.size() - 1;

    while (lo < hi) {
      size_t mi = lo + (hi - lo) / 2;

      if (nums[mi] > nums[hi]) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return nums[lo];
  }
};
