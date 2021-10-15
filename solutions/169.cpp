#include <vector>

class Solution {
 public:
  int majorityElement(std::vector<int>& nums) {
    int cand = -1;
    int count = 0;
    for (auto n : nums) {
      if (count == 0) {
        cand = n;
        ++count;
      } else if (cand == n) {
        ++count;
      } else {
        --count;
      }
    }
    return cand;
  }
};
