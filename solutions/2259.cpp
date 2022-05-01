#include <string>

class Solution {
 public:
  std::string removeDigit(std::string number, char digit) {
    auto remove = [&number](size_t pos) {
      return number.substr(0, pos) + number.substr(pos + 1);
    };
    size_t last_pos = 0;
    for (size_t pos = 0; pos < number.size(); ++pos) {
      if (pos + 1 < number.size() and number[pos] == digit and
          number[pos + 1] > digit) {
        return remove(pos);
      } else if (number[pos] == digit) {
        last_pos = pos;
      }
    }
    return remove(last_pos);
  }
};
