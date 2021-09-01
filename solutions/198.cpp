#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int last = 0;
    int prelast = 0;
    for (auto n : nums) {
      int new_prelast = std::max(last, prelast);
      int new_last = n + prelast;
      prelast = new_prelast;
      last = new_last;
    }
    return std::max(prelast, last);
  }
};
