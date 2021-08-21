#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    size_t lo = 0;
    size_t hi = nums.size();

    while (lo < hi) {
      auto mi = lo + (hi - lo) / 2;
      if (nums[mi] == target) {
        return static_cast<int>(mi);
      } else if (nums[mi] > target) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return -1;
  }
};
