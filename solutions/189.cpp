#include <numeric>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, size_t k) {
    const size_t cycle_count = std::gcd(nums.size(), k);
    const size_t cycle_size = nums.size() / cycle_count;
    for (size_t cycle = 0; cycle < cycle_count; ++cycle) {
      for (size_t cycle_pos = 0; cycle_pos < cycle_size; ++cycle_pos) {
        std::swap(nums[cycle], nums[(cycle + cycle_pos * k) % nums.size()]);
      }
    }
  }
};
