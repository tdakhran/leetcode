#include <array>
#include <limits>
#include <vector>

class Solution {
 public:
  bool increasingTriplet(std::vector<int>& nums) {
    std::array<int, 2> memo{std::numeric_limits<int>::max(),
                            std::numeric_limits<int>::max()};
    for (auto n : nums) {
      bool inserted = false;
      for (auto& m : memo) {
        if (m >= n) {
          m = n;
          inserted = true;
          break;
        }
      }
      if (!inserted) {
        return true;
      }
    }
    return false;
  }
};
