#include <functional>
#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>> &board) {
    // replace 'O' by 'C'
    for (auto &row : board) {
      for (auto &cell : row) {
        if (cell == 'O') {
          cell = 'C';
        }
      }
    }
    // fill 'C' islands by 'O'
    std::function<void(size_t, size_t)> fill_C_by_O =
        [&fill_C_by_O, &board](size_t row, size_t col) {
          if (board[row][col] != 'C') {
            return;
          }
          board[row][col] = 'O';
          if (row) {
            fill_C_by_O(row - 1, col);
          }
          if (col) {
            fill_C_by_O(row, col - 1);
          }
          if (row + 1 < board.size()) {
            fill_C_by_O(row + 1, col);
          }
          if (col + 1 < board.front().size()) {
            fill_C_by_O(row, col + 1);
          }
        };
    // fill islands that are on the border
    for (size_t row = 0; row < board.size(); ++row) {
      fill_C_by_O(row, 0);
      fill_C_by_O(row, board.front().size() - 1);
    }
    for (size_t col = 0; col < board.front().size(); ++col) {
      fill_C_by_O(0, col);
      fill_C_by_O(board.size() - 1, col);
    }

    // at this point all 'C's are surrounded by 'X'
    for (auto &row : board) {
      for (auto &cell : row) {
        if (cell == 'C') {
          cell = 'X';
        }
      }
    }
  }
};
