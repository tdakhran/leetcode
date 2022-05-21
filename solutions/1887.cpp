#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int reductionOperations(std::vector<int>& nums) {
    std::sort(begin(nums), end(nums), std::greater<int>());

    // group similar elements
    std::vector<size_t> groups;
    for (size_t pos = 0; pos < nums.size();) {
      size_t count = 0;
      for (int num = nums[pos]; pos < nums.size() and nums[pos] == num; ++pos) {
        ++count;
      }
      groups.push_back(count);
    }

    std::partial_sum(begin(groups), end(groups), begin(groups));

    return std::accumulate(begin(groups), prev(end(groups)), 0);
  }
};
