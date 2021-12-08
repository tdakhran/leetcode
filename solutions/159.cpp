#include <array>
#include <string>

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::array<int, 128> freq{0};
    size_t start = 0;
    size_t count = 0;
    size_t result = 0;
    for (size_t pos = 0; pos < s.size(); ++pos) {
      count += (++freq[static_cast<size_t>(s[pos])] == 1);
      while (count > 2) {
        count -= (--freq[static_cast<size_t>(s[start++])] == 0);
      }
      result = std::max(result, pos - start + 1);
    }
    return static_cast<int>(result);
  }
};
