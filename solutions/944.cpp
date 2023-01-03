#include <string>
#include <vector>

class Solution {
 public:
  int minDeletionSize(std::vector<std::string>& strs) {
    int cols = 0;
    for (size_t col = 0; col < strs.front().size(); ++col) {
      bool invalid = false;
      for (size_t row = 1; row < strs.size(); ++row) {
        if (strs[row - 1][col] > strs[row][col]) {
          invalid = true;
          break;
        }
      }
      cols += invalid;
    }
    return cols;
  }
};
