#include <string>

class Solution {
 public:
  int maxPower(std::string s) {
    int count = 1;
    int result = 1;

    for (size_t pos = 1; pos < s.size(); ++pos) {
      if (s[pos] == s[pos - 1]) {
        ++count;
      } else {
        count = 1;
      }
      result = std::max(result, count);
    }
    return result;
  }
};
