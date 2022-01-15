#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::string result;

    int carry = 0;
    auto ia = a.rbegin();
    auto ib = b.rbegin();
    while (ia != a.rend() or ib != b.rend() or carry) {
      if (ia != a.rend()) {
        carry += *ia++ == '1';
      }
      if (ib != b.rend()) {
        carry += *ib++ == '1';
      }
      result.push_back('0' + (carry & 1));
      carry >>= 1;
    }

    std::reverse(begin(result), end(result));
    return result;
  }
};
