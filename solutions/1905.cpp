#include <queue>
#include <vector>

class Solution {
 public:
  int countSubIslands(std::vector<std::vector<int>>& grid1,
                      std::vector<std::vector<int>>& grid2) {
    std::queue<std::pair<size_t, size_t>> q;
    int count = 0;

    for (size_t r = 0; r < grid2.size(); ++r) {
      for (size_t c = 0; c < grid2[r].size(); ++c) {
        bool sub_island = false;

        if (grid2[r][c]) {
          sub_island = true;
          grid2[r][c] = 0;
          q.push({r, c});
        }

        // bfs the sub island
        while (not q.empty()) {
          auto [row, col] = q.front();
          q.pop();

          if (not grid1[row][col]) {
            sub_island = false;
          }

          if (row and grid2[row - 1][col]) {
            grid2[row - 1][col] = 0;
            q.push({row - 1, col});
          }
          if (col and grid2[row][col - 1]) {
            grid2[row][col - 1] = 0;
            q.push({row, col - 1});
          }

          if (row + 1 < grid2.size() and grid2[row + 1][col]) {
            grid2[row + 1][col] = 0;
            q.push({row + 1, col});
          }
          if (col + 1 < grid2[row].size() and grid2[row][col + 1]) {
            grid2[row][col + 1] = 0;
            q.push({row, col + 1});
          }
        }

        count += sub_island;
      }
    }
    return count;
  }
};
