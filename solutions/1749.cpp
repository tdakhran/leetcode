#include <vector>

class Solution {
 public:
  int maxAbsoluteSum(std::vector<int>& nums) {
    int sum_positive = 0;
    int sum_negative = 0;
    int result = 0;
    for (auto val : nums) {
      sum_positive = std::max(sum_positive + val, 0);
      sum_negative = std::max(sum_negative - val, 0);
      result = std::max(result, std::max(sum_positive, sum_negative));
    }
    return result;
  }
};
