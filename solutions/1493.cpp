#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    struct Group {
      int type{0};
      int count{0};
    };

    Group pprev, prev, curr;

    int longest_ones = 0;
    bool zero_seen = false;

    int result = 0;

    for (auto n : nums) {
      if (n == curr.type) {
        ++curr.count;
      } else {
        pprev = prev;
        prev = curr;
        curr = {n, 1};
      }
      if (pprev.type and curr.type and not prev.type and prev.count == 1) {
        result = std::max(result, pprev.count + curr.count);
      }
      if (curr.type) {
        longest_ones = std::max(longest_ones, curr.count);
      } else {
        zero_seen = true;
      }
    }

    return zero_seen ? std::max(result, longest_ones)
                     : static_cast<int>(nums.size() - 1);
  }
};
