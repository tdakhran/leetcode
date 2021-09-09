#include <array>

class Solution {
 public:
  int firstUniqChar(std::string s) {
    std::array<size_t, 26> freq{0};
    for (auto c : s) {
      ++freq[static_cast<size_t>(c - 'a')];
    }
    for (size_t i = 0; i < s.size(); ++i) {
      if (freq[static_cast<size_t>(s[i] - 'a')] == 1) {
        return static_cast<int>(i);
      }
    }
    return -1;
  }
};
