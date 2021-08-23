#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int> &nums) {
    size_t insert_position = 0;
    for (auto &n : nums) {
      if (n) {
        std::swap(n, nums[insert_position++]);
      }
    }
  }
};
