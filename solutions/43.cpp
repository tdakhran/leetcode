#include <string>

class Solution {
 public:
  std::string multiply(std::string num1, std::string num2) {
    std::string sum(num1.size() + num2.size(), '0');

    for (size_t i1 = num1.size(); i1 > 0; --i1) {
      int carry = 0;
      for (size_t i2 = num2.size(); i2 > 0; --i2) {
        carry += (sum[i1 + i2 - 1] - '0') +
                 (num1[i1 - 1] - '0') * (num2[i2 - 1] - '0');
        sum[i1 + i2 - 1] = carry % 10 + '0';
        carry /= 10;
      }
      sum[i1 - 1] += carry;
    }

    if (size_t startpos = sum.find_first_not_of("0");
        startpos != std::string::npos) {
      return sum.substr(startpos);
    }
    return "0";
  }
};
