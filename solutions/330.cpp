#include <cstdint>
#include <vector>

class Solution {
 public:
  int minPatches(std::vector<int>& nums, int n) {
    int patches = 0;
    int64_t counter = 1;

    for (size_t i = 0; counter <= n and i < nums.size();) {
      if (nums[i] <= counter) {
        counter += nums[i++];
      } else {
        counter *= 2;
        ++patches;
      }
    }
    while (counter <= n) {
      counter *= 2;
      ++patches;
    }
    return patches;
  }
};
