#include <numeric>
#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    return std::accumulate(begin(nums), end(nums), 0, std::bit_xor<int>());
  }
};
