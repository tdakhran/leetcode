#include <cmath>

class Solution {
 public:
  int arrangeCoins(int n) {
    // n = 1 + 2 + .. + k = (1 + k) * k / 2
    // k^2 + k - 2 * n = 0
    // k = -1 + sqrt(1 + 4 * 2n) / 2 = (sqrt(1 + 8 * n) - 1) / 2;
    return static_cast<int>((sqrt(1ll + 8ll * n) - 1) / 2);
  }
};
