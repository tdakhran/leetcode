#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    long result = 0;
    std::vector<std::unordered_map<long, int>> count(nums.size());
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        auto diff = static_cast<long>(nums[i]) - nums[j];
        auto& i_diff = count[i][diff];
        ++i_diff;

        if (auto j_diff = count[j].find(diff); j_diff != count[j].end()) {
          i_diff += j_diff->second;
          result += j_diff->second;
        }
      }
    }

    return static_cast<int>(result);
  }
};
