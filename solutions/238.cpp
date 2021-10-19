#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int zeros_count = 0, product_without_zeros = 1;
    for (auto n : nums) {
      product_without_zeros *= (n ? n : 1);
      zeros_count += (n == 0);
    }
    for (auto& n : nums) {
      if (zeros_count == 0) {
        n = product_without_zeros / n;
      } else if (n == 0 and zeros_count == 1) {
        n = product_without_zeros;
      } else {
        n = 0;
      }
    }
    return nums;
  }
};
