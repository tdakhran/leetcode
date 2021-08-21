bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    while (lo < hi) {
      auto mi = lo + (hi - lo) / 2;
      if (isBadVersion(mi)) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    return lo;
  }
};
