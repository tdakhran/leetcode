#include <limits>
#include <vector>

class Solution {
 public:
  unsigned numSquares(unsigned n) {
    std::vector<unsigned> dp(n + 1);
    for (unsigned pos = 1; pos < dp.size(); ++pos) {
      unsigned num_squares = std::numeric_limits<unsigned>::max();
      for (unsigned value = 1; value * value <= pos; ++value) {
        num_squares = std::min(num_squares, dp[pos - value * value] + 1);
      }
      dp[pos] = num_squares;
    }
    return dp.back();
  }
};
