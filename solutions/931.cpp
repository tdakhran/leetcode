#include <algorithm>
#include <vector>

class Solution {
 public:
  int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    for (size_t row = 1; row < n; ++row) {
      matrix[row][0] += std::min(matrix[row - 1][0], matrix[row - 1][1]);
      for (size_t col = 1; col + 1 < n; ++col) {
        matrix[row][col] +=
            std::min(std::min(matrix[row - 1][col - 1], matrix[row - 1][col]),
                     matrix[row - 1][col + 1]);
      }
      matrix[row][n - 1] +=
          std::min(matrix[row - 1][n - 1], matrix[row - 1][n - 2]);
    }
    return *std::min_element(begin(matrix.back()), end(matrix.back()));
  }
};
