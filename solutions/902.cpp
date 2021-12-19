#include <cmath>
#include <string>
#include <vector>

class Solution {
 public:
  int atMostNGivenDigitSet(std::vector<std::string>& digits, int n) {
    std::string n_str = std::to_string(n);
    unsigned n_size = static_cast<unsigned>(n_str.size());
    unsigned dsize = static_cast<unsigned>(digits.size());
    int result = 0;

    for (size_t i = 1; i < n_size; ++i) {
      result += static_cast<int>(std::pow(dsize, i));
    }

    for (unsigned i = 0; i < n_size; ++i) {
      bool hasSameNum = false;
      for (auto d : digits) {
        if (d[0] < n_str[i]) {
          result += static_cast<int>(pow(dsize, n_size - i - 1));
        } else if (d[0] == n_str[i]) {
          hasSameNum = true;
        }
      }
      if (!hasSameNum) {
        return result;
      }
    }
    return result + 1;
  }
};
