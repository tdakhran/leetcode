#include <limits>
#include <vector>

class Solution {
 public:
  int maxSubarraySumCircular(std::vector<int>& nums) {
    auto length = nums.size();
    int max_sum = std::numeric_limits<int>::min();
    unsigned min_sum_pos = 0;

    // find where minimum is reached
    for (struct alignas(8) {
           unsigned pos = 0;
           int cur_max_sum = 0, cur_min_sum = 0,
               min_sum = std::numeric_limits<int>::max();
         } i;
         i.pos < length; ++i.pos) {
      i.cur_max_sum = std::max(0, i.cur_max_sum) + nums[i.pos];
      i.cur_min_sum = std::min(0, i.cur_min_sum) + nums[i.pos];
      if (i.cur_min_sum <= i.min_sum) {
        i.min_sum = i.cur_min_sum;
        min_sum_pos = i.pos;
      }
      max_sum = std::max(max_sum, i.cur_max_sum);
    }

    // iterate from next position after position where minimum sum reached
    for (struct {
           unsigned pos;
           int cur_max_sum;
         } i{0, 0};
         i.pos < length; ++i.pos) {
      i.cur_max_sum += nums[(i.pos + min_sum_pos + 1) % length];
      max_sum = std::max(max_sum, i.cur_max_sum);
    }

    return max_sum;
  }
};
