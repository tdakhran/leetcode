#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> result;

    for (auto i1 = begin(firstList), i2 = begin(secondList);
         i1 < end(firstList) and i2 < end(secondList);) {
      if ((*i1)[1] < (*i2)[0]) {
        ++i1;
      } else if ((*i2)[1] < (*i1)[0]) {
        ++i2;
      } else if ((*i1)[1] < (*i2)[1]) {
        result.push_back({std::max((*i1)[0], (*i2)[0]), (*i1)[1]});
        ++i1;
      } else {
        result.push_back({std::max((*i1)[0], (*i2)[0]), (*i2)[1]});
        ++i2;
      }
    }
    return result;
  }
};
