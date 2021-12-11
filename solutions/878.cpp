#include <algorithm>
#include <numeric>

class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    constexpr int64_t modulo = 1'000'000'007;
    const int64_t l = std::lcm(a, b);

    auto count = [a, b, l](int64_t num) { return num / a + num / b - num / l; };

    int64_t lo = 0;
    int64_t hi = static_cast<int64_t>(n) * std::min(a, b);

    while (lo < hi) {
      auto mi = lo + (hi - lo) / 2;
      if (count(mi) < n) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return static_cast<int>(lo % modulo);
  }
};
