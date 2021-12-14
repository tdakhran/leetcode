#include <string>

class Solution {
 public:
  int countSubstrings(std::string s) {
    int count = 0;
    for (size_t pos = 0; pos < s.size(); ++pos) {
      size_t left = pos + 1, right = pos;
      while (left > 0 and right < s.size() and s[left - 1] == s[right]) {
        ++count;
        --left;
        ++right;
      }
      left = pos + 1;
      right = pos + 1;
      while (left > 0 and right < s.size() and s[left - 1] == s[right]) {
        ++count;
        --left;
        ++right;
      }
    }
    return count;
  }
};
