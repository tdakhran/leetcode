#include <algorithm>
#include <string>

class Solution {
 public:
  bool detectCapitalUse(std::string word) {
    auto upper = [](char c) { return std::isupper(c); };
    return std::all_of(begin(word), end(word), upper) or
           std::none_of(next(begin(word)), end(word), upper);
  }
};
