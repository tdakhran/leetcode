#include <functional>
#include <vector>

class Solution {
 public:
  void wallsAndGates(std::vector<std::vector<int>>& rooms) {
    std::function<void(size_t, size_t)> visit = [&visit, &rooms](size_t row,
                                                                 size_t col) {
      auto val = rooms[row][col];
      if (row and rooms[row - 1][col] > val + 1) {
        rooms[row - 1][col] = val + 1;
        visit(row - 1, col);
      }
      if (col and rooms[row][col - 1] > val + 1) {
        rooms[row][col - 1] = val + 1;
        visit(row, col - 1);
      }
      if (row + 1 < rooms.size() and rooms[row + 1][col] > val + 1) {
        rooms[row + 1][col] = val + 1;
        visit(row + 1, col);
      }
      if (col + 1 < rooms.front().size() and rooms[row][col + 1] > val + 1) {
        rooms[row][col + 1] = val + 1;
        visit(row, col + 1);
      }
    };

    for (size_t row = 0; row < rooms.size(); ++row) {
      for (size_t col = 0; col < rooms.front().size(); ++col) {
        if (rooms[row][col] == 0) {
          visit(row, col);
        }
      }
    }
  }
};
