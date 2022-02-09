#include <unordered_map>
#include <vector>

class Solution {
 public:
  int findPairs(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> seen;

    int result = 0;
    for (auto num : nums) {
      auto count = ++seen[num];
      if (k == 0) {
        result += (count == 2);
        continue;
      }
      if (count > 1) {
        continue;
      }
      for (auto target : {num + k, num - k}) {
        if (auto it = seen.find(target); it != end(seen)) {
          ++result;
        }
      }
    }
    return result;
  }
};
