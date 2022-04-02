#include <optional>
#include <string>

class Solution {
 public:
  bool validPalindrome(std::string s) {
    auto borders = [&s](size_t lo,
                        size_t hi) -> std::optional<std::pair<size_t, size_t>> {
      while (lo < hi) {
        if (s[lo++] != s[--hi]) {
          return std::pair{lo - 1, hi + 1};
        }
      }
      return std::nullopt;
    };

    if (auto res = borders(0, s.size()); res) {
      return !borders(res->first + 1, res->second) or
             !borders(res->first, res->second - 1);
    }

    return true;
  }
};
