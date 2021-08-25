#include <cmath>

class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int64_t a = 0; a * a <= c; ++a) {
      auto b2 = c - a * a;
      int64_t b = static_cast<int64_t>(std::sqrt(b2));
      if (b * b == b2) {
        return true;
      }
    }
    return false;
  }
};
