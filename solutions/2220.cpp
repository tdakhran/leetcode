class Solution {
 public:
  int minBitFlips(int start, int goal) {
    return __builtin_popcount(static_cast<unsigned>(start ^ goal));
  }
};
