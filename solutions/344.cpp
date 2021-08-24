#include <vector>

class Solution {
 public:
  void reverseString(std::vector<char>& s) {
    size_t lo = 0;
    size_t hi = s.size() - 1;
    while (lo < hi) {
      std::swap(s[lo++], s[hi--]);
    }
  }
};
