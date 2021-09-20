#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int>& nums) {
    size_t longest_jump = 0;
    for (size_t pos = 0; pos <= longest_jump and longest_jump + 1 < nums.size();
         ++pos) {
      longest_jump =
          std::max(longest_jump, pos + static_cast<size_t>(nums[pos]));
    }
    return longest_jump + 1 >= nums.size();
  }
};
