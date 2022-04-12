#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid,
                                          size_t k) {
    const size_t rows = grid.size();
    const size_t cols = grid.front().size();

    auto result = std::vector<std::vector<int>>(rows, std::vector<int>(cols));
    for (size_t src = 0; src < rows * cols; ++src) {
      size_t dst = (src + k) % (rows * cols);
      result[dst / cols][dst % cols] = grid[src / cols][src % cols];
    }
    return result;
  }
};
