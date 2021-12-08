#include <array>
#include <string>

class Solution {
 public:
  int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    std::array<int, 128> freq{0};
    size_t start = 0;
    int count = 0;
    size_t result = 0;
    for (size_t pos = 0; pos < s.size(); ++pos) {
      count += (++freq[static_cast<size_t>(s[pos])] == 1);
      while (count > k) {
        count -= (--freq[static_cast<size_t>(s[start++])] == 0);
      }
      result = std::max(result, pos - start + 1);
    }
    return static_cast<int>(result);
  }
};
