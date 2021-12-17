#include <vector>

class Solution {
 public:
  int longestLine(std::vector<std::vector<int>>& mat) {
    int result = 0;

    auto visit = [&mat, &result](size_t row, size_t col, size_t d_row,
                                 size_t d_col) {
      int current = 0;
      while (row < mat.size() and col < mat[0].size()) {
        current = mat[row][col] * (current + 1);
        result = std::max(result, current);
        row += d_row;
        col += d_col;
      }
    };
    // row
    for (size_t row = 0; row < mat.size(); ++row) {
      visit(row, 0, 0, 1);
    }
    // col
    for (size_t col = 0; col < mat[0].size(); ++col) {
      visit(0, col, 1, 0);
    }
    // diagonal
    for (size_t col = 0; col < mat[0].size(); ++col) {
      visit(0, col, 1, 1);
    }
    for (size_t row = 1; row < mat.size(); ++row) {
      visit(row, 0, 1, 1);
    }
    // anti-diagonal
    for (size_t col = 0; col < mat[0].size(); ++col) {
      visit(0, col, 1, ~0ull);
    }
    for (size_t row = 1; row < mat.size(); ++row) {
      visit(row, mat.size() - 1, 1, ~0ull);
    }

    return result;
  }
};
