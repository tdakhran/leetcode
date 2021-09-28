#include <array>
#include <vector>

class Solution {
 public:
  std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
    std::array<size_t, 2> pos = {0, 1};
    do {
      std::swap(nums[pos[0]], nums[pos[1]]);
      for (auto& p : pos) {
        while (p < nums.size() and
               not((static_cast<size_t>(nums[p]) ^ p) & 1)) {
          p += 2;
        }
      }
    } while (pos[0] < nums.size());
    return nums;
  }
};
