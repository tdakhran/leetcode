#include <numeric>
#include <vector>

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    std::vector<int> dp;
    std::partial_sum(begin(grid.front()), end(grid.front()),
                     std::back_inserter(dp));
    for (size_t row = 1; row < grid.size(); ++row) {
      int left = dp.front();
      for (size_t col = 0; col < grid.front().size(); ++col) {
        left = dp[col] = std::min(dp[col], left) + grid[row][col];
      }
    }
    return dp.back();
  }
};
