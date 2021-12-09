#include <vector>

class Solution {
 public:
  size_t longestOnes(std::vector<int>& nums, size_t k) {
    size_t result = 0;
    for (size_t zeros = 0, start = 0, pos = 0; pos < nums.size(); ++pos) {
      zeros += nums[pos] == 0;
      while (zeros > k) {
        zeros -= nums[start++] == 0;
      }
      result = std::max(result, pos - start + 1);
    }
    return result;
  }
};
