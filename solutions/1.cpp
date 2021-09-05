#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    for (size_t i = 0; i < nums.size(); ++i) {
      auto required = target - nums[i];
      if (auto it = seen.find(required); it != end(seen)) {
        return {it->second, static_cast<int>(i)};
      }
      seen.insert({nums[i], i});
    }
    return {-1, -1};
  }
};
