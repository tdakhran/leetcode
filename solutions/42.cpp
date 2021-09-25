#include <vector>

class Solution {
 public:
  int trap(const std::vector<int>& height) {
    auto left = height.begin(), right = height.end() - 1;
    int level = 0;
    int water_trapped = 0;
    while (left != right + 1) {
      int lower = *left < *right ? *left++ : *right--;
      level = std::max(level, lower);
      water_trapped += level - lower;
    }
    return water_trapped;
  }
};
