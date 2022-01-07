class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) {
      return 1;
    }
    int zeros = __builtin_clz(static_cast<unsigned>(N));
    int mask = (1 << (32 - zeros)) - 1;
    return ~N & mask;
  }
};
