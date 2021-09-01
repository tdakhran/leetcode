#include <vector>

class Solution {
 public:
  int arrayNesting(std::vector<int>& nums) {
    int result = 0;
    for (size_t pos = 0; pos < nums.size(); ++pos) {
      int count = 0;
      for (size_t i = pos; nums[i] >= 0; ++count) {
        auto& current = nums[i];
        i = static_cast<size_t>(nums[i]);
        current = -1;
      }
      result = std::max(result, count);
    }
    return result;
  }
};
