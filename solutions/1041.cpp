#include <array>
#include <string>

class Solution {
 public:
  bool isRobotBounded(std::string instructions) {
    using Position = std::pair<int, int>;
    Position position = {0, 0};

    std::array<std::pair<int, int>, 4> directions = {
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    size_t direction = 0;

    for (auto i : instructions) {
      if (i == 'L') {
        direction = (direction + 4 - 1) % 4;
      } else if (i == 'R') {
        direction = (direction + 4 + 1) % 4;
      } else {
        position.first += directions[direction].first;
        position.second += directions[direction].second;
      }
    }

    return (position == Position{0, 0}) or direction;
  }
};
