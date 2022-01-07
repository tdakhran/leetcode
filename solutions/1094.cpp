#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
    std::sort(begin(trips), end(trips),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                if (a[1] < b[1]) {
                  return true;
                }
                if (a[1] == b[1]) {
                  return a[2] < b[2];
                }
                return false;
              });
    int cur = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        drops;

    for (const auto &t : trips) {
      int pass = t[0];
      int start = t[1];
      int end = t[2];
      while (drops.size() and drops.top().first <= start) {
        cur -= drops.top().second;
        drops.pop();
      }
      drops.push({end, pass});
      cur += pass;
      if (cur > capacity) {
        return false;
      }
    }
    return true;
  }
};
