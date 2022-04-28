#include <functional>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  int minimumEffortPath(std::vector<std::vector<int>>& heights) {
    using Coord = std::pair<size_t, size_t>;
    size_t rows = heights.size();
    size_t cols = heights.front().size();
    std::vector<std::vector<int>> steps(
        rows, std::vector<int>(cols, std::numeric_limits<int>::max()));
    steps[0][0] = 0;
    std::priority_queue<Coord, std::vector<Coord>,
                        std::function<bool(Coord, Coord)>>
        pq([&steps](Coord a, Coord b) {
          return steps[a.first][a.second] > steps[b.first][b.second];
        });

    pq.push({0, 0});

    const std::vector<Coord> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    while (not pq.empty()) {
      auto [r, c] = pq.top();
      pq.pop();

      for (auto [dr, dc] : dirs) {
        auto nr = r + dr;
        auto nc = c + dc;
        if (nr >= rows or nc >= cols) {
          continue;
        }
        auto nsteps =
            std::max(steps[r][c], abs(heights[nr][nc] - heights[r][c]));
        if (nsteps < steps[nr][nc]) {
          steps[nr][nc] = nsteps;
          pq.push({nr, nc});
        }
      }
    }
    return steps.back().back();
  }
};
