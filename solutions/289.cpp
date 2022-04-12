#include <array>
#include <vector>

class Solution {
 public:
  static inline constexpr std::array<std::pair<int, int>, 8> deltas{
      {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};

  void gameOfLife(std::vector<std::vector<int>> &board) {
    for (size_t i = 0; i < board.size(); ++i) {
      for (size_t j = 0; j < board[i].size(); ++j) {
        int nei = 0;
        for (auto [di, dj] : deltas) {
          size_t ni = i + static_cast<size_t>(di);
          size_t nj = j + static_cast<size_t>(dj);
          if (ni < board.size() and nj < board[i].size()) {
            nei += (board[ni][nj] & 1);
          }
        }
        int value = ((board[i][j] & 1) == 0 and nei == 3) or
                    ((board[i][j] & 1) and (nei == 2 or nei == 3));
        board[i][j] |= (value << 16);
      }
    }
    for (auto &row : board) {
      for (auto &cell : row) {
        cell >>= 16;
      }
    }
  }
};
