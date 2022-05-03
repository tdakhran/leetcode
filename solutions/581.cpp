#include <algorithm>
#include <vector>

class Solution {
 public:
  int findUnsortedSubarray(std::vector<int>& nums) {
    auto nums_copy = nums;
    std::sort(begin(nums_copy), end(nums_copy));

    size_t lo = 0;
    size_t hi = nums.size() - 1;
    while (lo < nums.size() and nums[lo] == nums_copy[lo]) {
      ++lo;
    }
    while (hi >= lo and nums[hi] == nums_copy[hi]) {
      --hi;
    }
    return static_cast<int>(hi - lo + 1);
  }
};
