#include <vector>

class Solution {
 public:
  int wiggleMaxLength(std::vector<int>& nums) {
    auto sign = [](int x) { return (x > 0) - (x < 0); };
    int prev_sign = -2;
    int result = 1;

    for (size_t i = 1; i < nums.size(); ++i) {
      if (auto new_sign = sign(nums[i] - nums[i - 1]);
          new_sign and new_sign != prev_sign) {
        ++result;
        prev_sign = new_sign;
      }
    }
    return result;
  }
};
