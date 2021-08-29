#include <limits>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> updateMatrix(
      std::vector<std::vector<int>>& mat) {
    std::queue<std::pair<size_t, size_t>> q;
    for (size_t r = 0; r < mat.size(); ++r) {
      for (size_t c = 0; c < mat.front().size(); ++c) {
        if (mat[r][c] == 0) {
          q.push({r, c});
        } else {
          mat[r][c] = std::numeric_limits<int>::max();
        }
      }
    }

    while (!q.empty()) {
      auto qsize = q.size();
      while (qsize--) {
        auto [r, c] = q.front();
        q.pop();
        auto steps = mat[r][c] + 1;

        if (c + 1 < mat.front().size() and mat[r][c + 1] > steps) {
          mat[r][c + 1] = steps;
          q.push({r, c + 1});
        }
        if (c != 0 and mat[r][c - 1] > steps) {
          mat[r][c - 1] = steps;
          q.push({r, c - 1});
        }
        if (r + 1 < mat.size() and mat[r + 1][c] > steps) {
          mat[r + 1][c] = steps;
          q.push({r + 1, c});
        }
        if (r != 0 and mat[r - 1][c] > steps) {
          mat[r - 1][c] = steps;
          q.push({r - 1, c});
        }
      }
    }

    return mat;
  }
};
