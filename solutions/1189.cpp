#include <array>
#include <string>

class Solution {
 public:
  int maxNumberOfBalloons(std::string text) {
    const auto target = std::string("balloon");
    std::array<int, 128> freq{0};
    for (auto c : text) {
      ++freq[static_cast<size_t>(c)];
    }
    for (int count = 0;; ++count) {
      for (auto c : target) {
        if (--freq[static_cast<size_t>(c)] < 0) {
          return count;
        }
      }
    }
  }
};
