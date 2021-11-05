#include <vector>

class Solution {
 public:
  int findLengthOfLCIS(std::vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int count = 1;
    int result = 1;
    for (size_t k = 1; k < nums.size(); ++k) {
      if (nums[k] <= nums[k - 1]) {
        count = 0;
      }
      ++count;
      result = std::max(result, count);
    }
    return result;
  }
};
