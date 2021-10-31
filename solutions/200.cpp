#include <functional>
#include <vector>

class Solution {
 public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    std::function<bool(size_t, size_t)> dfs = [&dfs, &grid](size_t row,
                                                            size_t col) {
      if (grid[row][col] == '0') {
        return false;
      }
      grid[row][col] = '0';

      if (row) {
        dfs(row - 1, col);
      }
      if (col) {
        dfs(row, col - 1);
      }
      if (row + 1 < grid.size()) {
        dfs(row + 1, col);
      }
      if (col + 1 < grid.front().size()) {
        dfs(row, col + 1);
      }
      return true;
    };

    int result = 0;
    for (size_t row = 0; row < grid.size(); ++row) {
      for (size_t col = 0; col < grid.front().size(); ++col) {
        result += dfs(row, col);
      }
    }
    return result;
  }
};
