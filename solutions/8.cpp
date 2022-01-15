#include <algorithm>
#include <string>

class Solution {
 public:
  int myAtoi(std::string s) {
    auto i = begin(s);
    int sign = 1;

    while (i != end(s) and *i == ' ') {
      ++i;
    }

    if (i != end(s)) {
      if (*i == '+') {
        ++i;
      } else if (*i == '-') {
        sign = -1;
        ++i;
      }
    }

    int64_t number = 0;
    while (i != end(s) and isdigit(*i) and
           number < std::numeric_limits<int>::max() and
           number > std::numeric_limits<int>::min()) {
      number = 10 * number + *i++ - '0';
    }

    number *= sign;

    return static_cast<int>(std::clamp<int64_t>(
        number, static_cast<int64_t>(std::numeric_limits<int>::min()),
        static_cast<int64_t>(std::numeric_limits<int>::max())));
  }
};
