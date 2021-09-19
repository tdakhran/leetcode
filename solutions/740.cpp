#include <map>
#include <vector>

class Solution {
 public:
  int deleteAndEarn(std::vector<int>& nums) {
    std::map<int, int> buckets;
    for (auto n : nums) {
      ++buckets[n];
    }

    int prev = -2;
    int pick = 0, skip = 0;
    for (const auto& [value, count] : buckets) {
      int new_pick =
          (value == prev + 1 ? skip : std::max(skip, pick)) + value * count;
      skip = std::max(skip, pick);
      pick = new_pick;
      prev = value;
    }
    return std::max(pick, skip);
  }
};
