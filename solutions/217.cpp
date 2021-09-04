#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> s;
    for (auto n : nums) {
      if (!s.insert(n).second) {
        return true;
      }
    }
    return false;
  }
};
