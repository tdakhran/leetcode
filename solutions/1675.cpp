#include <limits>
#include <queue>
#include <vector>

class Solution {
 public:
  int minimumDeviation(std::vector<int>& nums) {
    int max_val = std::numeric_limits<int>::min();
    int min_val = std::numeric_limits<int>::max();
    std::priority_queue<int> pq;

    for (auto n : nums) {
      n = (n % 2) ? 2 * n : n;
      max_val = std::max(max_val, n);
      min_val = std::min(min_val, n);
      pq.push(n);
    }

    int result = max_val - min_val;

    while ((pq.top() % 2) == 0) {
      max_val = pq.top();
      pq.pop();
      result = std::min(result, max_val - min_val);
      min_val = std::min(min_val, max_val / 2);
      pq.push(max_val / 2);
    }

    return std::min(result, pq.top() - min_val);
  }
};
