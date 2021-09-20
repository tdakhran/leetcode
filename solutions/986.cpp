#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> result;
    auto i2 = begin(secondList);
    for (auto i1 = begin(firstList);
         i1 != end(firstList) and i2 != end(secondList); ++i1) {
      while (i2 != end(secondList) and (*i2)[1] < (*i1)[0]) {
        ++i2;
      }
      while (i2 != end(secondList) and (*i2)[1] <= (*i1)[1]) {
        result.push_back({std::max((*i1)[0], (*i2)[0]), (*i2)[1]});

        ++i2;
      }
      if (i2 != end(secondList)) {
        int start = std::max((*i1)[0], (*i2)[0]);
        int end = std::min((*i1)[1], (*i2)[1]);
        if (start <= end) {
          result.push_back({start, end});
        }
      }
    }
    return result;
  }
};
