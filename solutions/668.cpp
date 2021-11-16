#include <algorithm>

class Solution {
  int count(int m, int n, int t) {
    int result = 0;
    for (int i = 1; i <= m; ++i) {
      result += std::min(t / i, n);
    }
    return result;
  }

 public:
  int findKthNumber(int m, int n, int k) {
    int lo = 1;
    int hi = m * n;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      if (count(m, n, mi) < k) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }
    return lo;
  }
};
