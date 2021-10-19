#include <unordered_map>
#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    int acc = 0;
    int result = 0;
    std::unordered_map<int, int> prefix{{0, 1}};

    for (auto n : nums) {
      if (auto it = prefix.find(acc + n - k); it != end(prefix)) {
        result += it->second;
      }
      ++prefix[acc += n];
    }
    return result;
  }
};
