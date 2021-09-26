#include <vector>

class Solution {
 public:
  int movesToChessboard(std::vector<std::vector<int>>& board) {
    auto n = board.size();
    for (size_t row = 0; row < n; ++row) {
      for (size_t col = 0; col < n; ++col) {
        // possible options:  [0 0] [0 1] [1 0] [1 1]
        //                    [0 0] [1 0] [0 1] [1 1]
        if (board[0][0] ^ board[row][0] ^ board[0][col] ^ board[row][col]) {
          return -1;
        }
      }
    }
    auto row_sum = 0, col_sum = 0;
    auto row_inv = 0, col_inv = 0;
    for (size_t index = 0; index < n; ++index) {
      row_sum += board[0][index];
      col_sum += board[index][0];
      row_inv += board[index][0] == (index & 1);
      col_inv += board[0][index] == (index & 1);
    }
    if (row_sum != n / 2 && row_sum != (n + 1) / 2) {
      return -1;
    }
    if (col_sum != n / 2 && col_sum != (n + 1) / 2) {
      return -1;
    }

    auto reverse_col_inv = static_cast<int>(n) - col_inv;
    auto reverse_row_inv = static_cast<int>(n) - row_inv;
    if (n & 1) {
      if (col_inv & 1) {
        col_inv = reverse_col_inv;
      }
      if (row_inv & 1) {
        row_inv = reverse_row_inv;
      }
    } else {
      col_inv = std::min(col_inv, reverse_col_inv);
      row_inv = std::min(row_inv, reverse_row_inv);
    }
    return (col_inv + row_inv) / 2;
  }
};
