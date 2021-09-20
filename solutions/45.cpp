#include <vector>

class Solution {
 public:
  int jump(std::vector<int>& nums) {
    int count = 0;
    size_t current_longest = 0, next_longest = 0;
    for (size_t pos = 0; pos + 1 < nums.size(); ++pos) {
      next_longest =
          std::max(next_longest, pos + static_cast<size_t>(nums[pos]));
      if (pos == current_longest) {
        ++count;
        current_longest = next_longest;
      }
    }
    return count;
  }
};
