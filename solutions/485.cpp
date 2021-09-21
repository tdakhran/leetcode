#include <vector>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    size_t last_zero = 0;
    size_t result = 0;
    for (size_t pos = 0; pos < nums.size(); ++pos) {
      last_zero = nums[pos] ? last_zero : pos + 1;
      result = std::max(result, pos - last_zero + 1);
    }
    return static_cast<int>(result);
  }
};
