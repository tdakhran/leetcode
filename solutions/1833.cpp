#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxIceCream(std::vector<int>& costs, int coins) {
    std::sort(begin(costs), end(costs));
    int bars = 0;
    for (auto it = begin(costs); it != end(costs) and coins >= *it;
         coins -= *it++, ++bars) {
    }
    return bars;
  }
};
