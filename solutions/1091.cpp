#include <array>
#include <queue>
#include <vector>

class Solution {
  static inline constexpr std::array<std::pair<int, int>, 8> neighbors{
      {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};

 public:
  int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<int, int>> q;
    if (grid[0][0] == 0) {
      q.push({0, 0});
      grid[0][0] = 1;
    }

    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid.front().size());

    for (int steps = 1; not q.empty(); ++steps) {
      auto sz = q.size();
      while (sz--) {
        auto [row, col] = q.front();
        q.pop();
        if (row == rows - 1 and col == cols - 1) {
          return steps;
        }

        for (const auto& [d_row, d_col] : neighbors) {
          int n_row = row + d_row;
          int n_col = col + d_col;
          if (n_row < 0 or n_col < 0 or n_row >= rows or n_col >= cols or
              grid[static_cast<size_t>(n_row)][static_cast<size_t>(n_col)]) {
            continue;
          }
          grid[static_cast<size_t>(n_row)][static_cast<size_t>(n_col)] = 1;
          q.push({n_row, n_col});
        }
      }
    }
    return -1;
  }
};
