#include <string>
#include <vector>

class Solution {
 public:
  int compress(std::vector<char>& chars) {
    auto in = begin(chars);
    char prev = chars.front();

    for (size_t p = 0, count = 0; p <= chars.size(); ++p, ++count) {
      if (char curr = p < chars.size() ? chars[p] : 0; curr != prev) {
        *in++ = prev;
        if (auto str = std::to_string(count); count > 1) {
          in = std::copy(begin(str), end(str), in);
        }
        count = 0;
        prev = curr;
      }
    }

    return static_cast<int>(std::distance(begin(chars), in));
  }
};
