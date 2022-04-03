#include <algorithm>
#include <vector>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    auto i = std::next(nums.rbegin());
    while (i != nums.rend() and *i >= *(prev(i))) {
      ++i;
    }
    if (i != nums.rend()) {
      auto j = nums.rbegin();
      while (*j <= *i) {
        ++j;
      }
      std::swap(*i, *j);
    }
    std::reverse(nums.rbegin(), i);
  }
};
