#include <array>
#include <string>
#include <vector>

class Solution {
 public:
  std::string tictactoe(std::vector<std::vector<int>> &moves) {
    std::array<std::array<int8_t, 3>, 3> grid = {{{0}}};

    auto win = [&grid]() -> bool {
      for (size_t idx = 0; idx < 3; ++idx) {
        if (grid[idx][0] and grid[idx][0] == grid[idx][1] and
            grid[idx][1] == grid[idx][2]) {
          return true;
        }
        if (grid[0][idx] and grid[0][idx] == grid[1][idx] and
            grid[1][idx] == grid[2][idx]) {
          return true;
        }
      }

      return (grid[0][0] and grid[0][0] == grid[1][1] and
              grid[1][1] == grid[2][2]) or
             (grid[0][2] and grid[0][2] == grid[1][1] and
              grid[1][1] == grid[2][0]);
    };

    int8_t player = 'A';
    for (const auto &move : moves) {
      grid[static_cast<size_t>(move[0])][static_cast<size_t>(move[1])] = player;
      if (win()) {
        return std::string(1, player);
      }
      player = (player == 'A') ? 'B' : 'A';
    }

    return moves.size() == 9 ? "Draw" : "Pending";
  }
};
