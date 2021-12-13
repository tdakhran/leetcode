#include <algorithm>
#include <vector>

class Solution {
 public:
  int findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(begin(pairs), end(pairs),
              [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int ending = std::numeric_limits<int>::min(), count = 0;
    for (const auto& pair : pairs) {
      if (ending < pair[0]) {
        ending = pair[1];
        ++count;
      }
    }
    return count;
  }
};
