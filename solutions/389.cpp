#include <array>
#include <string>

class Solution {
 public:
  char findTheDifference(std::string s, std::string t) {
    std::array<int, 26> freq{0};

    for (auto c : s) {
      --freq[static_cast<size_t>(c - 'a')];
    }
    for (auto c : t) {
      if (++freq[static_cast<size_t>(c - 'a')] == 1) {
        return c;
      }
    }
    return 0;
  }
};
