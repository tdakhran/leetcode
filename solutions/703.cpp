#include <queue>
#include <vector>

class KthLargest {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  int capacity_;

 public:
  KthLargest(int k, std::vector<int>& nums) {
    capacity_ = k;
    for (auto n : nums) {
      add(n);
    }
  }

  int add(int val) {
    pq.push(val);
    if (pq.size() > static_cast<size_t>(capacity_)) {
      pq.pop();
    }
    return pq.top();
  }
};
