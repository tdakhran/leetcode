#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& nums) {
    unsigned xor_all =
        accumulate(begin(nums), end(nums), 0u, std::bit_xor<unsigned>());

    while (xor_all & (xor_all - 1)) {
      xor_all &= xor_all - 1;
    }

    std::vector<int> result(2);
    for (auto n : nums) {
      if (n & static_cast<int>(xor_all)) {
        result[0] ^= n;
      } else {
        result[1] ^= n;
      }
    }

    return result;
  }
};
