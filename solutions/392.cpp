#include <string>

class Solution {
 public:
  bool isSubsequence(std::string s, std::string t) {
    auto is = begin(s);
    for (auto it = begin(t); is < end(s); ++is, ++it) {
      while (it < end(t) and *it != *is) {
        ++it;
      }
      if (it == end(t)) {
        return false;
      }
    }
    return is == end(s);
  }
};
