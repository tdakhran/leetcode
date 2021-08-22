#include <algorithm>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    auto rotation_pos = begin(nums) + (k % static_cast<int>(nums.size()));
    std::reverse(begin(nums), end(nums));
    std::reverse(begin(nums), rotation_pos);
    std::reverse(rotation_pos, end(nums));
  }
};
