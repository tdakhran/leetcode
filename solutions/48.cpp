#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>> &mat) {
    size_t n = mat.size();
    for (size_t row = 0; row < n / 2; ++row) {
      for (size_t col = row; col + row + 1 < n; ++col) {
        // rotate
        auto tmp = mat[row][col];               // save top to tmp
        mat[row][col] = mat[n - 1 - col][row];  // top = right
        mat[n - 1 - col][row] = mat[n - 1 - row][n - 1 - col];  // right = bot
        mat[n - 1 - row][n - 1 - col] = mat[col][n - 1 - row];  // bot= left
        mat[col][n - 1 - row] = tmp;                            // left = top
      }
    }
  }
};
