#include <functional>
#include <string>
#include <vector>
class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(size_t n) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> cur(n, std::string(n, '.'));
    std::vector<bool> mark_cols(n);
    std::vector<bool> mark_diags45(2 * n - 1);
    std::vector<bool> mark_diags135(2 * n - 1);

    std::function<void(size_t)> backtrack = [&](size_t row) {
      if (row == n) {
        result.push_back(cur);
        return;
      }

      for (size_t col = 0; col < n; ++col) {
        if (auto mark_45 = mark_diags45[col - row + n],
            mark_135 = mark_diags135[col + row], mark_col = mark_cols[col];
            not(mark_45 or mark_135 or mark_col)) {
          mark_45 = mark_135 = mark_col = true;
          cur[row][col] = 'Q';
          backtrack(row + 1);
          cur[row][col] = '.';
          mark_45 = mark_135 = mark_col = false;
        }
      }
    };

    backtrack(0);

    return result;
  }
};
