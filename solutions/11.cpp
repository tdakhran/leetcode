#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    size_t left = 0;
    size_t right = height.size() - 1;
    int result = 0;

    while (left < right) {
      result = std::max(result, static_cast<int>(right - left) *
                                    std::min(height[left], height[right]));
      height[left] < height[right] ? ++left : --right;
    }
    return result;
  }
};
