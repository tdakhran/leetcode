#include <queue>
#include <vector>

class Solution {
 public:
  int orangesRotting(std::vector<std::vector<int>>& grid) {
    std::queue<std::pair<size_t, size_t>> q;
    for (size_t r = 0; r < grid.size(); ++r) {
      for (size_t c = 0; c < grid.front().size(); ++c) {
        if (grid[r][c] == 2) {
          q.push({r, c});
        }
      }
    }
    int steps = 0;
    while (not q.empty()) {
      ++steps;
      auto qsize = q.size();
      while (qsize--) {
        auto [r, c] = q.front();
        q.pop();

        if (c + 1 < grid.front().size() and grid[r][c + 1] == 1) {
          grid[r][c + 1] = 2;
          q.push({r, c + 1});
        }
        if (c != 0 and grid[r][c - 1] == 1) {
          grid[r][c - 1] = 2;
          q.push({r, c - 1});
        }
        if (r + 1 < grid.size() and grid[r + 1][c] == 1) {
          grid[r + 1][c] = 2;
          q.push({r + 1, c});
        }
        if (r != 0 and grid[r - 1][c] == 1) {
          grid[r - 1][c] = 2;
          q.push({r - 1, c});
        }
      }
    }

    for (const auto& row : grid) {
      for (const auto cell : row) {
        if (cell == 1) {
          return -1;
        }
      }
    }

    return steps ? steps - 1 : 0;
  }
};
