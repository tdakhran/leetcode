#include <vector>

class Solution {
 public:
  int minCostToMoveChips(std::vector<int>& position) {
    int odd = 0, even = 0;
    for (auto p : position) {
      odd += (p & 1);
      even += (1 - (p & 1));
    }
    return std::min(odd, even);
  }
};
