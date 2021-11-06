#include <unordered_set>
#include <vector>

class Solution {
 public:
  int findMaximumXOR(std::vector<int>& nums) {
    int result = 0;
    for (int k = 31; k >= 0; --k) {
      std::unordered_set<int> s;
      for (auto n : nums) {
        s.insert(n >> k);
      }
      result <<= 1;
      int nresult = result + 1;
      for (auto prefix : s) {
        if (s.count(nresult ^ prefix)) {
          result = nresult;
          break;
        }
      }
    }
    return result;
  }
};
