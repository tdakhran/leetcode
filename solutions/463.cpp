#include <vector>

class Solution {
 public:
  int islandPerimeter(std::vector<std::vector<int>>& grid) {
    int result = 0;
    for (size_t row = 0; row < grid.size(); ++row) {
      for (size_t col = 0; col < grid.front().size(); ++col) {
        if (grid[row][col] == 0) {
          continue;
        }
        result += (row == 0 or !grid[row - 1][col]) +
                  (col == 0 or !grid[row][col - 1]) +
                  (row + 1 == grid.size() or !grid[row + 1][col]) +
                  (col + 1 == grid.front().size() or !grid[row][col + 1]);
      }
    }
    return result;
  }
};
