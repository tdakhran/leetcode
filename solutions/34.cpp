#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    auto first = std::lower_bound(begin(nums), end(nums), target);
    if (first == end(nums) or *first != target) {
      return {-1, -1};
    }
    auto last = prev(std::upper_bound(begin(nums), end(nums), target));
    return {static_cast<int>(distance(begin(nums), first)),
            static_cast<int>(distance(begin(nums), last))};
  }
};
