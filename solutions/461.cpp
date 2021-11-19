class Solution {
 public:
  int hammingDistance(int x, int y) {
    return __builtin_popcount(static_cast<unsigned>(x ^ y));
  }
};
