#include <array>
#include <vector>

class Solution {
  std::array<std::array<unsigned, 9>, 9> rows{{{0}}}, cols{{{0}}}, tiles{{{0}}};

  bool solveSudokuRecursive(std::vector<std::vector<char>>& board,
                            size_t cell_index) {
    // all cells are filled, return true
    if (cell_index == 81) {
      return true;
    }

    size_t row = cell_index / 9;
    size_t col = cell_index % 9;

    // skip cell if number already there
    if (board[row][col] != '.') {
      return solveSudokuRecursive(board, cell_index + 1);
    }

    size_t tile_id = ((row / 3) * 3) + (col / 3);

    for (size_t value = 0; value < 9; ++value) {
      // check if value is not valid for this cell
      if (rows[row][value] || cols[col][value] || tiles[tile_id][value]) {
        continue;
      }

      // update state
      ++rows[row][value];
      ++cols[col][value];
      ++tiles[tile_id][value];
      board[row][col] = static_cast<char>(value + '0' + 1);

      // dive deeper into recursion
      if (solveSudokuRecursive(board, cell_index + 1)) {
        return true;
      }

      // restore state
      --rows[row][value];
      --cols[col][value];
      --tiles[tile_id][value];
      board[row][col] = '.';
    }

    return false;
  }

 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    // fill in state on initial call
    for (size_t row = 0; row < board.size(); row++) {
      for (size_t col = 0; col < board[row].size(); col++) {
        if (board[row][col] != '.') {
          size_t tile_id = ((row / 3) * 3) + (col / 3);
          auto value = static_cast<unsigned>(board[row][col] - '0' - 1);
          ++rows[row][value];
          ++cols[col][value];
          ++tiles[tile_id][value];
        }
      }
    }

    solveSudokuRecursive(board, 0);
  }
};
