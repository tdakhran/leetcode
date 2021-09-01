class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 3) {
      return n;
    }
    int prelast = 1, last = 2;
    for (int i = 3; i <= n; ++i) {
      int cur = prelast + last;
      prelast = last;
      last = cur;
    }
    return last;
  }
};
