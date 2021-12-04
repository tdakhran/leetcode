#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxSubArrayLen(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixes;
    int sum = 0;
    prefixes[0] = -1;
    int result = 0;
    for (size_t pos = 0; pos < nums.size(); ++pos) {
      sum += nums[pos];
      if (!prefixes.count(sum)) {
        prefixes[sum] = static_cast<int>(pos);
      }
      auto target = sum - k;
      if (auto it = prefixes.find(target); it != end(prefixes)) {
        result = std::max<int>(result, static_cast<int>(pos) - it->second);
      }
    }
    return result;
  }
};
