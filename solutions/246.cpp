#include <array>

class Solution {
 public:
  bool isStrobogrammatic(std::string num) {
    constexpr std::array<char, 10> match{
        {'0', '1', ' ', ' ', ' ', ' ', '9', ' ', '8', '6'}};
    for (size_t lo = 0, hi = num.size(); lo < hi; ++lo, --hi) {
      if (match[static_cast<size_t>(num[lo] - '0')] != num[hi - 1]) {
        return false;
      }
    }
    return true;
  }
};
