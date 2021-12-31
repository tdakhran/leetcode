#include <cstdlib>
#include <limits>
#include <vector>

class Solution {
 public:
  int minimizeTheDifference(std::vector<std::vector<int>>& mat, int target) {
    const int threshold = 2 * target;

    std::vector<int> dp_prev(static_cast<size_t>(threshold), -1),
        dp_curr(static_cast<size_t>(threshold), -1);
    dp_prev[0] = 0;
    int prev_min_sum = 0;

    for (int row = 0; row < static_cast<int>(mat.size()); ++row) {
      int curr_min_sum = std::numeric_limits<int>::max();
      for (auto value : mat[static_cast<size_t>(row)]) {
        for (int sum = 0; sum < threshold; ++sum) {
          if (dp_prev[static_cast<size_t>(sum)] != row) {
            continue;
          }
          int next_sum = value + sum;
          if (next_sum < threshold) {
            dp_curr[static_cast<size_t>(next_sum)] = row + 1;
          }
          curr_min_sum = std::min(curr_min_sum, next_sum);
        }
        curr_min_sum = std::min(curr_min_sum, value + prev_min_sum);
      }
      prev_min_sum = curr_min_sum;
      swap(dp_prev, dp_curr);
    }

    int result = abs(prev_min_sum - target);
    for (int sum = 0; sum < 2 * target; ++sum) {
      if (dp_prev[static_cast<size_t>(sum)] == static_cast<int>(mat.size())) {
        result = std::min(result, abs(sum - target));
      }
    }
    return result;
  }
};
