#include <string>
#include <vector>

class Solution {
 public:
  int minFlipsMonoIncr(std::string s) {
    std::vector<size_t> zeros{0};
    for (auto c : s) zeros.push_back(zeros.back() + (c == '1'));

    size_t result = zeros.back();
    for (size_t p = s.size(), ones = 0; p > 0; --p) {
      ones += s[p - 1] == '0';
      result = std::min(result, ones + zeros[p - 1]);
    }
    return static_cast<int>(result);
  }
};
