#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    int sum = accumulate(begin(nums), end(nums), 0);
    int target_sum = sum / 2;
    if (target_sum * 2 != sum) {
      return false;
    }
    std::unordered_set<int> current{0}, next;
    for (auto n : nums) {
      next = {n};
      for (auto e : current) {
        next.insert(e);
        if (n + e == target_sum) {
          return true;
        }
        if (n + e < target_sum) {
          next.insert(n + e);
        }
      }
      swap(current, next);
    }
    return false;
  }
};
