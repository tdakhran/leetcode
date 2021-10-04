#include <vector>

class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> result;
    for (auto n : nums) {
      auto pos = lower_bound(begin(result), end(result), n);
      if (pos == end(result)) {
        result.push_back(n);
      } else {
        *pos = n;
      }
    }
    return static_cast<int>(result.size());
  }
};
