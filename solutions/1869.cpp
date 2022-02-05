#include <array>
#include <cassert>
#include <string>

class Solution {
 public:
  bool checkZeroOnes(std::string s) {
    std::array<int, 2> count{0};
    std::array<int, 2> max_count{0};

    for (auto c : s) {
      assert(c == '0' or c == '1');
      size_t idx = static_cast<size_t>(c - '0');
      for (size_t pos = 0; pos < 2; ++pos) {
        count[pos] = (idx == pos) * (count[pos] + 1);
        max_count[pos] = std::max(max_count[pos], count[pos]);
      }
    }
    return max_count[0] < max_count[1];
  }
};
