#include <array>

class Solution {
 public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::array<size_t, 26> freq{0};
    for (auto c : magazine) {
      ++freq[static_cast<size_t>(c - 'a')];
    }

    for (auto c : ransomNote) {
      if (!freq[static_cast<size_t>(c - 'a')]--) {
        return false;
      }
    }
    return true;
  }
};
