#include <unordered_set>

class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    if (K % 2 == 0) {
      return -1;
    }
    int digits = 1;
    int number = 1;
    std::unordered_set<int> cache{1};

    while (number % K) {
      ++digits;
      number = ((number * 10 + 1) % K);
      if (not cache.insert(number).second) {
        return -1;
      }
    }

    return digits;
  }
};
