#include <complex>

class Solution {
  std::string to_string(const std::complex<int> &num) {
    return std::to_string(num.real()) + std::string(1, '+') +
           std::to_string(num.imag()) + std::string(1, 'i');
  }
  std::complex<int> complexFromString(const std::string &s) {
    std::stringstream ss(s);
    char sign;
    int real, imag;
    ss >> real >> sign >> imag;
    return {real, imag};
  }

 public:
  std::string complexNumberMultiply(std::string num1, std::string num2) {
    return to_string(complexFromString(num1) * complexFromString(num2));
  }
};
