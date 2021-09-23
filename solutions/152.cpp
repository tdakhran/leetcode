#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    int result = nums.front();
    std::pair product{1, 1};  // <-- keep track min and max products
    for (auto n : nums) {
      product = {std::min(n, std::min(product.first * n, product.second * n)),
                 std::max(n, std::max(product.first * n, product.second * n))};
      result = std::max(result, product.second);
    }
    return result;
  }
};
