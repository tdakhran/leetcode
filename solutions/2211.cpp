#include <algorithm>
#include <string>

class Solution {
 public:
  int countCollisions(std::string dirs) {
    auto lo = begin(dirs);
    auto hi = end(dirs);

    while (lo <= hi and *lo == 'L') {
      ++lo;
    }
    while (lo <= hi and *prev(hi) == 'R') {
      --hi;
    }
    return static_cast<int>(
        std::count_if(lo, hi, [](char c) { return c != 'S'; }));
  }
};
