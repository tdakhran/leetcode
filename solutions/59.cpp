#include <array>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(size_t n) {
    auto result = std::vector<std::vector<int>>(n, std::vector<int>(n));
    constexpr std::array<std::pair<size_t, size_t>, 4> directions{
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int current_value = 0;

    for (size_t layer = 0; layer < (n + 1) / 2; ++layer) {
      size_t row = layer;
      size_t col = layer;
      size_t direction_index = 0;
      size_t side = n - layer * 2;
      size_t count = side < 2 ? side : (2 * side + 2 * (side - 2));
      for (size_t k = 0; k < count; ++k) {
        result[row][col] = ++current_value;
        row += directions[direction_index].first;
        col += directions[direction_index].second;
        if (row < layer or row + layer >= n or col < layer or
            col + layer >= n) {
          row -= directions[direction_index].first;
          col -= directions[direction_index].second;
          direction_index = (direction_index + 1) % 4;
          row += directions[direction_index].first;
          col += directions[direction_index].second;
        }
      }
    }
    return result;
  }
};
