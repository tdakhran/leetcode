#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    size_t lo = 0;
    size_t hi = numbers.size() - 1;
    while (lo < hi) {
      auto sum = numbers[lo] + numbers[hi];
      if (sum == target) {
        return {static_cast<int>(lo) + 1, static_cast<int>(hi) + 1};
      } else if (sum < target) {
        ++lo;
      } else {
        --hi;
      }
    }
    return {-1, -1};
  }
};
