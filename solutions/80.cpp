#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    size_t insert_pos = 2;
    for (size_t pos = 2; pos < nums.size(); ++pos) {
      if (nums[pos] != nums[insert_pos - 1] or
          nums[pos] != nums[insert_pos - 2]) {
        nums[insert_pos++] = nums[pos];
      }
    }
    return static_cast<int>(std::min(insert_pos, nums.size()));
  }
};
