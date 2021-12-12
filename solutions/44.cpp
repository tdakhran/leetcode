#include <optional>
#include <string>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    auto is = begin(s);
    auto ip = begin(p);
    std::optional<std::string::iterator> star, saved_is;

    while (is != end(s)) {
      if (ip != end(p) and (*is == *ip or *ip == '?')) {
        ++ip;
        ++is;
      } else if (ip != end(p) and *ip == '*') {
        star = ip;
        saved_is = is;
        ++ip;
      } else if (!star) {
        return false;
      } else {
        ip = next(*star);
        saved_is = is = next(*saved_is);
      }
    }

    for (; ip != end(p); ++ip) {
      if (*ip != '*') {
        return false;
      }
    }
    return true;
  }
};
