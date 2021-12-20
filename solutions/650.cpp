class Solution {
 public:
  int minSteps(int n) {
    for (int d = 2; 2 * d <= n; ++d) {
      if (n % d == 0) {
        return d + minSteps(n / d);
      }
    }
    return n == 1 ? 0 : n;
  }
};
