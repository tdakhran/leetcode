#include <vector>

class Solution {
  size_t area(std::vector<std::vector<int>>& grid, size_t r, size_t c) {
    if (!grid[r][c]) {
      return 0;
    }
    grid[r][c] = 0;
    size_t result = 1;
    if (c + 1 < grid.front().size()) {
      result += area(grid, r, c + 1);
    }
    if (c != 0) {
      result += area(grid, r, c - 1);
    }
    if (r != 0) {
      result += area(grid, r - 1, c);
    }
    if (r + 1 < grid.size()) {
      result += area(grid, r + 1, c);
    }
    return result;
  }

 public:
  size_t maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    size_t result = 0;
    for (size_t r = 0; r < grid.size(); ++r) {
      for (size_t c = 0; c < grid.front().size(); ++c) {
        result = std::max(result, area(grid, r, c));
      }
    }
    return result;
  }
};
