#include <string>

class Solution {
 public:
  std::string convert(std::string s, size_t n) {
    std::string result;

    for (size_t row = 0; row < n; ++row) {
      size_t du = row == 0 ? 0 : (2 * row - 1);
      size_t dd = row + 1 == n ? 0 : (2 * (n - row) - 3);
      du = du ? du : dd;
      dd = dd ? dd : du;
      for (size_t i = 0, p = row; p < s.size(); ++i, ++p) {
        result.push_back(s[p]);
        p += (i % 2 ? du : dd);
      }
    }
    return result;
  }
};
