#include <functional>
#include <vector>

class Solution {
 public:
  int uniquePathsIII(std::vector<std::vector<int>>& grid) {
    int target_length = 0;
    std::pair<size_t, size_t> start, finish;

    for (size_t row = 0; row < grid.size(); ++row) {
      for (size_t col = 0; col < grid.front().size(); ++col) {
        auto value = grid[row][col];
        start = value == 1 ? std::pair{row, col} : start;
        finish = value == 2 ? std::pair{row, col} : finish;
        target_length += 1 - (value == -1);
      }
    }

    std::function<int(std::pair<size_t, size_t>, int)> dfs =
        [&dfs, target_length, &grid, finish](std::pair<size_t, size_t> pos,
                                             int length) -> int {
      auto [row, col] = pos;
      if (grid[row][col] == -1) {
        return 0;
      }
      if (row == finish.first and col == finish.second) {
        return length == target_length;
      }
      int result = 0;

      grid[row][col] = -1;
      if (row) {
        result += dfs({row - 1, col}, length + 1);
      }
      if (col) {
        result += dfs({row, col - 1}, length + 1);
      }
      if (row + 1 < grid.size()) {
        result += dfs({row + 1, col}, length + 1);
      }
      if (col + 1 < grid.front().size()) {
        result += dfs({row, col + 1}, length + 1);
      }
      grid[row][col] = 0;

      return result;
    };

    return dfs(start, 1);
  }
};
