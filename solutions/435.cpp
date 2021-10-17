#include <algorithm>
#include <vector>

class Solution {
 public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty()) {
      return 0;
    }
    std::sort(begin(intervals), end(intervals),
              [](const auto &a, const auto &b) { return (a[1] < b[1]); });
    int count = 0;
    int last_value = std::numeric_limits<int>::min();

    for (const auto &i : intervals) {
      (i[0] < last_value) ? ++count : last_value = i[1];
    }
    return count;
  }
};
