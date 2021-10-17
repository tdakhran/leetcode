#include <vector>

class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    size_t row = 0, col = matrix.front().size();
    for (; row < matrix.size() and col > 0 and matrix[row][col - 1] != target;
         (matrix[row][col - 1] > target) ? --col : ++row) {
    }
    return row < matrix.size() and col > 0;
  }
};
