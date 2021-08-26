#include <array>
#include <string>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::array<int, 128> count{0};
    int result = 0;
    for (size_t start = 0, pos = 0; pos < s.size(); ++pos) {
      auto &value = ++count[static_cast<size_t>(s[pos])];
      while (value > 1) {
        --count[static_cast<size_t>(s[start++])];
      }
      result = std::max(result, static_cast<int>(pos - start + 1));
    }
    return result;
  }
};
