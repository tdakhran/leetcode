#include <vector>

class Solution {
 public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    auto can_eat = [&piles, &h](int eat_speed) {
      int hours = 0;
      for (auto p : piles) {
        hours += (p + eat_speed - 1) / eat_speed;
        if (hours > h) {
          return false;
        }
      }
      return true;
    };

    int lo = 1;
    int hi = 1'000'000'001;

    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      can_eat(mi) ? hi = mi : lo = mi + 1;
    }
    return lo;
  }
};
