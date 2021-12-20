#include <vector>

class Solution {
 public:
  int maxKilledEnemies(std::vector<std::vector<char>>& grid) {
    auto cache = std::vector<std::vector<int>>(
        grid.size(), std::vector<int>(grid.front().size()));
    int result = 0;

    auto visit = [&](size_t row, size_t col, size_t d_row, size_t d_col) {
      int count = 0;
      while (row < cache.size() and col < cache.front().size()) {
        auto cell = grid[row][col];
        if (cell == 'E') {
          ++count;
        } else if (cell == 'W') {
          count = 0;
        } else {
          cache[row][col] += count;
          result = std::max(result, cache[row][col]);
        }
        row += d_row;
        col += d_col;
      }
    };

    // left and right
    for (size_t row = 0; row < grid.size(); ++row) {
      visit(row, 0, 0, 1);
      visit(row, grid.front().size() - 1, 0, ~0ull);
    }

    // top and down
    for (size_t col = 0; col < grid.front().size(); ++col) {
      visit(0, col, 1, 0);
      visit(grid.size() - 1, col, ~0ull, 0);
    }

    return result;
  }
};
