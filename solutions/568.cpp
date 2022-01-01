#include <limits>
#include <vector>

class Solution {
 public:
  int maxVacationDays(std::vector<std::vector<int>>& flights,
                      std::vector<std::vector<int>>& days) {
    int result = 0;
    std::vector<std::pair<int, size_t>> current(
        flights.size(), {-1, std::numeric_limits<size_t>::max()});
    auto next = current;
    current.front() = {0, 0};

    for (size_t week = 0; week < days.front().size(); ++week) {
      for (size_t ccity = 0; ccity < flights.size(); ++ccity) {
        if (current[ccity].second != week) {
          continue;
        }
        for (size_t city = 0; city < flights.size(); ++city) {
          if (not flights[ccity][city] and ccity != city) {
            continue;
          }
          next[city].second = week + 1;
          next[city].first = std::max(current[ccity].first + days[city][week],
                                      next[city].first);
          result = std::max(result, next[city].first);
        }
      }
      swap(current, next);
    }

    return result;
  }
};
