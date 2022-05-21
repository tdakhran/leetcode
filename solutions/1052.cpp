#include <vector>

class Solution {
 public:
  int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy,
                   size_t minutes) {
    int gain = 0;
    int total = 0;
    int max_gain = 0;

    for (size_t time = 0; time < customers.size(); ++time) {
      if (not grumpy[time]) {
        total += customers[time];
      } else {
        gain += customers[time];
      }
      if (auto prev_time = time - minutes;
          time >= minutes and grumpy[prev_time]) {
        gain -= customers[prev_time];
      }
      max_gain = std::max(gain, max_gain);
    }
    return total + max_gain;
  }
};
