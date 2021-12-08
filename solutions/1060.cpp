#include <vector>

class Solution {
 public:
  int missingElement(std::vector<int>& nums, int k) {
    int lo = 0;
    int hi = static_cast<int>(nums.size() - 1);

    if (nums.front() + hi + k > nums.back()) {
      return nums.front() + hi + k;
    }

    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (nums.front() + mi + k > nums[static_cast<size_t>(mi)]) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return nums.front() + (lo - 1) + k;
  }
};
