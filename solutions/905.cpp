#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> sortArrayByParity(std::vector<int>& nums) {
    std::partition(begin(nums), end(nums), [](int n) { return (n & 1) == 0; });
    return nums;
  }
};
