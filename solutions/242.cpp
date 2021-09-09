#include <array>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    std::array<size_t, 26> freq_s{0}, freq_t{0};
    for (auto c : s) {
      ++freq_s[static_cast<size_t>(c - 'a')];
    }
    for (auto c : t) {
      ++freq_t[static_cast<size_t>(c - 'a')];
    }
    return freq_s == freq_t;
  }
};
