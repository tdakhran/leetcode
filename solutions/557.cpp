#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    auto space = begin(s);
    do {
      auto next_space = std::find(space, end(s), ' ');
      std::reverse(space, next_space);
      space = next_space == end(s) ? end(s) : next(next_space);
    } while (space != end(s));

    return s;
  }
};
