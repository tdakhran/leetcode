#include <vector>

class Solution {
 public:
  std::vector<int> rearrangeArray(std::vector<int>& nums) {
    std::vector<int> ans(nums.size());

    for (size_t pos = 0, positive = 0, negative = 1; pos < nums.size(); ++pos) {
      auto& index = nums[pos] > 0 ? positive : negative;
      ans[index] = nums[pos];
      index += 2;
    }

    return ans;
  }
};
