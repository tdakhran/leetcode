#include <vector>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int prev_group_size = 0;
    int current_group_size = 0;
    int result = 0;
    bool has_zero = false;

    for (auto n : nums) {
      if (n) {
        ++current_group_size;
      } else {
        has_zero = true;
        result = std::max(result, 1 + current_group_size + prev_group_size);
        prev_group_size = current_group_size;
        current_group_size = 0;
      }
    }
    return std::max(result, current_group_size + prev_group_size + has_zero);
  }
};
