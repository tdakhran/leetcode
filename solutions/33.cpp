#include <limits>
#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    size_t lo = 0, hi = nums.size();
    while (lo < hi) {
      size_t mi = lo + (hi - lo) / 2;

      auto num = (nums[mi] < nums[0]) == (target < nums[0])
                     ? nums[mi]
                     : target < nums[0] ? std::numeric_limits<int>::min()
                                        : std::numeric_limits<int>::max();

      if (num < target) {
        lo = mi + 1;
      } else if (num > target) {
        hi = mi;
      } else {
        return static_cast<int>(mi);
      }
    }
    return -1;
  }
};
