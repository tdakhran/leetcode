#include <queue>
#include <vector>

class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (auto n : nums) {
      pq.push(n);
      if (pq.size() > static_cast<size_t>(k)) {
        pq.pop();
      }
    }

    return pq.top();
  }
};
