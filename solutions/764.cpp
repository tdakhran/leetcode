#include <limits>
#include <vector>

class Solution {
 public:
  int orderOfLargestPlusSign(size_t n, std::vector<std::vector<int>>& mines) {
    auto field = std::vector<std::vector<unsigned>>(
        n, std::vector<unsigned>(n, std::numeric_limits<unsigned>::max()));
    for (const auto& mine : mines) {
      field[static_cast<size_t>(mine[0])][static_cast<size_t>(mine[1])] = 0;
    }

    // left to right
    for (size_t row = 0; row < field.size(); ++row) {
      unsigned acc = 0;
      for (size_t col = 0; col < field.front().size(); ++col) {
        acc = field[row][col] ? (acc + 1) : 0;
        field[row][col] = std::min(field[row][col], acc);
      }
    }

    // right to left
    for (size_t row = field.size(); row > 0; --row) {
      unsigned acc = 0;
      for (size_t col = field.front().size(); col > 0; --col) {
        acc = field[row - 1][col - 1] ? (acc + 1) : 0;
        field[row - 1][col - 1] = std::min(field[row - 1][col - 1], acc);
      }
    }

    // top to bottom
    for (size_t col = 0; col < field.front().size(); ++col) {
      unsigned acc = 0;
      for (size_t row = 0; row < field.size(); ++row) {
        acc = field[row][col] ? (acc + 1) : 0;
        field[row][col] = std::min(field[row][col], acc);
      }
    }

    // bottom to top
    unsigned result = 0;
    for (size_t col = field.front().size(); col > 0; --col) {
      unsigned acc = 0;
      for (size_t row = field.size(); row > 0; --row) {
        acc = field[row - 1][col - 1] ? (acc + 1) : 0;
        result = std::max(result, std::min(field[row - 1][col - 1], acc));
      }
    }

    return static_cast<int>(result);
  }
};
