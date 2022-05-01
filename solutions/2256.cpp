#include <cmath>
#include <numeric>
#include <vector>

class Solution {
 public:
  size_t minimumAverageDifference(std::vector<int>& nums) {
    long pre_sum = 0;
    long post_sum = accumulate(begin(nums), end(nums), 0ll);
    size_t min_index = 0;
    long min_diff = std::numeric_limits<long>::max();
    for (size_t i = 0; i < nums.size(); ++i) {
      pre_sum += nums[i];
      post_sum -= nums[i];
      long pre_avg = pre_sum / static_cast<long>(i + 1);
      long post_avg =
          post_sum ? post_sum / static_cast<long>(nums.size() - i - 1) : 0;

      if (long diff = std::abs(pre_avg - post_avg); diff < min_diff) {
        min_diff = diff;
        min_index = i;
      }
    }
    return min_index;
  }
};
