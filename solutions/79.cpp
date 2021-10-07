#include <array>
#include <functional>
#include <utility>
#include <vector>

class Solution {
  static inline constexpr std::array<std::pair<size_t, size_t>, 4> directions{
      {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    std::function<bool(size_t, size_t, size_t)> dfs =
        [&dfs, &board, &word](size_t row, size_t col, size_t pos) -> bool {
      if (pos == word.size()) {
        return true;
      }
      if (row >= board.size() or col >= board.front().size()) {
        return false;
      }
      if (board[row][col] != word[pos]) {
        return false;
      }

      board[row][col] = 0;

      for (const auto& [drow, dcol] : directions) {
        if (dfs(row + drow, col + dcol, pos + 1)) {
          return true;
        }
      }
      board[row][col] = word[pos];
      return false;
    };

    for (size_t row = 0; row < board.size(); ++row) {
      for (size_t col = 0; col < board.front().size(); ++col) {
        if (dfs(row, col, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
