#include <algorithm>

class Solution {
 public:
  int integerBreak(int n) {
    int result = 0;
    for (int k = 2; k <= n; ++k) {
      int n_div_k = n / k;
      int remainder = n % k;
      int current_result = 1;
      for (int i = 0; i < k; ++i) {
        current_result *= n_div_k + (remainder-- > 0);
      }
      result = std::max(result, current_result);
    }
    return result;
  }
};
