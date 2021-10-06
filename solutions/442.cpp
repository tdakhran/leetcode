#include <cmath>
#include <vector>

class Solution {
 public:
  std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> result;

    for (auto n : nums) {
      auto index = static_cast<size_t>(std::abs(n) - 1);
      if (nums[index] < 0) {
        result.push_back(std::abs(n));
      } else {
        nums[index] *= -1;
      }
    }
    return result;
  }
};
