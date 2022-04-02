#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProductPath(const std::vector<std::vector<int>> &grid) {
    const auto M = grid.front().size();
    std::vector<std::pair<int64_t, int64_t>> curr(M), next(M);

    std::transform(begin(grid[0]), end(grid[0]), begin(curr),
                   [acc = 1](const int e) mutable {
                     acc *= e;
                     return std::pair{acc, acc};
                   });

    for (auto row = std::next(begin(grid)); row != end(grid); ++row) {
      next[0] =
          std::minmax(curr[0].first * (*row)[0], curr[0].second * (*row)[0]);
      for (size_t col = 1; col < next.size(); ++col) {
        const auto val = row->operator[](col);
        const auto &top = curr[col];
        const auto &left = next[col - 1];

        next[col] = std::minmax({top.first * val, top.second * val,
                                 left.first * val, left.second * val});
      }
      swap(curr, next);
    }

    return curr.back().second < 0 ? -1 : curr.back().second % 1'000'000'007;
  }
};
