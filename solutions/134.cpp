#include <vector>

class Solution {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int start = 0;
    int total = 0;

    for (struct {
           unsigned pos = 0;
           int current = 0;
         } i;
         i.pos < gas.size(); ++i.pos) {
      auto delta = gas[i.pos] - cost[i.pos];
      total += delta;

      if ((i.current += delta) < 0) {
        start = static_cast<int>(i.pos) + 1;
        i.current = 0;
      }
    }
    return total < 0 ? -1 : start;
  }
};
