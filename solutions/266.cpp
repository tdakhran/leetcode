#include <bitset>

class Solution {
 public:
  bool canPermutePalindrome(std::string s) {
    std::bitset<26> bits;
    for (auto c : s) {
      bits[static_cast<size_t>(c - 'a')].flip();
    }
    return bits.count() < 2;
  }
};
