#include <numeric>
#include <string>

class Solution {
 public:
  int titleToNumber(std::string columnTitle) {
    return std::accumulate(
        begin(columnTitle), end(columnTitle), 0,
        [](int acc, char c) { return acc * 26 + (c - 'A' + 1); });
  }
};
