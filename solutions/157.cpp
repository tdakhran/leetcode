#include <array>

class Solution {
 public:
  int read(char *buf, int n) {
    auto finish = buf + n;
    auto it = buf;
    while (it + 4 <= finish) {
      auto read_bytes = read4(it);
      it += read_bytes;
      if (read_bytes < 4) {
        return static_cast<int>(it - buf);
      }
    }

    std::array<char, 4> tmp;
    auto read_bytes =
        std::min(read4(tmp.data()), static_cast<int>(buf + n - it));
    std::copy(begin(tmp), std::next(begin(tmp), read_bytes), it);
    return static_cast<int>(it + read_bytes - buf);
  }
};
