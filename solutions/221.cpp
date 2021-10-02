#include <vector>

class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    char max_side = 0;

    for (size_t row = 0; row < matrix.size(); ++row) {
      for (size_t col = 0; col < matrix.front().size(); ++col) {
        matrix[row][col] =
            matrix[row][col] == '0'
                ? 0
                : 1 + std::min(row ? matrix[row - 1][col] : '\0',
                               std::min(col ? matrix[row][col - 1] : '\0',
                                        row * col ? matrix[row - 1][col - 1]
                                                  : '\0'));
        max_side = std::max(max_side, matrix[row][col]);
      }
    }
    return max_side * max_side;
  }
};
