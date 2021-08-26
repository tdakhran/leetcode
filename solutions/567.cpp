#include <array>
#include <string>

class Solution {
 public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::array<int, 26> s1freq{0}, s2freq{0};
    for (auto c : s1) {
      ++s1freq[static_cast<size_t>(c - 'a')];
    }
    for (size_t start = 0, pos = 0; pos < s2.size(); ++pos) {
      ++s2freq[static_cast<size_t>(s2[pos] - 'a')];
      if (pos - start + 1 > s1.size()) {
        --s2freq[static_cast<size_t>(s2[start++] - 'a')];
      }
      bool success = true;
      for (size_t i = 0; i < s1freq.size(); ++i) {
        if (s1freq[i] > s2freq[i]) {
          success = false;
          break;
        }
      }
      if (success) {
        return true;
      }
    }
    return false;
  }
};
