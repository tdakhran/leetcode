int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    int lo = 1;
    int hi = n;
    while (lo < hi) {
      int mi = lo + (hi - lo) / 2;
      auto answer = guess(mi);

      if (answer == 0) {
        return mi;
      } else if (answer > 0) {
        lo = mi + 1;
      } else {  // answer < 0
        hi = mi - 1;
      }
    }
    return lo;
  }
};
