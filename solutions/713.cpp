#include <vector>

class Solution {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    size_t pos = 0;
    int prod = 1;
    int count = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      prod *= nums[i];
      while (pos <= i and prod >= k) {
        prod /= nums[pos++];
      }
      count += std::max<size_t>(i - pos + 1, 0);
    }
    return count;
  }
};
