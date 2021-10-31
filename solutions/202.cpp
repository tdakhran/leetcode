#include <unordered_set>

class Solution {
 public:
  bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n > 1) {
      if (not seen.insert(n).second) {
        return false;
      }
      int sum = 0;
      while (n) {
        int d = n % 10;
        n /= 10;
        sum += d * d;
      }
      n = sum;
    }
    return true;
  }
};
