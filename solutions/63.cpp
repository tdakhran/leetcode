#include <vector>

class Solution {
 public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>>& grid) {
    grid.front().front() = !grid.front().front();
    for (size_t col = 1; col < grid.front().size(); ++col) {
      grid.front()[col] = grid.front()[col] ? 0 : grid.front()[col - 1];
    }

    for (size_t row = 1; row < grid.size(); ++row) {
      grid[row].front() = grid[row].front() ? 0 : grid[row - 1].front();
      for (size_t col = 1; col < grid.front().size(); ++col) {
        grid[row][col] =
            grid[row][col] ? 0 : grid[row - 1][col] + grid[row][col - 1];
      }
    }
    return grid.back().back();
  }
};
