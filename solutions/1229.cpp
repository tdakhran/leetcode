#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> minAvailableDuration(std::vector<std::vector<int>>& slots1,
                                        std::vector<std::vector<int>>& slots2,
                                        int duration) {
    std::sort(begin(slots1), end(slots1));
    std::sort(begin(slots2), end(slots2));

    for (auto it1 = begin(slots1), it2 = begin(slots2);
         it1 != end(slots1) and it2 != end(slots2);) {
      auto start = std::max((*it1)[0], (*it2)[0]);
      auto end = std::min((*it1)[1], (*it2)[1]);

      if (end - start >= duration) {
        return {start, start + duration};
      }

      (*it1)[1] < (*it2)[1] ? ++it1 : ++it2;
    }
    return {};
  }
};
