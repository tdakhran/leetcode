#include <cmath>
#include <vector>

class Solution {
 public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    for (auto n : nums) {
      size_t index = static_cast<size_t>(std::abs(n) - 1);
      if (nums[index] > 0) {
        nums[index] *= -1;
      }
    }
    std::vector<int> result;
    for (size_t pos = 0; pos < nums.size(); ++pos) {
      if (nums[pos] > 0) {
        result.push_back(static_cast<int>(pos + 1));
      }
    }
    return result;
  }
};
