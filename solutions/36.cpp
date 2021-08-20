#include <array>
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char> >& board) {
    std::array<std::array<unsigned, 9>, 9> rows{{{0}}}, cols{{{0}}},
        tiles{{{0}}};

    for (size_t row = 0; row < board.size(); ++row) {
      for (size_t col = 0; col < board.front().size(); ++col) {
        size_t tile = ((row / 3) * 3) + (col / 3);
        if (board[row][col] == '.') {
          continue;
        }
        unsigned value = static_cast<unsigned>(board[row][col] - '0' - 1);
        if (rows[row][value] or cols[col][value] or tiles[tile][value]) {
          return false;
        }
        ++rows[row][value];
        ++cols[col][value];
        ++tiles[tile][value];
      }
    }
    return true;
  }
};
