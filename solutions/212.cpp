#include <array>
#include <functional>
#include <vector>

class Solution {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
  struct TrieNode {
    std::array<TrieNode *, 26> ch{nullptr};
    bool word = false;
  };
#pragma clang diagnostic pop

 public:
  std::vector<std::string> findWords(std::vector<std::vector<char>> &board,
                                     std::vector<std::string> &words) {
    TrieNode root;
    for (const auto &word : words) {
      auto it = &root;
      for (char c : word) {
        auto &ch = it->ch[static_cast<size_t>(c - 'a')];
        if (!ch) {
          ch = new TrieNode();
        }
        it = ch;
      }
      it->word = true;
    }

    std::vector<std::string> result;
    std::string current;

    std::function<void(TrieNode *, size_t, size_t)> dfs =
        [&dfs, &board, &result, &current](TrieNode *it, size_t row,
                                          size_t col) {
          if (!it or !board[row][col]) {
            return;
          }

          if (auto ch = it->ch[static_cast<size_t>(board[row][col] - 'a')];
              ch) {
            current.push_back(board[row][col]);

            if (ch->word) {
              result.push_back(current);
              ch->word = false;
            }
            board[row][col] = 0;

            if (row + 1 < board.size()) {
              dfs(ch, row + 1, col);
            }
            if (row) {
              dfs(ch, row - 1, col);
            }
            if (col + 1 < board.front().size()) {
              dfs(ch, row, col + 1);
            }
            if (col) {
              dfs(ch, row, col - 1);
            }

            board[row][col] = current.back();
            current.pop_back();
          }
        };

    for (size_t row = 0; row < board.size(); ++row) {
      for (size_t col = 0; col < board.front().size(); ++col) {
        dfs(&root, row, col);
      }
    }

    return result;
  }
};
