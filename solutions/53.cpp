#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int current_sum = nums.front();
    int max_sum = nums.front();
    for (auto it = next(begin(nums)); it != end(nums); ++it) {
      current_sum = std::max(*it, *it + current_sum);
      max_sum = std::max(current_sum, max_sum);
    }
    return max_sum;
  }
};
