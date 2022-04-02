#include <bitset>

class Solution {
 public:
  bool canConstruct(std::string s, size_t k) {
    if (k > s.size()) {
      return false;
    }

    std::bitset<128> freq;
    for (auto c : s) {
      freq.flip(static_cast<size_t>(c));
    }
    return freq.count() <= k;
  }
};
