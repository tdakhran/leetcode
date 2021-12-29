#include <vector>

class Solution {
 public:
  int diagonalSum(std::vector<std::vector<int>>& mat) {
    int result = 0;

    for (size_t row = 0; row < mat.size(); ++row) {
      auto inverted = mat.size() - 1 - row;
      result += mat[row][row] + (row != inverted) * mat[row][inverted];
    }
    return result;
  }
};
