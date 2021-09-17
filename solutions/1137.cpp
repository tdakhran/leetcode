#include <array>
#include <numeric>

class Solution {
 public:
  int tribonacci(int n) {
    if (n < 2) {
      return n;
    }
    std::array<int, 3> f = {1, 1, 0};

    while (--n > 1) {
      auto f_n_3 = std::accumulate(begin(f), end(f), 0);
      f[2] = f[1];
      f[1] = f[0];
      f[0] = f_n_3;
    }
    return f[0];
  }
};
