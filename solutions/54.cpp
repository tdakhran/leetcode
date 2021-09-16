#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;

    size_t top = 0;
    size_t right = matrix.front().size();
    size_t bot = matrix.size();
    size_t left = 0;

    while (result.size() < matrix.front().size() * matrix.size()) {
      for (size_t col = left; col < right; ++col) {
        result.push_back(matrix[top][col]);
      }
      ++top;

      for (size_t row = top; row < bot; ++row) {
        result.push_back(matrix[row][right - 1]);
      }
      --right;

      for (size_t col = right; top < bot and col > left; --col) {
        result.push_back(matrix[bot - 1][col - 1]);
      }
      --bot;

      for (size_t row = bot; left < right and row > top; --row) {
        result.push_back(matrix[row - 1][left]);
      }
      ++left;
    }
    return result;
  }
};
