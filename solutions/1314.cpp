#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> matrixBlockSum(
      std::vector<std::vector<int>>& mat, size_t k) {
    size_t rows = mat.size();
    size_t cols = mat.front().size();
    auto tmp = mat;
    for (size_t row = 0; row < rows; ++row) {
      int acc = 0;
      for (size_t col = 0; col < cols + k; ++col) {
        acc += col < cols ? mat[row][col] : 0;
        if (col >= 2 * k + 1) {
          acc -= mat[row][col - 2 * k - 1];
        }
        if (col >= k) {
          tmp[row][col - k] = acc;
        }
      }
    }
    for (size_t col = 0; col < cols; ++col) {
      int acc = 0;
      for (size_t row = 0; row < rows + k; ++row) {
        acc += row < rows ? tmp[row][col] : 0;
        if (row >= 2 * k + 1) {
          acc -= tmp[row - 2 * k - 1][col];
        }
        if (row >= k) {
          mat[row - k][col] = acc;
        }
      }
    }
    return mat;
  }
};
