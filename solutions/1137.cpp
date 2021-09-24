#include <algorithm>
#include <array>
#include <numeric>

class Solution {
 public:
  int tribonacci(int n) {
    if (n < 2) {
      return n;
    }
    std::array<int, 4> f = {1, 1, 0};

    while (--n > 1) {
      f.back() = std::accumulate(begin(f), std::prev(end(f)), 0);
      std::rotate(f.rbegin(), f.rbegin() + 1, f.rend());
    }
    return f.front();
  }
};
