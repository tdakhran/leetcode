#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addStrings(std::string num1, std::string num2) {
    std::string result;
    int carry = 0;
    auto i = num1.crbegin();
    auto j = num2.crbegin();
    while (i != num1.crend() or j != num2.crend() or carry) {
      if (i != num1.crend()) {
        carry += *i++ - '0';
      }
      if (j != num2.crend()) {
        carry += *j++ - '0';
      }
      result.push_back('0' + (carry % 10));
      carry /= 10;
    }
    if (carry) {
      result.push_back('1');
    }
    if (result.empty()) {
      result.push_back('0');
    }
    std::reverse(begin(result), end(result));

    return result;
  }
};
