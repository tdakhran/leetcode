#include <vector>

class Solution {
 public:
  int singleNonDuplicate(std::vector<int>& nums) {
    size_t lo = 0;
    size_t hi = nums.size() - 1;

    while (lo < hi) {
      size_t mi = (lo + (hi - lo) / 2ull) & (~1ull);
      if (nums[mi] != nums[mi + 1]) {
        hi = mi;
      } else {
        lo = mi + 2;
      }
    }
    return nums[lo];
  }
};
