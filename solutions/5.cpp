#include <string>
#include <vector>

class Solution {
  std::string_view longestPalindrome(const std::string_view &s, size_t lo,
                                     size_t hi) {
    while (lo > 0 and hi < s.size() and s[lo - 1] == s[hi]) {
      --lo;
      ++hi;
    }
    return s.substr(lo, hi - lo);
  }

 public:
  std::string longestPalindrome(std::string s) {
    std::string_view sv(s);
    std::string_view result;
    for (size_t i = 0; i < s.size(); ++i) {
      for (auto hi : {0u, 1u}) {
        auto longest = longestPalindrome(sv, i + 1, i + hi);
        if (longest.size() > result.size()) {
          result = longest;
        }
      }
    }
    return std::string(result);
  }
};
