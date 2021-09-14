#include <string>

class Solution {
 public:
  std::string reverseOnlyLetters(std::string s) {
    size_t lo = 0;
    size_t hi = s.size() - 1;
    while (lo < hi) {
      while (lo < hi and !isalpha(s[lo])) {
        ++lo;
      }
      while (lo < hi and !isalpha(s[hi])) {
        --hi;
      }
      std::swap(s[lo++], s[hi--]);
    }
    return s;
  }
};
