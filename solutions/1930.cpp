#include <bitset>
#include <string>

class Solution {
 public:
  int countPalindromicSubsequence(std::string s) {
    int count = 0;
    for (auto c = 'a'; c <= 'z'; ++c) {
      size_t lo = 0;
      size_t hi = s.size() - 1;
      while (lo < hi and s[lo] != c) {
        ++lo;
      }
      while (lo < hi and s[hi] != c) {
        --hi;
      }
      std::bitset<32> b(0);
      for (auto p = lo + 1; p < hi; ++p) {
        b.set(static_cast<size_t>(s[p] - 'a'));
      }
      count += b.count();
    }
    return count;
  }
};
