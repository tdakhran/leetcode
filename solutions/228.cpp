#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    std::vector<std::string> result;
    if (nums.empty()) {
      return {};
    }
    for (size_t k = 0; k < nums.size(); ++k) {
      size_t start = k;
      while (k + 1 < nums.size() and nums[k + 1] == nums[k] + 1) {
        ++k;
      }
      if (k == start) {
        result.push_back(std::to_string(nums[k]));
      } else {
        result.push_back(std::to_string(nums[start]) + "->" +
                         std::to_string(nums[k]));
      }
    }
    return result;
  }
};
