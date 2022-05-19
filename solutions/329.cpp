#include <functional>
#include <vector>

class Solution {
 public:
  int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
    auto dp = std::vector<std::vector<int>>(
        matrix.size(), std::vector<int>(matrix.front().size(), -1));

    std::function<int(size_t, size_t)> dfs = [&](size_t r, size_t c) {
      if (dp[r][c] != -1) {
        return dp[r][c];
      }
      int longest = 0;

      if (r and matrix[r - 1][c] > matrix[r][c]) {
        longest = std::max(longest, dfs(r - 1, c));
      }
      if (c and matrix[r][c - 1] > matrix[r][c]) {
        longest = std::max(longest, dfs(r, c - 1));
      }
      if (r + 1 < dp.size() and matrix[r + 1][c] > matrix[r][c]) {
        longest = std::max(longest, dfs(r + 1, c));
      }
      if (c + 1 < dp.front().size() and matrix[r][c + 1] > matrix[r][c]) {
        longest = std::max(longest, dfs(r, c + 1));
      }

      return (dp[r][c] = 1 + longest);
    };

    int longest = 0;
    for (size_t row = 0; row < matrix.size(); ++row) {
      for (size_t col = 0; col < matrix.front().size(); ++col) {
        longest = std::max(longest, dfs(row, col));
      }
    }
    return longest;
  }
};
