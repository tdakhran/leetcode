#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>> &intervals) {
    std::sort(begin(intervals), end(intervals),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return (a[0] < b[0]) or (a[0] == b[0] and a[1] < b[1]);
              });

    std::vector<std::vector<int>> result;
    for (auto &i : intervals) {
      if (result.empty()) {
        result.emplace_back(std::move(i));
      } else if (result.back()[1] < i[0]) {
        result.emplace_back(std::move(i));
      } else {
        result.back()[1] = std::max(result.back()[1], i[1]);
      }
    }
    return result;
  }
};
