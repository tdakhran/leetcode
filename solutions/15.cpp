#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;

    std::sort(begin(nums), end(nums));
    for (size_t i = 0; i + 2 < nums.size(); ++i) {
      size_t j = i + 1;
      size_t k = nums.size() - 1;
      while (j < k) {
        auto sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          result.push_back({nums[i], nums[j], nums[k]});
          while (j < k and nums[j] == nums[j + 1]) {
            ++j;
          }
          while (j < k and nums[k] == nums[k - 1]) {
            --k;
          }
          ++j;
          --k;
        } else if (sum < 0) {
          ++j;
        } else {
          --k;
        }
      }
      while (i + 2 < nums.size() and nums[i] == nums[i + 1]) {
        ++i;
      }
    }

    return result;
  }
};
