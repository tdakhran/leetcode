#include <queue>
#include <vector>

class Solution {
 public:
  int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq;
    for (auto s : stones) {
      pq.push(s);
    }
    while (pq.size() > 1) {
      auto s0 = pq.top();
      pq.pop();
      auto s1 = pq.top();
      pq.pop();
      if (auto diff = s0 - s1; diff) {
        pq.push(diff);
      }
    }
    return pq.empty() ? 0 : pq.top();
  }
};
