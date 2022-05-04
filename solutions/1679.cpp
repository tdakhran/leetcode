#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxOperations(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prev;
    int ops = 0;

    for (auto n : nums) {
      if (auto it = prev.find(k - n); it != end(prev) && it->second) {
        --it->second;
        ++ops;
      } else {
        ++prev[n];
      }
    }
    return ops;
  }
};
