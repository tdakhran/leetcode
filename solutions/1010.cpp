#include <array>
#include <vector>

class Solution {
 public:
  int numPairsDivisibleBy60(std::vector<int>& time) {
    std::array<int, 60> durations = {0};
    for (auto t : time) {
      ++durations[t % 60];
    }
    int result = (durations[0] - 1) * durations[0] / 2 +
                 (durations[30] - 1) * durations[30] / 2;
    for (size_t t = 1; t < 30; ++t) {
      result += durations[t] * durations[60 - t];
    }
    return result;
  }
};
