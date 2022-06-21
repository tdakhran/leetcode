#include <queue>
#include <vector>

class Solution {
 public:
  size_t furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    while (ladders--) {
      pq.push(0);
    }
    for (size_t pos = 1; pos < heights.size(); ++pos) {
      int delta = std::max(heights[pos] - heights[pos - 1], 0);

      pq.push(delta);
      delta = pq.top();
      pq.pop();

      if (delta > bricks) {
        return pos - 1;
      }

      bricks -= delta;
    }

    return heights.size() - 1;
  }
};
