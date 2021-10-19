#include <bitset>
#include <numeric>

class Solution {
 public:
  int longestPalindrome(std::string s) {
    std::bitset<128> b;
    return std::accumulate(begin(s), end(s), 0,
                           [&b](int acc, unsigned c) {
                             return acc + ((!b.flip(c).test(c)) << 1u);
                           }) +
           b.any();
  }
};
