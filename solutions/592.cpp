#include <numeric>
#include <string>
#include <vector>

struct Fraction {
  int a = 0;
  int b = 1;

  Fraction operator+(const Fraction &other) {
    Fraction res;
    res.a = a * other.b + other.a * b;
    res.b = b * other.b;
    auto gcd = std::gcd(res.a, res.b);
    res.a /= gcd;
    res.b /= gcd;
    return res;
  }

  operator std::string() const {
    return std::to_string(a) + "/" + std::to_string(b);
  }
};

class Solution {
  std::vector<Fraction> parse(const std::string &expr) {
    std::vector<Fraction> result;
    Fraction f;
    int digit = 0;
    int sign = 1;
    for (auto c : expr) {
      switch (c) {
        case '-':
          if (digit) {
            f.b = digit;
            digit = 0;
            result.push_back(f);
          }
          sign = -1;
          break;
        case '+':
          if (digit) {
            f.b = digit;
            digit = 0;
            result.push_back(f);
          }
          sign = 1;
          break;
        case '/':
          f.a = sign * digit;
          digit = 0;
          break;
        default:
          digit = digit * 10 + c - '0';
      }
    }
    f.b = digit;
    result.push_back(f);
    return result;
  }

 public:
  std::string fractionAddition(std::string expression) {
    auto fractions = parse(expression);
    return std::accumulate(begin(fractions), end(fractions), Fraction());
  }
};
