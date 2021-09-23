#include <vector>

class Solution {
 public:
  int maxScoreSightseeingPair(std::vector<int>& values) {
    int prev_max = values.front();
    int result = 0;
    for (auto i = 1u; i < values.size(); ++i) {
      result = std::max(result, values[i] - static_cast<int>(i) + prev_max);
      prev_max = std::max(prev_max, values[i] + static_cast<int>(i));
    }
    return result;
  }
};
