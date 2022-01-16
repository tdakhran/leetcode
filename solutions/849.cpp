#include <vector>

class Solution {
 public:
  int maxDistToClosest(std::vector<int>& seats) {
    size_t current_seat = 0;
    while (seats[current_seat] == 0) {
      ++current_seat;
    }

    size_t result = current_seat;
    size_t prev_seat = current_seat;
    while (current_seat < seats.size()) {
      ++current_seat;
      while (current_seat < seats.size() and seats[current_seat] == 0) {
        ++current_seat;
      }
      if (current_seat < seats.size()) {
        size_t dist = current_seat - prev_seat;
        result = std::max(result, dist / 2);
        prev_seat = current_seat;
      }
    }
    return static_cast<int>(std::max(result, seats.size() - prev_seat - 1));
  }
};
