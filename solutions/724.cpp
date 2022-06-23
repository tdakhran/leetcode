#include <numeric>
#include <vector>

class Solution {
 public:
  int pivotIndex(std::vector<int>& nums) {
    int left_sum = 0;
    int right_sum = std::accumulate(begin(nums), end(nums), 0);
    for (size_t pivot = 0; pivot < nums.size(); ++pivot) {
      right_sum -= nums[pivot];
      if (left_sum == right_sum) {
        return static_cast<int>(pivot);
      }
      left_sum += nums[pivot];
    }
    return -1;
  }
};
