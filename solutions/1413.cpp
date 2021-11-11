#include <vector>

class Solution {
 public:
  int minStartValue(std::vector<int>& nums) {
    int result = 1;
    int sum = 0;

    for (auto num : nums) {
      sum += num;
      result = std::max(result, 1 - std::min(0, sum));
    }
    return result;
  }
};
