#include <algorithm>
#include <vector>

class Solution {
 public:
  int cherryPickup(std::vector<std::vector<int>> &grid) {
    auto n = grid.front().size();
    auto curr = std::vector<std::pair<int, size_t>>(n * n);
    auto next = curr;
    curr[n - 1] = {grid[0][0] + grid[0][n - 1], 1};

    for (size_t row = 1; row < grid.size(); ++row) {
      for (size_t pos = 0; pos < n * n; ++pos) {
        const auto &curr_val = curr[pos];
        if (curr_val.second != row) {
          continue;
        }
        size_t r1 = pos / n;
        size_t r2 = pos % n;
        for (int dr1 = -1; dr1 <= 1; ++dr1) {
          for (int dr2 = -1; dr2 <= 1; ++dr2) {
            size_t nr1 = r1 + static_cast<size_t>(dr1);
            if (nr1 >= n) {
              continue;
            }
            size_t nr2 = r2 + static_cast<size_t>(dr2);
            if (nr2 >= n) {
              continue;
            }
            if (nr1 == nr2) {
              continue;
            }
            auto cherries = curr_val.first + grid[row][nr1] + grid[row][nr2];
            auto &next_val = next[nr1 * n + nr2];
            if (next_val.second != row + 1 or next_val.first < cherries) {
              next_val = {cherries, row + 1};
            }
          }
        }
      }
      swap(curr, next);
    }

    return std::max_element(begin(curr), end(curr))->first;
  }
};
