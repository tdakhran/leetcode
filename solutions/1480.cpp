#include <vector>

class Solution {
 public:
  std::vector<int> runningSum(const std::vector<int>& nums) const {
    std::vector<int> running_sum(nums.size());
    running_sum.front() = nums.front();
    for (size_t pos = 1; pos < nums.size(); ++pos) {
      running_sum[pos] = running_sum[pos - 1] + nums[pos];
    }
    return running_sum;
  }
};
