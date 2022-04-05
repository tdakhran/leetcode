#include <algorithm>
#include <vector>

class Solution {
 public:
  void reverseWords(std::vector<char>& s) {
    for (auto it = begin(s), pos = begin(s); it <= end(s); ++it) {
      if (it == end(s) or *it == ' ') {
        std::reverse(pos, it);
        pos = next(it);
      }
    }
    std::reverse(begin(s), end(s));
  }
};
