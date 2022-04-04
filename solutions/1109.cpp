#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings,
                                      int n) {
    std::vector<int> seats(static_cast<size_t>(n));
    for (const auto& b : bookings) {
      size_t begin = static_cast<size_t>(b[0] - 1);
      const int count = b[2];
      seats[begin] += count;
      if (size_t end = static_cast<size_t>(b[1]); end < seats.size()) {
        seats[end] -= count;
      }
    }
    std::partial_sum(begin(seats), end(seats), begin(seats));
    return seats;
  }
};
