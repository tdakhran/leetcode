#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
  static constexpr int hash(int x, int y, int r) {
    return (x << 20) | (y << 10) | r;
  }
  static inline constexpr std::array<std::pair<int, int>, 4> moves{
      {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};

 public:
  int shortestPath(const std::vector<std::vector<int>>& grid,
                   int eliminate_count) const {
    std::unordered_set<int> visited;
    const int rows = static_cast<int>(grid.size());
    const int cols = static_cast<int>(grid.front().size());

    // row, col, eliminate, steps
    std::queue<std::tuple<int, int, int, int>> bfs_queue;
    bfs_queue.push({0, 0, eliminate_count, 0});
    visited.insert(hash(0, 0, eliminate_count));

    auto in_bounds = [rows, cols](int row, int col) {
      return row >= 0 and row < rows and col >= 0 and col < cols;
    };

    while (not bfs_queue.empty()) {
      auto [row, col, eliminate, steps] = bfs_queue.front();
      bfs_queue.pop();

      if (row + 1 == rows and col + 1 == cols) {
        return steps;
      }

      for (const auto& [dx, dy] : moves) {
        if (int nrow = row + dx, ncol = col + dy; in_bounds(nrow, ncol)) {
          int obstacle =
              grid[static_cast<size_t>(nrow)][static_cast<size_t>(ncol)];
          if (int neliminate = eliminate - obstacle;
              neliminate >= 0 and
              visited.insert(hash(nrow, ncol, neliminate)).second) {
            bfs_queue.push({nrow, ncol, neliminate, steps + 1});
          }
        }
      }
    }

    return -1;
  }
};
