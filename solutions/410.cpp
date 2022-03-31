#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int splitArray(std::vector<int>& nums, int m) {
    auto split_possible = [&nums, &m](int chunk_capacity) {
      int capacity = chunk_capacity;
      int chunks = 1;
      for (auto num : nums) {
        if (capacity >= num) {
          capacity -= num;
        } else if (++chunks > m) {
          return false;
        } else {
          capacity = chunk_capacity - num;
        }
      }
      return true;
    };

    int lo = *std::max_element(begin(nums), end(nums));
    int hi = std::accumulate(begin(nums), end(nums), 0);
    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      if (split_possible(mi)) {
        hi = mi - 1;
      } else {
        lo = mi + 1;
      }
    }
    return hi + 1;
  }
};
