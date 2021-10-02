#include <limits>
#include <vector>

class Solution {
 public:
  int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
    auto dp =
        std::vector<int>(dungeon.size() + 1, std::numeric_limits<int>::max());
    dp[dungeon.size() - 1] = 1;

    for (size_t col = dungeon.front().size(); col > 0; --col) {
      for (size_t row = dungeon.size(); row > 0; --row) {
        dp[row - 1] = std::max(
            1, std::min(dp[row - 1], dp[row]) - dungeon[row - 1][col - 1]);
      }
    }
    return dp.front();
  }
};
